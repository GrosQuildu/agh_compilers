#include <vector>
#include "Go2LLVMError.h"

using namespace go_parser;

std::vector<std::string> Go2LLVMError::errors;
size_t Go2LLVMError::line_no;

void Go2LLVMError::Log(string log) {
#if DEBUG == 1
    cout <<"Log: " << log << std::endl;
#endif
}