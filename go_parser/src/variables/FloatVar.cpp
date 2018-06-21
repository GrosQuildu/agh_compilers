#include "FloatVar.h"
#include "VarFactory.h"
#include "../exceptions/Go2LLVMError.h"
#include "../exceptions/Go2LLVMWarning.h"

using namespace go_parser;

using llvm::ConstantFP;
using llvm::Constant;
using llvm::APFloat;
using llvm::CmpInst;

FloatVar::FloatVar(llvm::LLVMContext &context, llvm::IRBuilder<> &builder, std::string number) : BasicVar(context,
                                                                                                          builder) {
    // minimal amount of bits required to store this literal
    Value *value = ConstantFP::get(context, APFloat(APFloat::IEEEdouble, number));

    this->name = "basicFloatLiteral";
    this->type = value->getType();
}

FloatVar::FloatVar(llvm::LLVMContext &context, llvm::IRBuilder<true> &builder,
                   const std::string &name, llvm::Type *type) : BasicVar(context, builder, name, type) {

}


llvm::Value *FloatVar::Cast(llvm::Value *l) {
    if (l->getType() == type)
        return l;

    if (l->getType()->isFloatingPointTy() && l->getType()->getFPMantissaWidth() > type->getFPMantissaWidth()) {
        Go2LLVMWarning::AddWarning("Casting loses mantissa bits, from " +
                                   VarFactory::TypeToString(l->getType()) + " to " +
                                   VarFactory::TypeToString(type));
    }

    if (l->getType()->isIntegerTy()) {
        l = builder.CreateSIToFP(l, type);
    } else if (l->getType()->isFloatingPointTy()) {
        l = builder.CreateFPCast(l, type);
    } else {
        throw Go2LLVMError(
                "Can't cast from " + VarFactory::TypeToString(l->getType()) + " to " + VarFactory::TypeToString(type));
    }

    return l;
}

Constant *FloatVar::getZeroValue() {
    return llvm::ConstantFP::getZeroValueForNegation(type);
}

BasicVar* FloatVar::Expression(std::string op, BasicVar *var) {
    Value *l = this->getValue();
    Value *r = var->getValue();

    switch (op[0]) {
        case '+':
            value = builder.CreateFAdd(l, r, "binaryFAdd"); break;
        case '-':
            value = builder.CreateFSub(l, r, "binaryFSub"); break;
        case '*':
            value = builder.CreateFMul(l, r, "binaryFMul"); break;
        case '/':
            value = builder.CreateFDiv(l, r, "binaryFDiv"); break;
        case '=':
            value = builder.CreateFCmp(CmpInst::Predicate::FCMP_OEQ, l, r, "binaryFCmp"); break;
        default:
            throw Go2LLVMError("unknown unary operator " + op);
    }

    return this;
}

BasicVar* FloatVar::Expression(std::string op) {
    Value *r = this->getValue();

    switch (op[0]) {
        case '+':
            value = r; break;
        case '-':
            value = builder.CreateFSub(this->getZeroValue(), r, "unarySub"); break;
        default:
            throw Go2LLVMError("Unknown unary operator " + op);
    }

    return this;
}
