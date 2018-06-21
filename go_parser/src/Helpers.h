//
// Created by gros on 02.06.18.
//

#ifndef GO_PARSER_HELPERS_H
#define GO_PARSER_HELPERS_H

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/InstrTypes.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>
#include <map>
#include "variables/BasicVar.h"


namespace go_parser {

    class StringHelper {
    public:
        static inline bool IsHexDigit(char c);

        static inline bool IsOctalDigit(char c);

        static inline int HexToInt(char c);

        static llvm::StringRef Unescape(std::string str);
    };

    class NoNamedValueException : public std::exception {
    };


    class MyBlock {
    public:
        MyBlock();
        MyBlock(MyBlock *previous);

        /*
         * Find Variable in named_value by the name in this block and it's parents blocks
         */
        BasicVar* GetNamedValue(std::string value_name);
        void DumpVariables();

        MyBlock *previous;
        std::map<std::string, BasicVar*> named_values;
    };

}

#endif //GO_PARSER_HELPERS_H
