#include <sstream>
#include "BasicVar.h"
#include "../exceptions/Go2LLVMError.h"
#include "VarFactory.h"

using namespace go_parser;

using std::string;
using std::pair;
using std::tuple;
using llvm::Type;
using llvm::Value;
using llvm::CastInst;
using llvm::FPToUIInst;
using llvm::UIToFPInst;
using llvm::Module;
using llvm::IRBuilder;

BasicVar::BasicVar(llvm::LLVMContext &context, IRBuilder<> &builder) :
        builder(builder), context(context) {
}

BasicVar::BasicVar(llvm::LLVMContext &context, IRBuilder<> &builder, const string &name, Type *type) :
        name(name), type(type), builder(builder), context(context) {
}

void BasicVar::setValue(llvm::Value *value) {
    this->value = Cast(value);
}

Value *BasicVar::getValue() {
    return this->value;
}

Type *BasicVar::getType() {
    return this->type;
}

void BasicVar::setType(llvm::Type *type) {

}

BasicVar* BasicVar::CreateExpression(std::string op, BasicVar *r) {
    if (this->getType() != r->getType()) {
        throw Go2LLVMError(
                "Auto-cast didn't work, can't create expression for types " +
                VarFactory::TypeToString(this->getType()) + ", " +
                VarFactory::TypeToString(r->getType()) + "and operator " + op);
    }
    return this->Expression(op, r);
}