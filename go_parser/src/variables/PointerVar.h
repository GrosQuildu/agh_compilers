//
// Created by gros on 21.06.18.
//

#ifndef GO_PARSER_POINTERVAR_H
#define GO_PARSER_POINTERVAR_H

#include "BasicVar.h"

namespace go_parser {
    class PointerVar : public BasicVar {
    public:

        PointerVar(llvm::LLVMContext &context, llvm::IRBuilder<> &builder, const std::string &name,
                   llvm::Type *type);

        BasicVar* Expression(std::string op, BasicVar *var) override;

        BasicVar* Expression(std::string op) override;

        llvm::Constant *getZeroValue() override;

        llvm::Value *Cast(llvm::Value *l) override;
    };
}

#endif //GO_PARSER_POINTERVAR_H
