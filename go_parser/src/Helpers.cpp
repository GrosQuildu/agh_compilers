#include <sstream>
#include <llvm/IR/Module.h>

#include "Helpers.h"
#include "Go2LLVMError.h"

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

/* Variable */
Variable::Variable(string name, Type *type, Value *value) : name(name), type(type), value(value) {}
Variable::Variable(string name, Type *type) : name(name), type(type), value(nullptr) {}
Variable::Variable() {};
Variable::Variable(const Variable &v) {
    name = v.name;
    type = v.type;
    value = v.value;
}


Type* Variable::TypeFromStr(llvm::LLVMContext &context, string type_string) {
    Type *type;
    if(type_string.substr(0, 3) == "int") {
        string bitWidth = type_string.substr(3);
        if(bitWidth.empty())
            bitWidth = "64";
        type = Type::getIntNTy(context, (unsigned int)std::stoi(bitWidth));
    } else if(type_string.substr(0, 5) == "float") {
        string bitWidth = type_string.substr(5);
        if(bitWidth.empty())
            bitWidth = "64";

        if(bitWidth == "16")
            type = Type::getHalfTy(context);
        else if(bitWidth == "32")
            type = Type::getFloatTy(context);
        else if(bitWidth == "64")
            type = Type::getDoubleTy(context);
        else if(bitWidth == "128")
            type = Type::getFP128Ty(context);
        else
            type = Type::getDoubleTy(context);
    } else if(type_string == "string") {
        throw Go2LLVMError("Strings not implemented ;/");
    } else if(type_string == "void") {
        type = llvm::FunctionType::getVoidTy(context);
    } else {
        return nullptr;
    }
    return type;
}

std::string Variable::IntStrFromIntToken(std::string int_token) {
    if(int_token.substr(0, 2) == "0x" || int_token.substr(0, 2) == "0X") {
        std::stringstream ss;
        ss << std::hex << int_token.substr(2);
        return ss.str();
    } else if(int_token.substr(0,1) == "0") {
        std::stringstream ss;
        ss << std::oct << int_token.substr(1);
        return ss.str();
    } else {
        return int_token;
    }
}

string Type2String(Type *type) {
    static std::map<Type::TypeID, string> types_id_map = {
            {Type::VoidTyID, "VoidTyID"},
            {Type::HalfTyID, "HalfTyID"},
            {Type::FloatTyID, "FloatTyID"},
            {Type::DoubleTyID, "DoubleTyID"},
            {Type::X86_FP80TyID, "X86_FP80TyID"},
            {Type::FP128TyID, "FP128TyID"},
            {Type::PPC_FP128TyID, "PPC_FP128TyID"},
            {Type::LabelTyID, "LabelTyID"},
            {Type::MetadataTyID, "MetadataTyID"},
            {Type::X86_MMXTyID, "X86_MMXTyID"},
            {Type::TokenTyID, "TokenTyID"},
            {Type::IntegerTyID, "IntegerTyID"},
            {Type::FunctionTyID, "FunctionTyID"},
            {Type::StructTyID, "StructTyID"},
            {Type::ArrayTyID, "ArrayTyID"},
            {Type::PointerTyID, "PointerTyID"},
            {Type::VectorTyID, "VectorTyID"}
    };
    string result = types_id_map.at(type->getTypeID());

    if(type->isIntegerTy()) {
        result += " (" + std::to_string(type->getIntegerBitWidth()) + " bits)";
    }
    return result;
}

/*
 *  Cast left Value* to Type*
 */
Value* Variable::CastL2R(size_t line_no, IRBuilder<> &builder, Value *l, Type *t) {
    if(l->getType() == t)
        return l;

    if(l->getType()->isIntegerTy() && t->isIntegerTy() && l->getType()->getIntegerBitWidth() > t->getIntegerBitWidth()) {
        Go2LLVMError::AddWarning(line_no, "Casting loses bits, from " +
                Type2String(l->getType()) + " to " +
                Type2String(t));
    } else if(l->getType()->isFloatingPointTy() && t->isIntegerTy()) {
        Go2LLVMError::AddWarning(line_no, "Casting loses precision, from " +
                Type2String(l->getType()) + " to " +
                Type2String(t));
    }

    if(l->getType()->isIntegerTy() && t->isIntegerTy()) {
        l = builder.CreateIntCast(l, t, true);
    } else if(l->getType()->isIntegerTy() && t->isFloatingPointTy()) {
        l = builder.CreateSIToFP(l, t);
    } else if(l->getType()->isFloatingPointTy() && t->isIntegerTy()) {
        l = builder.CreateFPToSI(l, t);
    } else if(l->getType()->isFloatingPointTy() && t->isFloatingPointTy()) {
        l = builder.CreateFPCast(l, t);
    } else {
        throw Go2LLVMError(line_no, "Can't cast from " + Type2String(l->getType()) + " to " + Type2String(t));
    }

    return l;
};

tuple<CastInst*, Value*, Value*> reverse_cast_tuple(tuple<CastInst*, Value*, Value*> p) {
    return std::make_tuple(std::get<0>(p),std::get<2>(p),std::get<1>(p));
};

