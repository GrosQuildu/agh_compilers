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
    // todo: exponent handling
    value = ConstantFP::get(context, APFloat(APFloat::IEEEdouble(), number));

    this->name = "basicFloatLiteral";
    this->type = value->getType();
}

FloatVar::FloatVar(llvm::LLVMContext &context, llvm::IRBuilder<> &builder,
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

    if(op == "+") {
        value = builder.CreateFAdd(l, r, "CreateFAdd");
    } else if(op == "-") {
        value = builder.CreateFSub(l, r, "CreateFSub");
    } else if(op == "*") {
        value = builder.CreateFMul(l, r, "CreateFMul");
    } else if(op == "/") {
        value = builder.CreateFDiv(l, r, "CreateFDiv");
    } else if(op == "%") {
        value = builder.CreateFRem(l, r, "CreateFRem");
    } else if(op == "==") {
        value = builder.CreateFCmp(CmpInst::Predicate::FCMP_OEQ, l, r, "binaryCmpFCMP_OEQ");
    } else if(op == "!=") {
        value = builder.CreateFCmp(CmpInst::Predicate::FCMP_ONE, l, r, "binaryCmpFCMP_ONE");
    }  else if(op == "<") {
        value = builder.CreateFCmp(CmpInst::Predicate::FCMP_OLT, l, r, "binaryCmpFCMP_OLT");
    }  else if(op == ">") {
        value = builder.CreateFCmp(CmpInst::Predicate::FCMP_OGT, l, r, "binaryCmpFCMP_OGT");
    }  else if(op == "<=") {
        value = builder.CreateFCmp(CmpInst::Predicate::FCMP_OLE, l, r, "binaryCmpFCMP_OLE");
    }  else if(op == ">=") {
        value = builder.CreateFCmp(CmpInst::Predicate::FCMP_OGE, l, r, "binaryCmpFCMP_OGE");
    } else {
        throw Go2LLVMError(
                "Unknown binary operator " + op + " for " + VarFactory::TypeToString(l->getType()) + " and " +
                VarFactory::TypeToString(r->getType()));
    }

    this->type = value->getType();
    return this;
}

BasicVar* FloatVar::Expression(std::string op) {
    Value *r = this->getValue();

    if(op == "+") {
        value = r;
    } else if(op == "-") {
        value = builder.CreateFSub(this->getZeroValue(), r, "unarySub");
    } else {
        throw Go2LLVMError("Unknown unary operator " + op + " for " + VarFactory::TypeToString(r->getType()));
    }

    return this;
}
