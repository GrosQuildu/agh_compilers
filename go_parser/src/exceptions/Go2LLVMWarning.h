//
// Created by gros on 20.06.18.
//

#ifndef GO_PARSER_GO2LLVMWARNING_H
#define GO_PARSER_GO2LLVMWARNING_H

#include <iostream>
#include <llvm/IR/Value.h>
#include <vector>
#include "Go2LLVMError.h"

using std::string;
using std::vector;
using std::cout;
using std::exception;
using llvm::Value;

namespace go_parser {
    class Go2LLVMWarning : exception {
        static std::vector<string> warnings;
        Go2LLVMWarning() : exception() {}

    public:

        static void AddWarning(string warning) {
            if(Go2LLVMError::line_no == -1)
                warnings.push_back("Warning: " + warning);
            else
                AddWarning(Go2LLVMError::line_no, warning);
        }

        static void AddWarning(size_t line_no, string warning) {
            warnings.push_back("Warning at line " + std::to_string(line_no) + string(": ") + warning);
        }

        static vector<string> GetWarnings() {
            return warnings;
        }

        static bool NoWarnings() {
            return warnings.empty();
        }

        static void PrintWarnings() {
            for (string warning : warnings) {
                cout << warning << "\n";
            }
        }
    };
}

#endif //GO_PARSER_GO2LLVMWARNING_H
