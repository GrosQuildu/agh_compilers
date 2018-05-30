#ifndef GO_PARSER_GO2LLVMMYVISITOR_H
#define GO_PARSER_GO2LLVMMYVISITOR_H

#include "antlr4-runtime.h"
#include "Go2LLVMVisitor.h"
#include "Go2LLVMError.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

using namespace llvm;

namespace go_parser {

    class Go2LLVMMyVisitor : public Go2LLVMVisitor {
    public:

        LLVMContext *the_context;
        IRBuilder<> &builder;
        Module *the_module;
        std::map<std::string, Value *> named_values;

        Go2LLVMMyVisitor(LLVMContext&, IRBuilder<>&, Module*);

        Go2LLVMError parser_errors;

        // Top Level
        virtual antlrcpp::Any visitSourceFile(Go2LLVMParser::SourceFileContext *ctx);

        virtual antlrcpp::Any visitPackageClause(Go2LLVMParser::PackageClauseContext *ctx);

        virtual antlrcpp::Any visitTopLevelDecl(Go2LLVMParser::TopLevelDeclContext *ctx);


        virtual antlrcpp::Any visitBlock(Go2LLVMParser::BlockContext *ctx);

        /*
         * Type = IDENT_TOK
         * Return: string - type
         */
        virtual antlrcpp::Any visitType(Go2LLVMParser::TypeContext *ctx);

        virtual antlrcpp::Any visitEos(Go2LLVMParser::EosContext *ctx);


        // Statements
        virtual antlrcpp::Any visitStatementList(Go2LLVMParser::StatementListContext *ctx);

        virtual antlrcpp::Any visitStatement(Go2LLVMParser::StatementContext *ctx);

        virtual antlrcpp::Any visitIfStmt(Go2LLVMParser::IfStmtContext *ctx);

        /*
         * ReturnStmt = "return" [ExpressionList]
         * Return: nullptr | vector<Value*>
         */
        virtual antlrcpp::Any visitReturnStmt(Go2LLVMParser::ReturnStmtContext *ctx);

        /*
         * SimpleStmt = EmptyStmt | Expression | Assignment
         * Return: nullptr | Value*
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
         * Return: nullptr
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
         * Return: nullptr | vector<Value *>
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
         * Return: nullptr | Value*
         */
        virtual antlrcpp::Any visitOperandBasicLit(Go2LLVMParser::OperandBasicLitContext *ctx);

        virtual antlrcpp::Any visitOperandIdent(Go2LLVMParser::OperandIdentContext *ctx);

        virtual antlrcpp::Any visitOperandFunc(Go2LLVMParser::OperandFuncContext *ctx);

        virtual antlrcpp::Any visitOperandExp(Go2LLVMParser::OperandExpContext *ctx);

        virtual antlrcpp::Any visitArguments(Go2LLVMParser::ArgumentsContext *ctx);

        /*
         * BasicLit = int_tok | float_tok | imag_tok  | string_tok
         * Return: nullptr | Value*
         */
        virtual antlrcpp::Any visitBasicLit(Go2LLVMParser::BasicLitContext *ctx);


        // ------------------------------------------------------------------------------
        // Functions
        /*
         * Function = func_tok ident_tok signature block
         * Return: nullptr | Function*
         */
        virtual antlrcpp::Any visitFunctionDecl(Go2LLVMParser::FunctionDeclContext *ctx);

        /*
         * Signature = parameters [result]
         * Return: pair<vector<string>, string> - identifiers (arguments) and return type
         */
        virtual antlrcpp::Any visitSignature(Go2LLVMParser::SignatureContext *ctx);

        /*
         * Result = parameters | type
         * Return: string - type
         */
        virtual antlrcpp::Any visitResult(Go2LLVMParser::ResultContext *ctx);

        /*
         * Parameters = '(' [parameterList [',']] ')'
         * Return: nullptr | vector<string> - identifiers
         */
        virtual antlrcpp::Any visitParameters(Go2LLVMParser::ParametersContext *ctx);

        /*
         * ParameterList = parameterDecl { COMMA parameterDecl }
         * Return: vector<string> - identifiers
         */
        virtual antlrcpp::Any visitParameterList(Go2LLVMParser::ParameterListContext *ctx);

        /*
         * ParameterDecl = identifielList type
         * Return: vector<string> - identifiers
         */
        virtual antlrcpp::Any visitParameterDecl(Go2LLVMParser::ParameterDeclContext *ctx);

    };

}  // namespace go_parser

#endif //GO_PARSER_GO2LLVMMYVISITOR_H
