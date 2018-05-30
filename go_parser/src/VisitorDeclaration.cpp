#include "Go2LLVMMyVisitor.h"

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;
using std::string;
using std::vector;

/*
 * Declaration = "var" IdentifierList Type ["=" ExpressionList]
 * Return: nullptr
 */
Any Go2LLVMMyVisitor::visitDeclaration(Go2LLVMParser::DeclarationContext *ctx) {
    parser_errors.Log("visitDeclaration: " + ctx->getText());

    vector<string> identifiers = ctx->identifierList()->accept(this);
    string type = ctx->type()->accept(this);

    if(ctx->EQ() != nullptr && ctx->expressionList() != nullptr) {
        Any any_v = ctx->expressionList()->accept(this); if(any_v.isNull()) return nullptr;
        vector<Value *> expressions = any_v;

        if(expressions.size() != identifiers.size())
            return parser_errors.AddError(ctx->getStart()->getLine(), "expressions size != identifiers size");

        for(size_t i = 0; i < identifiers.size(); i++) {
            named_values[identifiers.at(i)] = expressions.at(i);
        }
    } else {
        for(size_t i = 0; i < identifiers.size(); i++) {
            named_values[identifiers.at(i)] = ConstantInt::get(*the_context, APInt(32, 0));
        }
    }

    return nullptr;
}

/*
 * IdentifierList = ident_tok { "," ident_tok }
 * Return: vector<string> - identifiers
*/
Any Go2LLVMMyVisitor::visitIdentifierList(Go2LLVMParser::IdentifierListContext *ctx) {
    parser_errors.Log("visitIdentifierList: " + ctx->getText());

    vector<string> identifiers;
    for(auto identifier : ctx->IDENT_TOK()) {
        identifiers.push_back(identifier->getText());
    }
    return identifiers;
}

