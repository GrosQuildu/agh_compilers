//
// Created by gros on 29.05.18.
//

#ifndef GO_PARSER_GO2LLVMERROR_H
#define GO_PARSER_GO2LLVMERROR_H

#include <iostream>
#include <llvm/IR/Value.h>

using std::string;
using std::vector;
using std::cout;
using std::exception;
using llvm::Value;

namespace go_parser {
    class Go2LLVMError : exception {
        static std::vector<string> errors;
        static std::vector<string> warnings;

    public:
        Go2LLVMError() : exception() {}

        Go2LLVMError(string error) : exception() {
            errors.push_back(error);
        }

        Go2LLVMError(size_t line_no, string error) {
            errors.push_back("Error at line " + std::to_string(line_no) + string(": ") + error);
        }

        static void AddWarning(string warning) {
            warnings.push_back("Warning: " + warning);
        }

        static void AddWarning(size_t line_no, string warning) {
            warnings.push_back("Warning at line " + std::to_string(line_no) + string(": ") + warning);
        }

        static vector<string> GetWarnings() {
            return warnings;
        }

        static vector<string> GetErrors() {
            return errors;
        }

        static bool NoWarnings() {
            return Go2LLVMError::warnings.empty();
        }

        static bool NoErrors() {
            return Go2LLVMError::errors.empty();
        }

        static void PrintWarnings() {
            for (string warning : warnings) {
                cout << warning << "\n";
            }
        }

        static void PrintErrors() {
            for (string error : errors) {
                cout << error << "\n";
            }
        }

        static void Log(string log) {
            cout <<"Log: " << log << std::endl;
        }
    };
}

#endif //GO_PARSER_GO2LLVMERROR_H
