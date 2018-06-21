#ifndef GO_PARSER_BASICVAR_H
#define GO_PARSER_BASICVAR_H

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/InstrTypes.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>
#include <map>
#include <ParserRuleContext.h>

namespace go_parser {
    class BasicVar {
    public:
        std::string name;
        llvm::Type *type;
        llvm::Value *value;
        llvm::IRBuilder<> &builder;
        llvm::LLVMContext &context;

        BasicVar(llvm::LLVMContext &context, llvm::IRBuilder<> &builder);
        BasicVar(llvm::LLVMContext &context, llvm::IRBuilder<> &builder, const std::string &name, llvm::Type *type);

        BasicVar* CreateExpression(std::string op, BasicVar*);

        virtual BasicVar* Expression(std::string op, BasicVar*) = 0;
        virtual BasicVar* Expression(std::string op) = 0;

        /*
         * Cast given value to this->type and save as this->value
         */
        void setValue(llvm::Value* value);

        virtual llvm::Value* getValue();

        virtual llvm::Type* getType();

        /*
         * Cast this->value to new type and save it
         */
        void setType(llvm::Type* type);

        virtual llvm::Constant* getZeroValue() = 0;

        /*
         * Cast given value to this->type and return it
         */
        virtual llvm::Value* Cast(llvm::Value *l) = 0;
    };
}

#endif //GO_PARSER_BASICVAR_H
