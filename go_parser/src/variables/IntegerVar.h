#ifndef GO_PARSER_INTEGERVAR_H
#define GO_PARSER_INTEGERVAR_H

#include "BasicVar.h"

namespace go_parser {
    class IntegerVar : public BasicVar {
    public:
        IntegerVar(llvm::LLVMContext &context, llvm::IRBuilder<> &builder, std::string init_value);

        IntegerVar(llvm::LLVMContext &context, llvm::IRBuilder<> &builder, const std::string &name,
                   llvm::Type *type);

        BasicVar* Expression(std::string op, BasicVar *var) override;

        BasicVar* Expression(std::string op) override;

        llvm::Constant *getZeroValue() override;

        llvm::Value *Cast(llvm::Value *l) override;
    };
}

#endif //GO_PARSER_INTEGERVAR_H
