#include <iostream>
#include "antlr4-runtime.h"
#include "Go2LLVMParser.h"
#include "Go2LLVMLexer.h"
#include "Go2LLVMMyVisitor.h"

using namespace go_parser;
using namespace antlr4;
using namespace llvm;
using antlrcpp::Any;

int main(int argc, const char **argv) {
    if(argc != 2) {
        std::cerr << "Usage " << argv[0] << " file.go\n";
        return 1;
    }

    std::ifstream stream;
    stream.open(argv[1]);

    ANTLRInputStream input(stream);
    Go2LLVMLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    Go2LLVMParser parser(&tokens);

    Go2LLVMParser::SourceFileContext* tree = parser.sourceFile();

    tokens.fill();
    for (auto token : tokens.getTokens()) {
        std::cout << token->toString() << std::endl;
    }

    std::cout << tree->toStringTree(&parser) << std::endl << std::endl;

    LLVMContext the_context;
    IRBuilder<> builder(the_context);
    Module *the_module = new Module("Go2LLVM module", the_context);

    Go2LLVMMyVisitor visitor(the_context, builder, the_module);
    Any AnyV = visitor.visitSourceFile(tree);

    if(!visitor.parser_errors.NoErrors()) {
        std::cout<<"Parser errors:\n";
        visitor.parser_errors.PrintErrors();
    }

    the_module->dump();
    for(auto const& value : visitor.named_values) {
        value.second->dump();
    }

    the_module->getFunction("main");


    return 0;
}
