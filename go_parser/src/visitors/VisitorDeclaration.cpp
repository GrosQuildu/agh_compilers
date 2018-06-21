#include "Go2LLVMMyVisitor.h"

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;
using std::string;
using std::vector;

/*
 * Declaration = "var" IdentifierList Type ["=" ExpressionList]
 * Return: vector<BasicVar*>
 */
Any Go2LLVMMyVisitor::visitDeclaration(Go2LLVMParser::DeclarationContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitDeclaration: " + ctx->getText());

    // get names and check for uniqueness
    vector<string> identifiers = ctx->identifierList()->accept(this);
    if(std::adjacent_find(identifiers.begin(), identifiers.end()) != identifiers.end()) {
        throw Go2LLVMError("variables must be unique");
    }

    // get type
    Type *type = ctx->type()->accept(this);

    // create variables
    vector<BasicVar*> variables;
    for(string identifier : identifiers) {
        variables.push_back(var_factory.Get(identifier, type));
    }

    // check for variables' initialization
    if(ctx->EQ() != nullptr && ctx->expressionList() != nullptr) {
        vector<BasicVar*> expressions = ctx->expressionList()->accept(this);

        if(expressions.size() != identifiers.size())
            throw Go2LLVMError("identifiers list size != expressions list size");

        for(size_t i = 0; i<variables.size(); i++) {
            variables.at(i)->setValue(expressions.at(i)->getValue());
        }
    }

    return variables;
}

/*
 * IdentifierList = ident_tok { "," ident_tok }
 * Return: vector<string> - identifiers
*/
Any Go2LLVMMyVisitor::visitIdentifierList(Go2LLVMParser::IdentifierListContext *ctx) {
    Go2LLVMError::Log("visitIdentifierList: " + ctx->getText());

    vector<string> identifiers;
    for(auto identifier : ctx->IDENT_TOK()) {
        identifiers.push_back(identifier->getText());
    }
    return identifiers;
}

