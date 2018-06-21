#include <iostream>

#include "llvm/Support/raw_os_ostream.h"
#include "antlr4-runtime.h"
#include "Go2LLVMParser.h"
#include "Go2LLVMLexer.h"
#include "visitors/Go2LLVMMyVisitor.h"
#include "exceptions/Go2LLVMWarning.h"

using namespace go_parser;
using namespace antlr4;

using std::cerr;
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;



int main(int argc, const char **argv) {
    
    // Parse cmd line arguments
    string input_file;
    string output_file;
    if(argc == 2) {
        input_file = argv[1];
        if(input_file.substr(input_file.length()-3) == ".go")
            output_file = input_file.substr(0, input_file.length()-3) + ".ll";
        else
            output_file = input_file + ".ll";

    } else if(argc == 4) {
        if(argv[1] == "-o" || argv[1] == "--out") {
            input_file = argv[3];
            output_file = argv[2];
        } else if(argv[2] == "-o" || argv[2] == "--out") {
            input_file = argv[1];
            output_file = argv[3];
        }
    } else {
        cerr << "Usage " << argv[0] << " file.go [-o | --out file.ll]\n";
        return 1;
    }

    // Check if source file exists
    ifstream input_file_stream(input_file);
    if(!input_file_stream.good()) {
        cerr << "Can't read file " << input_file << "\n";
        return 1;
    }


    // Load file to antlr
    ifstream stream;
    stream.open(input_file);

    ANTLRInputStream input(stream);
    Go2LLVMLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    Go2LLVMParser parser(&tokens);

    // Parse
    Go2LLVMParser::SourceFileContext* tree = parser.sourceFile();

    if(parser.getNumberOfSyntaxErrors() > 0) {
        return 1;
    }

    // Globals for LLVM
    LLVMContext the_context;
    IRBuilder<> builder(the_context);
    Module *module = new Module("Go2LLVM module", the_context);

    // Traverse parser tree
    Go2LLVMMyVisitor visitor(the_context, builder, module);

    try {
        visitor.visitSourceFile(tree);
    } catch(Go2LLVMError) {
        cout<<"Parser errors:\n";
        Go2LLVMError::PrintErrors();
        return 1;
    }

    if(!Go2LLVMWarning::NoWarnings()) {
        Go2LLVMWarning::PrintWarnings();
    }

    // Verify, dump to stdout and save to file
    verifyModule(*module);
    module->dump();

    ofstream output_file_stream(output_file);
    raw_os_ostream OutputFile(output_file_stream);
    module->print(OutputFile, nullptr);

    return 0;
}
