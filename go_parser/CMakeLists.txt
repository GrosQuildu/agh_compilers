if(NOT UNIX)
    message(WARNING "Unsupported operating system")
endif()

cmake_minimum_required(VERSION 2.8.4)
project(go_parser)

# config stuff
set(Java_JAVA_EXECUTABLE /usr/bin/java)
set(ANTLR_JAR_LOCATION /home/gros/studia/eaiib_3b/kompilatory/go_parser/antlr-4.7.1-complete.jar)


# antlr stuff
set(go_parser-GENERATED_SRC
        ${PROJECT_SOURCE_DIR}/src/generated/Go2LLVMLexer.cpp
        ${PROJECT_SOURCE_DIR}/src/generated/Go2LLVMParser.cpp
        ${PROJECT_SOURCE_DIR}/src/generated/Go2LLVMBaseListener.cpp
        ${PROJECT_SOURCE_DIR}/src/generated/Go2LLVMBaseVisitor.cpp
        ${PROJECT_SOURCE_DIR}/src/generated/Go2LLVMListener.cpp
        ${PROJECT_SOURCE_DIR}/src/generated/Go2LLVMVisitor.cpp
)

foreach( src_file ${go_parser-GENERATED_SRC} )
    set_source_files_properties(
            ${src_file}
            PROPERTIES
            GENERATED TRUE
    )
endforeach( src_file ${go_parser-GENERATED_SRC} )

add_custom_target(GenerateParser DEPENDS ${go_parser-GENERATED_SRC})
add_custom_command(OUTPUT ${go_parser-GENERATED_SRC}
        COMMAND
        ${CMAKE_COMMAND} -E make_directory src/generated/
        COMMAND
        "${Java_JAVA_EXECUTABLE}" -jar ${ANTLR_JAR_LOCATION} -Werror -Dlanguage=Cpp -listener -visitor -o src/generated/ -package go_parser ${PROJECT_SOURCE_DIR}/Go2LLVM.g4
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
        DEPENDS ${PROJECT_SOURCE_DIR}/Go2LLVM.g4
        )

include_directories(
        ${PROJECT_SOURCE_DIR}/antlr_runtime_unix/include/antlr4-runtime
        ${PROJECT_SOURCE_DIR}/antlr_runtime_unix/include/antlr4-runtime/misc
        ${PROJECT_SOURCE_DIR}/antlr_runtime_unix/include/antlr4-runtime/atn
        ${PROJECT_SOURCE_DIR}/antlr_runtime_unix/include/antlr4-runtime/dfa
        ${PROJECT_SOURCE_DIR}/antlr_runtime_unix/include/antlr4-runtime/tree
        ${PROJECT_SOURCE_DIR}/antlr_runtime_unix/include/antlr4-runtime/support
        src/generated
)

# llvm stuff
find_package(LLVM "6.0.1" REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(llvm_libs support core irreader)


# main project stuff
set(go_parser-SRC
        ${PROJECT_SOURCE_DIR}/src/go_parser.cpp
        ${PROJECT_SOURCE_DIR}/src/Helpers.cpp
        ${PROJECT_SOURCE_DIR}/src/visitors/Go2LLVMMyVisitor.cpp
        ${PROJECT_SOURCE_DIR}/src/exceptions/Go2LLVMError.cpp
        ${PROJECT_SOURCE_DIR}/src/exceptions/Go2LLVMWarning.cpp
        ${PROJECT_SOURCE_DIR}/src/visitors/VisitorTopLevel.cpp
        ${PROJECT_SOURCE_DIR}/src/visitors/VisitorStatement.cpp
        ${PROJECT_SOURCE_DIR}/src/visitors/VisitorDeclaration.cpp
        ${PROJECT_SOURCE_DIR}/src/visitors/VisitorExpression.cpp
        ${PROJECT_SOURCE_DIR}/src/visitors/VisitorOperand.cpp
        ${PROJECT_SOURCE_DIR}/src/visitors/VisitorFunction.cpp
        ${PROJECT_SOURCE_DIR}/src/variables/BasicVar.cpp
        ${PROJECT_SOURCE_DIR}/src/variables/IntegerVar.cpp
        ${PROJECT_SOURCE_DIR}/src/variables/FloatVar.cpp
        ${PROJECT_SOURCE_DIR}/src/variables/VarFactory.cpp
        ${PROJECT_SOURCE_DIR}/src/variables/PointerVar.cpp
        ${PROJECT_SOURCE_DIR}/src/variables/VoidVar.cpp
        ${PROJECT_SOURCE_DIR}/src/variables/BoolVar.cpp
        ${go_parser-GENERATED_SRC}
)

if (NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set (flags_1 "-Wno-overloaded-virtual")
else()
    set (flags_1 "-MP /wd4251")
endif()

foreach( src_file ${go_parser-SRC} )
    set_source_files_properties(
            ${src_file}
            PROPERTIES
            COMPILE_FLAGS "${COMPILE_FLAGS} ${flags_1}"
    )
endforeach( src_file ${go_parser-SRC} )

add_executable(go_parser ${go_parser-SRC})
#add_precompiled_header(go_parser ${PROJECT_SOURCE_DIR}/antlr_runtime_unix/src/antlrcpp-Prefix.h)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options(go_parser PRIVATE "/MT$<$<CONFIG:Debug>:d>")
endif()

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -DDEBUG=0")
add_dependencies(go_parser GenerateParser)
target_link_libraries(go_parser ${llvm_libs} ${PROJECT_SOURCE_DIR}/antlr_runtime_unix/lib/libantlr4-runtime.a)


# testing
#add_executable(testing ${PROJECT_SOURCE_DIR}/testing/testing.cpp)
#target_link_libraries(testing ${llvm_libs})