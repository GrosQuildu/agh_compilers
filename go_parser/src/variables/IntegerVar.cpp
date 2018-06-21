#include "IntegerVar.h"
#include "VarFactory.h"
#include "../exceptions/Go2LLVMError.h"
#include "../exceptions/Go2LLVMWarning.h"

using namespace go_parser;

using llvm::ConstantInt;
using llvm::Constant;
using llvm::APInt;
using llvm::CmpInst;
using llvm::GetElementPtrInst;


IntegerVar::IntegerVar(llvm::LLVMContext &context, llvm::IRBuilder<> &builder, std::string number) : BasicVar(context,
                                                                                                              builder) {
    // minimal amount of bits required to store this literal
    size_t bit_width;

    if (number.substr(0, 2) == "0x" || number.substr(0, 2) == "0X") {
        number = number.substr(2);
        bit_width = 1 + number.length() * 4;
        value = ConstantInt::get(context, APInt(bit_width, number, 16));
    } else if (number.substr(0, 1) == "0" && number.size() > 1) {
        number = number.substr(1);
        bit_width = 1 + number.length() * 3;
        value = ConstantInt::get(context, APInt(bit_width, number, 8));
    } else {
        bit_width = 2 + 3 * number.length() + ((number.length() - 1) / 3);
        value = ConstantInt::get(context, APInt(bit_width, number, 10));
    }

    this->name = "basicIntegerLiteral";
    this->type = value->getType();
}

IntegerVar::IntegerVar(llvm::LLVMContext &context, llvm::IRBuilder<true> &builder,
                       const std::string &name, llvm::Type *type) : BasicVar(context, builder, name, type) {}

llvm::Value *IntegerVar::Cast(llvm::Value *l) {
    if (l->getType() == type)
        return l;

    if (l->getType()->isIntegerTy() && l->getType()->getIntegerBitWidth() > type->getIntegerBitWidth()) {
        Go2LLVMWarning::AddWarning("Casting loses bits, from " +
                                   VarFactory::TypeToString(l->getType()) + " to " +
                                   VarFactory::TypeToString(type));
    } else if (l->getType()->isFloatingPointTy()) {
        Go2LLVMWarning::AddWarning("Casting loses precision, from " +
                                   VarFactory::TypeToString(l->getType()) + " to " +
                                   VarFactory::TypeToString(type));
    }

    if (l->getType()->isIntegerTy()) {
        l = builder.CreateIntCast(l, type, true);
    } else if (l->getType()->isFloatingPointTy()) {
        l = builder.CreateFPToSI(l, type);
    } else {
        throw Go2LLVMError("Can't cast from " + VarFactory::TypeToString(l->getType()) + " to " +
                           VarFactory::TypeToString(type));
    }

    return l;
}

Constant *IntegerVar::getZeroValue() {
    return ConstantInt::get(context, APInt(type->getIntegerBitWidth(), 0));
}

BasicVar *IntegerVar::Expression(std::string op, BasicVar *var) {
    Value *l = this->getValue();
    Value *r = var->getValue();

    if(op == "+") {
        value = builder.CreateAdd(l, r, "binaryAdd");
    } else if(op == "-") {
        value = builder.CreateSub(l, r, "CreateSub");
    } else if(op == "*") {
        value = builder.CreateMul(l, r, "CreateMul");
    } else if(op == "/") {
        value = builder.CreateSDiv(l, r, "CreateDiv");
    } else if(op == "%") {
        value = builder.CreateSRem(l, r, "CreateRem");
    } else if(op == "<<") {
        value = builder.CreateShl(l, r, "CreateShl");
    } else if(op == ">>") {
        value = builder.CreateLShr(l, r, "CreateLShr");
    } else if(op == "&") {
        value = builder.CreateBinOp(llvm::BinaryOperator::And, l, r, "CreateAnd");
    } else if(op == "&^") {
        value = builder.CreateBinOp(llvm::BinaryOperator::And, l, r, "CreateAnd");
    } else if(op == "|") {
        value = builder.CreateBinOp(llvm::BinaryOperator::Or, l, r, "CreateOr");
    } else if(op == "^") {
        value = builder.CreateBinOp(llvm::BinaryOperator::Xor, l, r, "CreateXor");
    } else if(op == "==") {
        value = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, l, r, "binaryCmpICMP_EQ");
    } else if(op == "!=") {
        value = builder.CreateICmp(CmpInst::Predicate::ICMP_NE, l, r, "binaryCmpICMP_NE");
    }  else if(op == "<") {
        value = builder.CreateICmp(CmpInst::Predicate::ICMP_SLT, l, r, "binaryCmpICMP_SLT");
    }  else if(op == ">") {
        value = builder.CreateICmp(CmpInst::Predicate::ICMP_SGT, l, r, "binaryCmpICMP_SGT");
    }  else if(op == "<=") {
        value = builder.CreateICmp(CmpInst::Predicate::ICMP_SLE, l, r, "binaryCmpICMP_SLE");
    }  else if(op == ">=") {
        value = builder.CreateICmp(CmpInst::Predicate::ICMP_SGE, l, r, "binaryCmpICMP_SLE");
    } else if(op == "&&") {
        value = builder.CreateAnd(l, r, "CreateAnd");
    }  else if(op == "||") {
        value = builder.CreateOr(l, r, "CreateOr");
    } else {
        throw Go2LLVMError(
                "Unknown binary operator " + op + " for " + VarFactory::TypeToString(l->getType()) + " and " +
                VarFactory::TypeToString(r->getType()));
    }

    this->type = value->getType();
    return this;
}

BasicVar *IntegerVar::Expression(std::string op) {
    Value *r = this->getValue();

    if(op == "+") {
        value = r;
    } else if(op == "-") {
        value = builder.CreateSub(this->getZeroValue(), r, "unarySub");
    } else if(op == "!") {
        value = builder.CreateNeg(r, "CreateMul");
    } else {
        throw Go2LLVMError("Unknown unary operator " + op + " for " + VarFactory::TypeToString(r->getType()));
    }

    return this;
}
