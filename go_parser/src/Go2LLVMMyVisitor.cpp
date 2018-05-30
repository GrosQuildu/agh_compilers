#include "Go2LLVMMyVisitor.h"

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;

Go2LLVMMyVisitor::Go2LLVMMyVisitor(LLVMContext& the_context, IRBuilder<>& builder, Module* the_module) :
        builder(builder), the_context(&the_context), the_module(the_module) {}
