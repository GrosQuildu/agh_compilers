/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
* Use of this file is governed by the BSD 3-clause license that
* can be found in the LICENSE.txt file in the project root.
*/

//
//  main.cpp
//  antlr4-cpp-demo
//
//  Created by Mike Lischke on 13.03.16.
//

#include <iostream>
#include "antlr4-runtime.h"
#include "Go2LLVMParser.h"
#include "Go2LLVMLexer.h"
#include "Go2LLVMMyVisitor.h"

using namespace go_parser;
using namespace antlr4;


int main(int, const char **) {
    std::ifstream stream;
    stream.open("test.go");

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

//    Go2LLVMMyVisitor visitor;
//    Scene scene = visitor.visitFile(tree);
//    scene.draw();

    return 0;
}
