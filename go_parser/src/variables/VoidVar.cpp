#include "VoidVar.h"
#include "VarFactory.h"
#include "../exceptions/Go2LLVMError.h"
#include "../exceptions/Go2LLVMWarning.h"

using namespace go_parser;

using llvm::ConstantInt;
using llvm::Constant;
using llvm::APInt;
using llvm::CmpInst;

VoidVar::VoidVar(llvm::LLVMContext &context, llvm::IRBuilder<> &builder,
                       const std::string &name, llvm::Type *type) : BasicVar(context, builder, name, type) {}

llvm::Value *VoidVar::Cast(llvm::Value *l) {
    if (l->getType() == type)
        return l;

    throw Go2LLVMError("Can't cast " + VarFactory::TypeToString(l->getType()) + " to void " +
                       VarFactory::TypeToString(this->getType()));
}

Constant *VoidVar::getZeroValue() {
    return llvm::ConstantPointerNull::get((llvm::PointerType *) getValue()->getType());
}

BasicVar *VoidVar::Expression(std::string op, BasicVar *var) {
    throw Go2LLVMError("Expressions with voids not allowed");
}

BasicVar *VoidVar::Expression(std::string op) {
    throw Go2LLVMError("Expressions with voids not allowed");
}