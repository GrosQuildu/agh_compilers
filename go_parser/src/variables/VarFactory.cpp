#include "VarFactory.h"
#include "IntegerVar.h"
#include "FloatVar.h"
#include "../exceptions/Go2LLVMError.h"
#include "PointerVar.h"
#include "VoidVar.h"
#include "BoolVar.h"

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

VarFactory::VarFactory(llvm::LLVMContext &context, IRBuilder<> &builder) : context(context), builder(builder) {};


BasicVar *VarFactory::Get(std::string name, llvm::Type *type, llvm::Value *value) {
    Go2LLVMError::Log("VarFactory::Get - type: " + VarFactory::TypeToString(type) + ", value: " +
                      VarFactory::TypeToString(value->getType()));

    BasicVar *var = VarFactory::Get(name, type);
    var->setValue(value);
    return var;
}

BasicVar *VarFactory::Get(std::string name, llvm::Type *type) {
    Go2LLVMError::Log("VarFactory::Get - type: " + VarFactory::TypeToString(type));

    if (type->isIntegerTy(1))
        return new BoolVar(context, builder, name, type);
    else if (type->isFloatingPointTy())
        return new FloatVar(context, builder, name, type);
    else if (type->isIntegerTy())
        return new IntegerVar(context, builder, name, type);
    else if (type->isPointerTy())
        return new PointerVar(context, builder, name, type);
    else if (type->isVoidTy())
        return new VoidVar(context, builder, name, type);

    throw Go2LLVMError("Unknown type: " + VarFactory::TypeToString(type));
}

BasicVar *VarFactory::Get(std::string type, std::string init_val) {
    Go2LLVMError::Log("VarFactory::Get - typeStr: " + type + ", init_val: " + init_val);

    if(type == "IntegerVar") {
        return new IntegerVar(context, builder, init_val);
    } else if(type == "FloatVar") {
        return new FloatVar(context, builder, init_val);
    } else if(type == "BoolVar") {
        return new BoolVar(context, builder, init_val);
    }

    throw Go2LLVMError("Unknown type: " + type);
}

Type *VarFactory::StringToType(string type_string) {
    Type *type;
    if (type_string.substr(0, 3) == "int") {
        string bitWidth = type_string.substr(3);
        if (bitWidth.empty())
            bitWidth = "64";
        type = Type::getIntNTy(context, (unsigned int) std::stoi(bitWidth));
    } else if (type_string.substr(0, 5) == "float") {
        string bitWidth = type_string.substr(5);
        if (bitWidth.empty())
            bitWidth = "64";

        if (bitWidth == "16")
            type = Type::getHalfTy(context);
        else if (bitWidth == "32")
            type = Type::getFloatTy(context);
        else if (bitWidth == "64")
            type = Type::getDoubleTy(context);
        else if (bitWidth == "128")
            type = Type::getFP128Ty(context);
        else
            type = Type::getDoubleTy(context);
    } else if (type_string == "string") {
        throw Go2LLVMError("Strings not implemented ;/");
    } else if (type_string == "void") {
        type = llvm::FunctionType::getVoidTy(context);
    } else if (type_string == "bool") {
        type = Type::getIntNTy(context, 1);
    } else {
        return nullptr;
    }
    return type;
}

string inline PointerTypeToString(llvm::PointerType *type) {
    return VarFactory::TypeToString(type->getContainedType(0));
}

string inline IntegerTypeToString(llvm::IntegerType *type) {
    return std::to_string(type->getIntegerBitWidth()) + " bits";
}

string VarFactory::TypeToString(Type *type) {
    static std::map<Type::TypeID, string> types_id_map = {
            {Type::VoidTyID,      "VoidTyID"},
            {Type::HalfTyID,      "HalfTyID"},
            {Type::FloatTyID,     "FloatTyID"},
            {Type::DoubleTyID,    "DoubleTyID"},
            {Type::X86_FP80TyID,  "X86_FP80TyID"},
            {Type::FP128TyID,     "FP128TyID"},
            {Type::PPC_FP128TyID, "PPC_FP128TyID"},
            {Type::LabelTyID,     "LabelTyID"},
            {Type::MetadataTyID,  "MetadataTyID"},
            {Type::X86_MMXTyID,   "X86_MMXTyID"},
            {Type::TokenTyID,     "TokenTyID"},
            {Type::IntegerTyID,   "IntegerTyID"},
            {Type::FunctionTyID,  "FunctionTyID"},
            {Type::StructTyID,    "StructTyID"},
            {Type::ArrayTyID,     "ArrayTyID"},
            {Type::PointerTyID,   "PointerTyID"},
            {Type::VectorTyID,    "VectorTyID"}
    };
    string result = types_id_map.at(type->getTypeID());

    if (type->isPointerTy()) {
        result += "(" + PointerTypeToString((llvm::PointerType*)type) + ")";
    }

    if (type->isIntegerTy()) {
        result += "(" + IntegerTypeToString((llvm::IntegerType*)type) + ")";
    }

    return result;
}


std::pair<BasicVar*, BasicVar*> VarFactory::BestCast(BasicVar *l, BasicVar *r) {
    if (l->getType() == r->getType())
        return std::make_pair(l, r);

    bool cast_r;

    if(l->getType()->isIntegerTy(1))
        cast_r = true;
    else if(r->getType()->isIntegerTy(1))
        cast_r = false;
    else if (l->getType()->isIntegerTy() && r->getType()->isIntegerTy()) {
        if (l->getType()->getIntegerBitWidth() >= r->getType()->getIntegerBitWidth())
            cast_r = true;
        else
            cast_r = false;
    } else if (l->getType()->isIntegerTy() && r->getType()->isDoubleTy()) {
        cast_r = false;
    } else if (l->getType()->isFloatingPointTy() && r->getType()->isIntegerTy()) {
        cast_r = true;
    } else if (l->getType()->isFloatingPointTy() && r->getType()->isFloatingPointTy()) {
        cast_r = false;
    } else {
        throw Go2LLVMError("Can't cast from " + VarFactory::TypeToString(l->getType()) + " to " +
                           VarFactory::TypeToString(r->getType()));
    }

    if (cast_r) {
        r = this->Get(r->name, l->getType(), r->getValue());
    } else {
        l = this->Get(l->name, r->getType(), l->getValue());
    }

    return std::make_pair(l, r);
};