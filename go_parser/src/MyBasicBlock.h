//
// Created by gros on 02.06.18.
//

#ifndef GO_PARSER_MYBASICBLOCK_H
#define GO_PARSER_MYBASICBLOCK_H

namespace go_parser {

    class Variable {
    public:
        Variable(std::string name, std::string type, Value *value) : name(name), type(type), value(value) {}
        Variable(std::string name, std::string type) : name(name), type(type), value(nullptr) {}
        Variable() {};
        Variable(const Variable &v) {
            name = v.name;
            type = v.type;
            value = v.value;
        }

        std::string name;
        std::string type;
        Value* value;
    };

    class NoNamedValueException : public std::exception {

    };

    class MyBasicBlock {
    public:
        MyBasicBlock(llvm::Function *function, llvm::BasicBlock *basicBlock) :
                function{function}, block{basicBlock}, previous{nullptr} {}

        MyBasicBlock(llvm::Function *function, llvm::BasicBlock *basicBlock, MyBasicBlock *previous) :
                function{function}, block{basicBlock}, previous{previous} {}

        /*
         * Find Variable in named_value by the name in this block and it's parents blocks
         */
        Variable get_named_value(std::string value_name) {
            if (named_values.find(value_name) != named_values.end()) {
                Variable x = named_values[value_name];
                return x;
            }
            if(previous != nullptr)
                return previous->get_named_value(value_name);
            throw NoNamedValueException();
        }

        llvm::Function *function;
        MyBasicBlock *previous;
        llvm::BasicBlock *block;
        std::map<std::string, Variable> named_values;
    };

}

#endif //GO_PARSER_MYBASICBLOCK_H
