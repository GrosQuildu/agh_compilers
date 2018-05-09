#!/bin/bash

export CLASSPATH=".:/usr/local/lib/antlr-4.7.1-complete.jar:$CLASSPATH"
antlr4='java -Xmx500M -cp "/usr/local/lib/antlr-4.7.1-complete.jar" org.antlr.v4.Tool'
grun='java org.antlr.v4.gui.TestRig'

if [[ $1 = "g" ]]; then
    rm -rf ./tmp_tree
    mkdir -p ./tmp_tree

    echo "generating..."
    java -Xmx500M -cp "/usr/local/lib/antlr-4.7.1-complete.jar" org.antlr.v4.Tool -o tmp_tree Go2LLVMLexer.g4 Go2LLVMParser.g4

    echo "compiling..."
    javac tmp_tree/*.java
fi

echo "making tree"
cd tmp_tree
java org.antlr.v4.gui.TestRig Go2LLVM sourceFile -gui ../test.go
