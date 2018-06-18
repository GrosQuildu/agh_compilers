#ifndef GO_PARSER_GO2LLVMMYVISITOR_H
#define GO_PARSER_GO2LLVMMYVISITOR_H

#include "antlr4-runtime.h"
#include "Go2LLVMVisitor.h"
#include "Go2LLVMError.h"
#include "Helpers.h"

#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/InstrTypes.h>
#include <llvm/IR/Instructions.h>

using namespace llvm;

namespace go_parser {

    class Go2LLVMMyVisitor : public Go2LLVMVisitor {
    public:

        LLVMContext &context;
        IRBuilder<> &builder;
        Module *module;
        MyBlock *current_block;
        bool is_main_defined;

        Go2LLVMMyVisitor(LLVMContext&, IRBuilder<>&, Module*);

        Go2LLVMError parser_errors;

        // ------------------------------------------------------------------------------
        // Top Level
        /*
         * SourceFile = PackageClause Eos { TopLevelDecl Eos }
         */
        virtual antlrcpp::Any visitSourceFile(Go2LLVMParser::SourceFileContext *ctx);

        virtual antlrcpp::Any visitPackageClause(Go2LLVMParser::PackageClauseContext *ctx);

        /*
         * TopLevelDecl = Declaration | FunctionDecl
         * Return: nullptr
         */
        virtual antlrcpp::Any visitTopLevelDecl(Go2LLVMParser::TopLevelDeclContext *ctx);

        /*
         * Block = "{" StatementList "}"
         * Return: nullptr
         *
         * modifies builder and current_block
         */
        virtual antlrcpp::Any visitBlock(Go2LLVMParser::BlockContext *ctx);

        /*
         * Type = IDENT_TOK
         * Return: nullptr | Type*
         */
        virtual antlrcpp::Any visitType(Go2LLVMParser::TypeContext *ctx);

        /*
         * not used
         */
        virtual antlrcpp::Any visitEos(Go2LLVMParser::EosContext *ctx);


        // ------------------------------------------------------------------------------
        // Statements
        /*
         * StatementList = { Statement EOS }
         * Return: nullptr
         */
        virtual antlrcpp::Any visitStatementList(Go2LLVMParser::StatementListContext *ctx);

        /*
         * Statement = Declaration | SimpleStmt | Block | ReturnStmt | IfStmt
         * Return: nullptr
         */
        virtual antlrcpp::Any visitStatement(Go2LLVMParser::StatementContext *ctx);

        virtual antlrcpp::Any visitIfStmt(Go2LLVMParser::IfStmtContext *ctx);

        /*
         * ReturnStmt = "return" [ExpressionList]
         * Return: nullptr | vector<Value*>
         */
        virtual antlrcpp::Any visitReturnStmt(Go2LLVMParser::ReturnStmtContext *ctx);

        /*
         * SimpleStmt = EmptyStmt | Expression | Assignment
         * Return: nullptr
         */
        virtual antlrcpp::Any visitSimpleStmt(Go2LLVMParser::SimpleStmtContext *ctx);

        /*
         * Assignment = identifierList [add_op | mul_op] '=' expressionList
         * Return: nullptr
         */
        virtual antlrcpp::Any visitAssignment(Go2LLVMParser::AssignmentContext *ctx);

        /*
         * EmptyStmt = ";"
         * Return: nullptr
         */
        virtual antlrcpp::Any visitEmptyStmt(Go2LLVMParser::EmptyStmtContext *ctx);


        // ------------------------------------------------------------------------------
        // Declarations
        /*
         * Declaration = "var" IdentifierList Type ["=" ExpressionList]
         * Return: nullptr | vector<Variable>
         */
        virtual antlrcpp::Any visitDeclaration(Go2LLVMParser::DeclarationContext *ctx);

        /*
         * IdentifierList = ident_tok { "," ident_tok }
         * Return: vector<string> - identifiers
        */
        virtual antlrcpp::Any visitIdentifierList(Go2LLVMParser::IdentifierListContext *ctx);


        // ------------------------------------------------------------------------------
        // Expressions
        /*
         * ExpressionList = Expression { "," Expression }
         * Return: nullptr | vector<Value*>
         */
        virtual antlrcpp::Any visitExpressionList(Go2LLVMParser::ExpressionListContext *ctx);

        /*
         * Expression = UnaryExpr | Expression binary_op_tok Expression
         * Return: nullptr | Value*
         */
        virtual antlrcpp::Any visitExpression(Go2LLVMParser::ExpressionContext *ctx);

        /*
         * UnaryExpr = unary_op_tok UnaryExpr | operand
         * Return: nullptr | Value*
         */
        virtual antlrcpp::Any visitUnaryExpr(Go2LLVMParser::UnaryExprContext *ctx);


        // ------------------------------------------------------------------------------
        // Operands
        /*
         * OperandBasicList = basicLit
         * Return: nullptr | Value*
         */
        virtual antlrcpp::Any visitOperandBasicLit(Go2LLVMParser::OperandBasicLitContext *ctx);

        /*
         * BasicLit = int_tok | float_tok | imag_tok  | string_tok
         * Return: nullptr | Value*
         */
        virtual antlrcpp::Any visitBasicLit(Go2LLVMParser::BasicLitContext *ctx);

        /*
         * OperandIdent = ident_tok
         * Return: nullptr | Value*
         */
        virtual antlrcpp::Any visitOperandIdent(Go2LLVMParser::OperandIdentContext *ctx);

        /*
         * OperandFunc = ident_tok Arguments, this is function call
         * Return: nullptr | Value*
         */
        virtual antlrcpp::Any visitOperandFunc(Go2LLVMParser::OperandFuncContext *ctx);

        /*
         * Arguments '(' [ExpressionList [',']] ')'
         * Return: nullptr | vector<Value*>
         */
        virtual antlrcpp::Any visitArguments(Go2LLVMParser::ArgumentsContext *ctx);

        /*
         * OperandExp = PO expression PC
         * Return: nullptr | Value*
         */
        virtual antlrcpp::Any visitOperandExp(Go2LLVMParser::OperandExpContext *ctx);


        // ------------------------------------------------------------------------------
        // Functions
        /*
         * Function = func_tok ident_tok signature block
         * Return: nullptr | Function*
         */
        virtual antlrcpp::Any visitFunctionDecl(Go2LLVMParser::FunctionDeclContext *ctx);

        /*
         * Signature = parameters [result]
         * Return: nullptr | pair<vector<Variable>, Type*> - arguments and return type
         */
        virtual antlrcpp::Any visitSignature(Go2LLVMParser::SignatureContext *ctx);

        /*
         * Result = parameters | type
         * Return: nullptr | Type* - type
         */
        virtual antlrcpp::Any visitResult(Go2LLVMParser::ResultContext *ctx);

        /*
         * Parameters = '(' [parameterList [',']] ')'
         * Return: nullptr | vector<Variable> - parameters
         */
        virtual antlrcpp::Any visitParameters(Go2LLVMParser::ParametersContext *ctx);


        /*
         * ParameterList = parameterDecl { COMMA parameterDecl }
         * Return: nullptr | vector<Variable> - parameters
         */
        virtual antlrcpp::Any visitParameterList(Go2LLVMParser::ParameterListContext *ctx);

        /*
        * ParameterDecl = identifielList type
        * Return: nullptr | vector<Variable> - parameters
        */
        virtual antlrcpp::Any visitParameterDecl(Go2LLVMParser::ParameterDeclContext *ctx);

    };

}  // namespace go_parser

#endif //GO_PARSER_GO2LLVMMYVISITOR_H
