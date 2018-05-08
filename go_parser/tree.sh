#!/bin/bash

antlr4='java -Xmx500M -cp "/usr/local/lib/antlr-4.7.1-complete.jar" org.antlr.v4.Tool'
grun='java org.antlr.v4.gui.TestRig'

mkdir -p tmp

echo "generating..."
java -Xmx500M -cp "/usr/local/lib/antlr-4.7.1-complete.jar" org.antlr.v4.Tool -o tmp Go2LLVMLexer.g4 Go2LLVMParser.g4

echo "compiling..."
javac tmp/*.java

echo "making tree"
cd tmp
java org.antlr.v4.gui.TestRig Go2LLVM sourceFile -gui ../test.go
