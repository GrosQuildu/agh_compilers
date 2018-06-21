#include "IntegerVar.h"
#include "VarFactory.h"
#include "../exceptions/Go2LLVMError.h"
#include "../exceptions/Go2LLVMWarning.h"

using namespace go_parser;

using llvm::ConstantInt;
using llvm::Constant;
using llvm::APInt;
using llvm::CmpInst;

IntegerVar::IntegerVar(llvm::LLVMContext &context, llvm::IRBuilder<> &builder, std::string number) : BasicVar(context,
                                                                                                              builder) {
    // minimal amount of bits required to store this literal
    size_t bit_width;

    if (number.substr(0, 2) == "0x" || number.substr(0, 2) == "0X") {
        number = number.substr(2);
        bit_width = 1 + number.length() * 4;
        value = ConstantInt::get(context, APInt(bit_width, number, 16));
    } else if (number.substr(0, 1) == "0") {
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

Constant* IntegerVar::getZeroValue() {
    return ConstantInt::get(context, APInt(type->getIntegerBitWidth(), 0));
}

BasicVar* IntegerVar::Expression(std::string op, BasicVar *var) {
    Value *l = this->getValue();
    Value *r = var->getValue();

    switch (op[0]) {
        case '+':
            value = builder.CreateAdd(l, r, "binaryAdd"); break;
        case '-':
            value = builder.CreateSub(l, r, "binarySub"); break;
        case '*':
            value = builder.CreateMul(l, r, "binaryMul"); break;
        case '/':
            value = builder.CreateSDiv(l, r, "binaryDiv"); break;
        case '=':
            value = builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, l, r, "binaryCmp");
        default:
            throw Go2LLVMError("Unknown binary operator " + op);
    }

    return this;
}

BasicVar* IntegerVar::Expression(std::string op) {
    Value *r = this->getValue();

    switch (op[0]) {
        case '+':
            value = r; break;
        case '-':
            value = builder.CreateSub(this->getZeroValue(), r, "unarySub"); break;
        default:
            throw Go2LLVMError("Unknown unary operator " + op);
    }

    return this;
}
