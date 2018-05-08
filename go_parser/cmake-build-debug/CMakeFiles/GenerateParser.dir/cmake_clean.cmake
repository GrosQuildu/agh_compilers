file(REMOVE_RECURSE
  "CMakeFiles/GenerateParser"
  "../generated/Go2LLVMLexer.cpp"
  "../generated/Go2LLVMParser.cpp"
  "../generated/Go2LLVMParserBaseListener.cpp"
  "../generated/Go2LLVMParserBaseVisitor.cpp"
  "../generated/Go2LLVMParserListener.cpp"
  "../generated/Go2LLVMParserVisitor.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/GenerateParser.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
