//
// Created by gros on 02.06.18.
//

#ifndef GO_PARSER_MYBASICBLOCK_H
#define GO_PARSER_MYBASICBLOCK_H

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/DerivedTypes.h>

namespace go_parser {

    class Variable {
    public:
        Variable(std::string name, llvm::Type *type, llvm::Value *value) : name(name), type(type), value(value) {}
        Variable(std::string name, llvm::Type *type) : name(name), type(type), value(nullptr) {}
        Variable() {};
        Variable(const Variable &v) {
            name = v.name;
            type = v.type;
            value = v.value;
        }

        std::string name;
        llvm::Type *type;
        llvm::Value* value;

        static llvm::Type* TypeFromStr(llvm::LLVMContext &context, std::string typeStr) {
            if(typeStr.substr(0, 3) == "int") {
                std::string bitWidth = typeStr.substr(3);
                llvm::IntegerType::get(context, (unsigned int)std::stoi(bitWidth));
            } else if(typeStr == "void") {
                return llvm::FunctionType::getVoidTy(context);
            }
            return llvm::IntegerType::get(context, 32);
        }
    };

    class NoNamedValueException : public std::exception {

    };

    class MyBasicBlock {
    public:
        MyBasicBlock(llvm::Function *function) :
                function{function}, previous{nullptr} {}

        MyBasicBlock(llvm::Function *function, MyBasicBlock *previous) :
                function{function}, previous{previous} {}

        /*
         * Find Variable in named_value by the name in this block and it's parents blocks
         */
        Variable get_named_value(std::string value_name) {
            if (named_values.find(value_name) != named_values.end()) {
                Variable x = named_values[value_name];
                return x;
            }
            if(previous != nullptr)
                return previous->get_named_value(value_name);
            throw NoNamedValueException();
        }

        llvm::Function *function;
        MyBasicBlock *previous;
        std::map<std::string, Variable> named_values;
    };

}

#endif //GO_PARSER_MYBASICBLOCK_H
