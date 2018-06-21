#include "BoolVar.h"
#include "VarFactory.h"
#include "../exceptions/Go2LLVMError.h"
#include "../exceptions/Go2LLVMWarning.h"

using namespace go_parser;

using llvm::ConstantInt;
using llvm::Constant;
using llvm::APInt;
using llvm::CmpInst;

BoolVar::BoolVar(llvm::LLVMContext &context, llvm::IRBuilder<> &builder, std::string number) : BasicVar(context,
                                                                                                        builder) {
    // minimal amount of bits required to store this literal
    size_t bit_width;

    if (number == "1" || number == "true" || number == "TRUE") {
        value = ConstantInt::get(context, APInt(1, 1, 10));
    } else {
        value = ConstantInt::get(context, APInt(1, 0, 10));
    }

    this->name = "basicBoolLiteral";
    this->type = value->getType();
}

BoolVar::BoolVar(llvm::LLVMContext &context, llvm::IRBuilder<true> &builder,
                 const std::string &name, llvm::Type *type) : BasicVar(context, builder, name, type) {}

llvm::Value *BoolVar::Cast(llvm::Value *l) {
    if (l->getType() == type)
        return l;

    if (l->getType()->isIntegerTy()) {
        l = builder.CreateICmpNE(l, ConstantInt::get(context, APInt(l->getType()->getIntegerBitWidth(), 0)));
    } else if (l->getType()->isFloatingPointTy()) {
        l = builder.CreateFCmpONE(l, llvm::ConstantFP::get(context, llvm::APFloat(l->getType()->getFltSemantics(), 0)));
    } else {
        throw Go2LLVMError("Can't cast " + VarFactory::TypeToString(l->getType()) + " to bool " +
                           VarFactory::TypeToString(this->getType()));
    }

    return l;

}

Constant *BoolVar::getZeroValue() {
    return ConstantInt::get(context, APInt(type->getIntegerBitWidth(), 0));
}

BasicVar *BoolVar::Expression(std::string op, BasicVar *var) {
    Value *l = this->getValue();
    Value *r = var->getValue();

    if (op == "==") {
        value = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, l, r, "binaryCmpICMP_EQ");
    } else if (op == "!=") {
        value = builder.CreateICmp(CmpInst::Predicate::ICMP_NE, l, r, "binaryCmpICMP_NE");
    } else if (op == "&&") {
        value = builder.CreateAnd(l, r, "CreateAnd");
    } else if (op == "||") {
        value = builder.CreateOr(l, r, "CreateOr");
    } else {
        throw Go2LLVMError(
                "Unknown binary operator " + op + " for " + VarFactory::TypeToString(l->getType()) + " and " +
                VarFactory::TypeToString(r->getType()));
    }

    this->type = value->getType();
    return this;
}

BasicVar *BoolVar::Expression(std::string op) {
    Value *r = this->getValue();

    if (op == "!") {
        value = builder.CreateNeg(r, "CreateMul");
    } else {
        throw Go2LLVMError("Unknown unary operator " + op + " for " + VarFactory::TypeToString(r->getType()));
    }

    return this;
}