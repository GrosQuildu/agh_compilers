#include "Go2LLVMMyVisitor.h"

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;

Go2LLVMMyVisitor::Go2LLVMMyVisitor(LLVMContext &context, IRBuilder<> &builder, Module *module) :
        builder(builder), context(context), module(module), is_main_defined(false), var_factory(context, builder) {
}
