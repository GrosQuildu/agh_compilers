# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/gros/Informatics/hax/tools/others/clion-2016.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/gros/Informatics/hax/tools/others/clion-2016.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gros/studia/eaiib_3b/kompilatory/go_parser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gros/studia/eaiib_3b/kompilatory/go_parser/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/go_parser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/go_parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/go_parser.dir/flags.make

../generated/Go2LLVMLexer.cpp: ../Go2LLVMParser.g4
../generated/Go2LLVMLexer.cpp: ../Go2LLVMLexer.g4
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/gros/studia/eaiib_3b/kompilatory/go_parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../generated/Go2LLVMLexer.cpp, ../generated/Go2LLVMParser.cpp, ../generated/Go2LLVMParserBaseListener.cpp, ../generated/Go2LLVMParserBaseVisitor.cpp, ../generated/Go2LLVMParserListener.cpp, ../generated/Go2LLVMParserVisitor.cpp"
	/home/gros/Informatics/hax/tools/others/clion-2016.3.3/bin/cmake/bin/cmake -E make_directory /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/
	/usr/bin/java -jar /home/gros/studia/eaiib_3b/kompilatory/go_parser/antlr-4.7.1-complete.jar -Werror -Dlanguage=Cpp -listener -visitor -o /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/ -package go_parser /home/gros/studia/eaiib_3b/kompilatory/go_parser/Go2LLVMParser.g4 /home/gros/studia/eaiib_3b/kompilatory/go_parser/Go2LLVMLexer.g4

../generated/Go2LLVMParser.cpp: ../generated/Go2LLVMLexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ../generated/Go2LLVMParser.cpp

../generated/Go2LLVMParserBaseListener.cpp: ../generated/Go2LLVMLexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ../generated/Go2LLVMParserBaseListener.cpp

../generated/Go2LLVMParserBaseVisitor.cpp: ../generated/Go2LLVMLexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ../generated/Go2LLVMParserBaseVisitor.cpp

../generated/Go2LLVMParserListener.cpp: ../generated/Go2LLVMLexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ../generated/Go2LLVMParserListener.cpp

../generated/Go2LLVMParserVisitor.cpp: ../generated/Go2LLVMLexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate ../generated/Go2LLVMParserVisitor.cpp

CMakeFiles/go_parser.dir/src/go_parser.cpp.o: CMakeFiles/go_parser.dir/flags.make
CMakeFiles/go_parser.dir/src/go_parser.cpp.o: ../src/go_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gros/studia/eaiib_3b/kompilatory/go_parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/go_parser.dir/src/go_parser.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -o CMakeFiles/go_parser.dir/src/go_parser.cpp.o -c /home/gros/studia/eaiib_3b/kompilatory/go_parser/src/go_parser.cpp

CMakeFiles/go_parser.dir/src/go_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/go_parser.dir/src/go_parser.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -E /home/gros/studia/eaiib_3b/kompilatory/go_parser/src/go_parser.cpp > CMakeFiles/go_parser.dir/src/go_parser.cpp.i

CMakeFiles/go_parser.dir/src/go_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/go_parser.dir/src/go_parser.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -S /home/gros/studia/eaiib_3b/kompilatory/go_parser/src/go_parser.cpp -o CMakeFiles/go_parser.dir/src/go_parser.cpp.s

CMakeFiles/go_parser.dir/src/go_parser.cpp.o.requires:

.PHONY : CMakeFiles/go_parser.dir/src/go_parser.cpp.o.requires

CMakeFiles/go_parser.dir/src/go_parser.cpp.o.provides: CMakeFiles/go_parser.dir/src/go_parser.cpp.o.requires
	$(MAKE) -f CMakeFiles/go_parser.dir/build.make CMakeFiles/go_parser.dir/src/go_parser.cpp.o.provides.build
.PHONY : CMakeFiles/go_parser.dir/src/go_parser.cpp.o.provides

CMakeFiles/go_parser.dir/src/go_parser.cpp.o.provides.build: CMakeFiles/go_parser.dir/src/go_parser.cpp.o


CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.o: CMakeFiles/go_parser.dir/flags.make
CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.o: ../generated/Go2LLVMLexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gros/studia/eaiib_3b/kompilatory/go_parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -o CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.o -c /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMLexer.cpp

CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -E /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMLexer.cpp > CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.i

CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -S /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMLexer.cpp -o CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.s

CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.o.requires:

.PHONY : CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.o.requires

CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.o.provides: CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.o.requires
	$(MAKE) -f CMakeFiles/go_parser.dir/build.make CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.o.provides.build
.PHONY : CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.o.provides

CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.o.provides.build: CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.o


CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.o: CMakeFiles/go_parser.dir/flags.make
CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.o: ../generated/Go2LLVMParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gros/studia/eaiib_3b/kompilatory/go_parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -o CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.o -c /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMParser.cpp

CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -E /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMParser.cpp > CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.i

CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -S /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMParser.cpp -o CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.s

CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.o.requires:

.PHONY : CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.o.requires

CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.o.provides: CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/go_parser.dir/build.make CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.o.provides.build
.PHONY : CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.o.provides

CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.o.provides.build: CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.o


CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.o: CMakeFiles/go_parser.dir/flags.make
CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.o: ../generated/Go2LLVMParserBaseListener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gros/studia/eaiib_3b/kompilatory/go_parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -o CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.o -c /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMParserBaseListener.cpp

CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -E /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMParserBaseListener.cpp > CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.i

CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -S /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMParserBaseListener.cpp -o CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.s

CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.o.requires:

.PHONY : CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.o.requires

CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.o.provides: CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.o.requires
	$(MAKE) -f CMakeFiles/go_parser.dir/build.make CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.o.provides.build
.PHONY : CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.o.provides

CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.o.provides.build: CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.o


CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.o: CMakeFiles/go_parser.dir/flags.make
CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.o: ../generated/Go2LLVMParserBaseVisitor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gros/studia/eaiib_3b/kompilatory/go_parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -o CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.o -c /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMParserBaseVisitor.cpp

CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -E /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMParserBaseVisitor.cpp > CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.i

CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -S /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMParserBaseVisitor.cpp -o CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.s

CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.o.requires:

.PHONY : CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.o.requires

CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.o.provides: CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.o.requires
	$(MAKE) -f CMakeFiles/go_parser.dir/build.make CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.o.provides.build
.PHONY : CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.o.provides

CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.o.provides.build: CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.o


CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.o: CMakeFiles/go_parser.dir/flags.make
CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.o: ../generated/Go2LLVMParserListener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gros/studia/eaiib_3b/kompilatory/go_parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -o CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.o -c /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMParserListener.cpp

CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -E /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMParserListener.cpp > CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.i

CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -S /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMParserListener.cpp -o CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.s

CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.o.requires:

.PHONY : CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.o.requires

CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.o.provides: CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.o.requires
	$(MAKE) -f CMakeFiles/go_parser.dir/build.make CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.o.provides.build
.PHONY : CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.o.provides

CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.o.provides.build: CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.o


CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.o: CMakeFiles/go_parser.dir/flags.make
CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.o: ../generated/Go2LLVMParserVisitor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gros/studia/eaiib_3b/kompilatory/go_parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -o CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.o -c /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMParserVisitor.cpp

CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -E /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMParserVisitor.cpp > CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.i

CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS)  -Wno-overloaded-virtual -S /home/gros/studia/eaiib_3b/kompilatory/go_parser/generated/Go2LLVMParserVisitor.cpp -o CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.s

CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.o.requires:

.PHONY : CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.o.requires

CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.o.provides: CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.o.requires
	$(MAKE) -f CMakeFiles/go_parser.dir/build.make CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.o.provides.build
.PHONY : CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.o.provides

CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.o.provides.build: CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.o


# Object files for target go_parser
go_parser_OBJECTS = \
"CMakeFiles/go_parser.dir/src/go_parser.cpp.o" \
"CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.o" \
"CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.o" \
"CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.o" \
"CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.o" \
"CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.o" \
"CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.o"

# External object files for target go_parser
go_parser_EXTERNAL_OBJECTS =

go_parser: CMakeFiles/go_parser.dir/src/go_parser.cpp.o
go_parser: CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.o
go_parser: CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.o
go_parser: CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.o
go_parser: CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.o
go_parser: CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.o
go_parser: CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.o
go_parser: CMakeFiles/go_parser.dir/build.make
go_parser: ../antlr_runtime_unix/lib/libantlr4-runtime.a
go_parser: CMakeFiles/go_parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gros/studia/eaiib_3b/kompilatory/go_parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable go_parser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/go_parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/go_parser.dir/build: go_parser

.PHONY : CMakeFiles/go_parser.dir/build

CMakeFiles/go_parser.dir/requires: CMakeFiles/go_parser.dir/src/go_parser.cpp.o.requires
CMakeFiles/go_parser.dir/requires: CMakeFiles/go_parser.dir/generated/Go2LLVMLexer.cpp.o.requires
CMakeFiles/go_parser.dir/requires: CMakeFiles/go_parser.dir/generated/Go2LLVMParser.cpp.o.requires
CMakeFiles/go_parser.dir/requires: CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseListener.cpp.o.requires
CMakeFiles/go_parser.dir/requires: CMakeFiles/go_parser.dir/generated/Go2LLVMParserBaseVisitor.cpp.o.requires
CMakeFiles/go_parser.dir/requires: CMakeFiles/go_parser.dir/generated/Go2LLVMParserListener.cpp.o.requires
CMakeFiles/go_parser.dir/requires: CMakeFiles/go_parser.dir/generated/Go2LLVMParserVisitor.cpp.o.requires

.PHONY : CMakeFiles/go_parser.dir/requires

CMakeFiles/go_parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/go_parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/go_parser.dir/clean

CMakeFiles/go_parser.dir/depend: ../generated/Go2LLVMLexer.cpp
CMakeFiles/go_parser.dir/depend: ../generated/Go2LLVMParser.cpp
CMakeFiles/go_parser.dir/depend: ../generated/Go2LLVMParserBaseListener.cpp
CMakeFiles/go_parser.dir/depend: ../generated/Go2LLVMParserBaseVisitor.cpp
CMakeFiles/go_parser.dir/depend: ../generated/Go2LLVMParserListener.cpp
CMakeFiles/go_parser.dir/depend: ../generated/Go2LLVMParserVisitor.cpp
	cd /home/gros/studia/eaiib_3b/kompilatory/go_parser/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gros/studia/eaiib_3b/kompilatory/go_parser /home/gros/studia/eaiib_3b/kompilatory/go_parser /home/gros/studia/eaiib_3b/kompilatory/go_parser/cmake-build-debug /home/gros/studia/eaiib_3b/kompilatory/go_parser/cmake-build-debug /home/gros/studia/eaiib_3b/kompilatory/go_parser/cmake-build-debug/CMakeFiles/go_parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/go_parser.dir/depend

