//
// Created by gros on 29.05.18.
//

#ifndef GO_PARSER_GO2LLVMERROR_H
#define GO_PARSER_GO2LLVMERROR_H

#include <iostream>
#include "llvm/IR/IRBuilder.h"

using llvm::Value;

class Go2LLVMError {
    std::vector<std::string> errors;

public:
    Go2LLVMError() {}

    Go2LLVMError(std::string error) {
        errors.push_back(error);
    }

    std::vector<std::string> GetErrors() {
        return errors;
    }

    bool NoErrors() {
        return errors.empty();
    }

    void PrintErrors() {
        for(std::string error : errors) {
            std::cout<<error<<"\n";
        }
    }

    Value* AddError(size_t line_no, std::string error) {
        errors.push_back("Error at line " + std::to_string(line_no) + std::string(": ") + error);
        return nullptr;
    }

    Value* AddError(std::string error) {
        errors.push_back(error);
        return nullptr;
    }

    void Log(std::string log) {
        std::cout<<log<<std::endl;
    }
};


#endif //GO_PARSER_GO2LLVMERROR_H
