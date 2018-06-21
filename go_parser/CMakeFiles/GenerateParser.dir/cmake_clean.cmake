file(REMOVE_RECURSE
  "CMakeFiles/GenerateParser"
  "src/generated/Go2LLVMLexer.cpp"
  "src/generated/Go2LLVMParser.cpp"
  "src/generated/Go2LLVMBaseListener.cpp"
  "src/generated/Go2LLVMBaseVisitor.cpp"
  "src/generated/Go2LLVMListener.cpp"
  "src/generated/Go2LLVMVisitor.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/GenerateParser.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
