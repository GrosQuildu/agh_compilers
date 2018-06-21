#include "Go2LLVMMyVisitor.h"

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;
using std::string;
using std::vector;
using std::pair;


/*
 * Function = func_tok ident_tok signature [block]
 * Return: Function*
 */
Any Go2LLVMMyVisitor::visitFunctionDecl(Go2LLVMParser::FunctionDeclContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitFunctionDecl");

    // Function name
    string function_name = ctx->IDENT_TOK()->getText();

    // Function signature - parameters and return types/variables
    pair<pair<vector<BasicVar *>, bool>, Type *> signature = ctx->signature()->accept(this);
    vector<BasicVar *> arguments = signature.first.first;
    bool is_var_arg = signature.first.second;
    Type *return_type = signature.second;

    // Make the function signature
    vector<Type *> arg_types;
    for (auto &variable : arguments)
        arg_types.push_back(variable->getType());
    FunctionType *function_type = FunctionType::get(return_type, arg_types, is_var_arg);

    Function *function = module->getFunction(function_name);
    if (function) {
        // If function exists, check if signature it matches
        if (function->getFunctionType() != function_type) {
            throw Go2LLVMError("Function " + function_name + " redefined with different signature");
        }
    } else {
        // Create function
        function = Function::Create(function_type, Function::ExternalLinkage, function_name, module);
    }

    // Set arg names
    unsigned i = 0;
    for (auto &arg : function->args())
        arg.setName(arguments.at(i++)->name);

    // Return if no function body
    if (ctx->block() == nullptr) {
        return function;
    }

    if (function->getName() != "main") {
        // Make entrypoint block, main function already have entrypoint
        BasicBlock *entrypoint = BasicBlock::Create(context, function->getName() + " entrypoint", function);
        builder.SetInsertPoint(entrypoint);
    } else {
        // Main is defined
        this->is_main_defined = true;
        builder.SetInsertPoint(&function->getEntryBlock());
    }

    // entrypoint block will contain mutable arguments, they should be visible in whole function
    current_block = new MyBlock(current_block);

    // Make store instruction for arguments
    for (auto &arg : function->args()) {
        // Create an alloca for the argument
        AllocaInst *alloca = builder.CreateAlloca(arg.getType(), 0, arg.getName() + ".addr");

        // Store the initial value into the alloca.
        builder.CreateStore(&arg, alloca);

        // Add arguments to variable symbol table.
        current_block->named_values[arg.getName()] = var_factory.Get(arg.getName(), arg.getType(), alloca);
    }

    // Make body
    ctx->block()->accept(this);
    current_block = current_block->previous;

    // Verify
    verifyFunction(*function);

    return function;
}

/*
 * Signature = parameters [result]
 * Return: pair<pair<vector<BasicVar*>, bool>, Type*> - arguments and return type
 */
Any Go2LLVMMyVisitor::visitSignature(Go2LLVMParser::SignatureContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitSignature");

    pair<vector<BasicVar *>, bool> parameters = ctx->parameters()->accept(this);

    Type *result;

    if (ctx->result() != nullptr) {
        result = ctx->result()->accept(this);
    } else {
        result = var_factory.StringToType("void");
    }

    return std::make_pair(parameters, result);
}

/*
 * Result = parameters | type
 * Return: Type*
*/
Any Go2LLVMMyVisitor::visitResult(Go2LLVMParser::ResultContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitResult");

    if (ctx->type() != nullptr) {
        return ctx->type()->accept(this).as<Type *>();
    } else {
        // todo: handle list of params in result
        return var_factory.StringToType("void");
    }
}

/*
 * Parameters = '(' [parameterList [',']] [...] ')'
 * Return: pair<vector<BasicVar*>, bool> - parameters and isVarArg
 */
Any Go2LLVMMyVisitor::visitParameters(Go2LLVMParser::ParametersContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitParameters");

    bool is_var_arg = false;
    if (ctx->vararg_tok != nullptr)
        is_var_arg = true;

    vector<BasicVar *> parameters;
    if (ctx->parameterList() != nullptr) {
        parameters = ctx->parameterList()->accept(this).as<vector<BasicVar *>>();
    }
    return std::make_pair(parameters, is_var_arg);
}

/*
 * ParameterList = parameterDecl { COMMA parameterDecl }
 * Return: vector<BasicVar*> - parameters
 */
Any Go2LLVMMyVisitor::visitParameterList(Go2LLVMParser::ParameterListContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitParameterList");

    vector<BasicVar *> identifiers;
    vector<BasicVar *> identifiers_to_append;

    for (auto parameterDecl : ctx->parameterDecl()) {
        identifiers_to_append.clear();
        identifiers_to_append = parameterDecl->accept(this).as<vector<BasicVar *>>();
        identifiers.insert(identifiers.end(), identifiers_to_append.begin(), identifiers_to_append.end());
    }
    return identifiers;
}

/*
 * ParameterDecl = identifielList type
 * Return: vector<BasicVar*> - parameters
 */
Any Go2LLVMMyVisitor::visitParameterDecl(Go2LLVMParser::ParameterDeclContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitParameterDecl");

    vector<string> identifiers = ctx->identifierList()->accept(this);
    Type *type = ctx->type()->accept(this);

    vector<BasicVar *> parameters;
    for (auto identifier : identifiers) {
        parameters.push_back(var_factory.Get(identifier, type));
    }
    return parameters;
}

