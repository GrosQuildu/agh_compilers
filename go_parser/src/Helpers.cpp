#include <sstream>
#include <llvm/IR/Module.h>

#include "Helpers.h"
#include "exceptions/Go2LLVMError.h"
#include "variables/VarFactory.h"

using namespace go_parser;
using std::string;
using std::pair;
using std::tuple;
using llvm::Type;
using llvm::Value;
using llvm::CastInst;
using llvm::FPToUIInst;
using llvm::UIToFPInst;
using llvm::Module;
using llvm::IRBuilder;



/* StringHelper */
inline bool StringHelper::IsHexDigit(char c) {
    return (c >= 48 && c <= 57) || (c >= 65 && c <= 70) || (c >= 97 && c <= 102);
}

inline bool StringHelper::IsOctalDigit(char c) {
    return (c >= 48) && (c <= 55);
}

inline int StringHelper::HexToInt(char c) {
    if(c >= 48 && c <= 57)
        return c - 48;
    if(c >= 65 && c <= 70)
        return c - 55;
    if(c >= 97 && c <= 102)
        return c - 87;
    else
        return 0;
}

string StringHelper::Unescape(string str) {
    str = str.substr(1, str.size()-2);
    string str_unescaped;

    size_t i = 0;
    while(i < str.size()) {
        if(str[i] == '\\') {
            if(i+1 > str.size())
                break;
            switch (str[i+1]) {
                case 'a': str_unescaped += '\x07'; i+=2; break;
                case 'b': str_unescaped += '\x08'; i+=2; break;
                case 'f': str_unescaped += '\x0c'; i+=2; break;
                case 'n': str_unescaped += '\x0a'; i+=2; break;
                case 'r': str_unescaped += '\x0d'; i+=2; break;
                case 't': str_unescaped += '\x09'; i+=2; break;
                case 'v': str_unescaped += '\x0b'; i+=2; break;
                case '\\': str_unescaped += '\\'; i+=2; break;
                case '"': str_unescaped += '"'; i+=2; break;

                case 'x':
                    if(i+3 < str.size()) {
                        if(IsHexDigit(str[i + 2]) && IsHexDigit(str[i + 3]))
                            str_unescaped += (char)(HexToInt(str[i+2])*16 + HexToInt(str[i+3]));
                        else
                            throw Go2LLVMError("bad hex byte value: \\x" + str.substr(i+2, 2));
                    } else {
                        throw Go2LLVMError("bad hex byte value at the end of string");
                    }
                    i += 4;
                    break;

                default:
                    if(IsOctalDigit(str[i+1])) {
                        if(i+3 < str.size()) {
                            if(IsOctalDigit(str[i + 2]) && IsOctalDigit(str[i + 3]))
                                str_unescaped += (char)((str[i+1]-48)*64 + (str[i+2]-48)*8 + str[i+3]-48);
                            else {
                                throw Go2LLVMError("bad octal byte value: \\" + str.substr(i+1, 3));
                            }
                        } else {
                            throw Go2LLVMError("bad octal byte value at the end of string");
                        }
                    } else {
                        throw Go2LLVMError("unknown escape character: " + str[i+1]);
                    }
                    i += 4;
                    break;

            }
        } else {
            str_unescaped += str[i];
            i++;
        }
    }
    return str_unescaped;
}


/* Helpers */
MyBlock::MyBlock() : previous{nullptr} {}
MyBlock::MyBlock(MyBlock *previous) : previous{previous} {}

void MyBlock::DumpVariables() {
    string result = "";
    for(auto &named_value : named_values) {
        cout<<named_value.second->name<<": ";
        named_value.second->getValue()->dump();
        cout<<"\n";
    }
    if(this->previous != nullptr)
        this->previous->DumpVariables();
}

BasicVar* MyBlock::GetNamedValue(std::string value_name) {
    // search in current block
    if (named_values.find(value_name) != named_values.end()) {
        return named_values[value_name];
    }

    // recursively search in previous blocks
    if(previous != nullptr)
        return previous->GetNamedValue(value_name);
    throw NoNamedValueException();
}