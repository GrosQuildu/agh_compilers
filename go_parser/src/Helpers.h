//
// Created by gros on 02.06.18.
//

#ifndef GO_PARSER_HELPERS_H
#define GO_PARSER_HELPERS_H

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/InstrTypes.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>
#include <map>


namespace go_parser {

    class Variable {
    public:
        Variable(std::string name, llvm::Type *type, llvm::Value *value);

        Variable(std::string name, llvm::Type *type);

        Variable();

        Variable(const Variable &v);

        std::string name;
        llvm::Type *type;
        llvm::Value *value;

        static llvm::Type *TypeFromStr(llvm::LLVMContext &context, std::string type_string);

        static std::string IntStrFromIntToken(std::string int_token);

        static llvm::Value* CastL2R(size_t line_no, llvm::IRBuilder<> &builder, llvm::Value *l, llvm::Type *t);

        static std::pair<llvm::Value*, llvm::Value*> Cast(size_t line_no, llvm::IRBuilder<> &builder, llvm::Value *l, llvm::Value *r);
    };

    class StringHelper {
    public:
        static inline bool IsHexDigit(char c);

        static inline bool IsOctalDigit(char c);

        static inline int HexToInt(char c);

        static llvm::StringRef Unescape(std::string str);
    };

    class NoNamedValueException : public std::exception {
    };


    class MyBlock {
    public:
        MyBlock(llvm::Function *function);

        MyBlock(llvm::Function *function, MyBlock *previous);

        /*
         * Find Variable in named_value by the name in this block and it's parents blocks
         */
        Variable GetNamedValue(std::string value_name);

        llvm::Function *function;
        MyBlock *previous;
        std::map<std::string, Variable> named_values;
    };

}

#endif //GO_PARSER_HELPERS_H
