#ifndef GO_PARSER_VARFACTORY_H
#define GO_PARSER_VARFACTORY_H

#include "BasicVar.h"

namespace go_parser {
    class VarFactory {
    public:
        VarFactory(llvm::LLVMContext &context, llvm::IRBuilder<> &builder);

        BasicVar* Get(std::string name, llvm::Type *type, llvm::Value *value);
        BasicVar* Get(std::string name, llvm::Type *type);
        BasicVar* Get(std::string type, std::string init_val);

        /*
         * Update one of values, so they have the same type
         */
        std::pair<BasicVar*, BasicVar*> BestCast(BasicVar* l, BasicVar* r);

        llvm::Type* StringToType(std::string type_string);

        static std::string TypeToString(llvm::Type *type);

        llvm::IRBuilder<> &builder;
        llvm::LLVMContext &context;
    };
}

#endif //GO_PARSER_VARFACTORY_H