/*
 *  Cast two Values* in best possible way
 */
pair<Value*, Value*> Variable::Cast(size_t line_no, IRBuilder<> &builder, Value *l, Value *r) {
    if(l->getType() == r->getType())
        return std::make_pair(l, r);

    if(l->getType()->isIntegerTy() && r->getType()->isIntegerTy()) {
        if(l->getType()->getIntegerBitWidth() >= r->getType()->getIntegerBitWidth())
            r = Variable::CastL2R(line_no, builder, r, l->getType());
        else
            l = Variable::CastL2R(line_no, builder, l, r->getType());
        return std::make_pair(l, r);
    } else if(l->getType()->isIntegerTy() && r->getType()->isDoubleTy()) {
        l = Variable::CastL2R(line_no, builder, l, r->getType());
        return std::make_pair(l, r);
    } else if(l->getType()->isFloatingPointTy() && r->getType()->isIntegerTy()) {
        r = Variable::CastL2R(line_no, builder, r, l->getType());
        return std::make_pair(l, r);
    } else if(l->getType()->isFloatingPointTy() && r->getType()->isFloatingPointTy()) {
        l = Variable::CastL2R(line_no, builder, l, r->getType());
        return std::make_pair(l, r);
    } else {
        throw Go2LLVMError(line_no, "Can't cast from " + Type2String(l->getType()) + " to " + Type2String(r->getType()));
    }
};


/* StringHelper */
inline bool StringHelper::IsHexDigit(char c) {
    return (c >= 48 && c <= 57) || (c >= 65 && c <= 70) || (c >= 97 && c <= 102);
}

inline bool StringHelper::IsOctalDigit(char c) {
    return (c >= 48) && (c <= 55);
}

inline int StringHelper::HexToInt(char c) {
    if(c >= 48 && c <= 57)
        return c - 48;
    if(c >= 65 && c <= 70)
        return c - 55;
    if(c >= 97 && c <= 102)
        return c - 87;
    else
        return 0;
}

llvm::StringRef StringHelper::Unescape(string str) {
    str = str.substr(1, str.size()-2);
    string str_unescaped;

    size_t i = 0;
    while(i < str.size()) {
        if(str[i] == '\\') {
            if(i+1 > str.size())
                break;
            switch (str[i+1]) {
                case 'a': str_unescaped += '\x07'; i+=2; break;
                case 'b': str_unescaped += '\x08'; i+=2; break;
                case 'f': str_unescaped += '\x0c'; i+=2; break;
                case 'n': str_unescaped += '\x0a'; i+=2; break;
                case 'r': str_unescaped += '\x0d'; i+=2; break;
                case 't': str_unescaped += '\x09'; i+=2; break;
                case 'v': str_unescaped += '\x0b'; i+=2; break;
                case '\\': str_unescaped += '\\'; i+=2; break;
                case '"': str_unescaped += '"'; i+=2; break;

                case 'x':
                    if(i+3 < str.size()) {
                        if(IsHexDigit(str[i + 2]) && IsHexDigit(str[i + 3]))
                            str_unescaped += (char)(HexToInt(str[i+2])*16 + HexToInt(str[i+3]));
                        else
                            throw Go2LLVMError("bad hex byte value: \\x" + str.substr(i+2, 2));
                    } else {
                        throw Go2LLVMError("bad hex byte value at the end of string");
                    }
                    i += 4;
                    break;

                default:
                    if(IsOctalDigit(str[i+1])) {
                        if(i+3 < str.size()) {
                            if(IsOctalDigit(str[i + 2]) && IsOctalDigit(str[i + 3]))
                                str_unescaped += (char)((str[i+1]-48)*64 + (str[i+2]-48)*8 + str[i+3]-48);
                            else {
                                throw Go2LLVMError("bad octal byte value: \\" + str.substr(i+1, 3));
                            }
                        } else {
                            throw Go2LLVMError("bad octal byte value at the end of string");
                        }
                    } else {
                        throw Go2LLVMError("unknown escape character: " + str[i+1]);
                    }
                    i += 4;
                    break;

            }
        } else {
            str_unescaped += str[i];
            i++;
        }
    }
    return str_unescaped;
}


/* Helpers */
MyBlock::MyBlock(llvm::Function *function) : function{function}, previous{nullptr} {}
MyBlock::MyBlock(llvm::Function *function, MyBlock *previous) :function{function}, previous{previous} {}

Variable MyBlock::GetNamedValue(Module *module, std::string value_name) {
    // search in global variables
    llvm::GlobalVariable * global_val = module->getGlobalVariable(value_name, true);
    if(global_val != nullptr)
        return Variable(global_val->getName(), global_val->getType(), global_val);

    // search in current block
    if (named_values.find(value_name) != named_values.end()) {
        Variable x = named_values[value_name];
        return x;
    }

    // recursively search in previous blocks
    if(previous != nullptr)
        return previous->GetNamedValue(module, value_name);
    throw NoNamedValueException();
}