# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/freudmaster/CLionProjects/TP.IoT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug

# Include any dependencies generated for this target.
include _deps/json-build/test/CMakeFiles/test-class_lexer.dir/depend.make

# Include the progress variables for this target.
include _deps/json-build/test/CMakeFiles/test-class_lexer.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/json-build/test/CMakeFiles/test-class_lexer.dir/flags.make

_deps/json-build/test/CMakeFiles/test-class_lexer.dir/src/unit-class_lexer.cpp.o: _deps/json-build/test/CMakeFiles/test-class_lexer.dir/flags.make
_deps/json-build/test/CMakeFiles/test-class_lexer.dir/src/unit-class_lexer.cpp.o: _deps/json-src/test/src/unit-class_lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/json-build/test/CMakeFiles/test-class_lexer.dir/src/unit-class_lexer.cpp.o"
	cd /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-build/test && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-class_lexer.dir/src/unit-class_lexer.cpp.o -c /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-src/test/src/unit-class_lexer.cpp

_deps/json-build/test/CMakeFiles/test-class_lexer.dir/src/unit-class_lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-class_lexer.dir/src/unit-class_lexer.cpp.i"
	cd /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-src/test/src/unit-class_lexer.cpp > CMakeFiles/test-class_lexer.dir/src/unit-class_lexer.cpp.i

_deps/json-build/test/CMakeFiles/test-class_lexer.dir/src/unit-class_lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-class_lexer.dir/src/unit-class_lexer.cpp.s"
	cd /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-src/test/src/unit-class_lexer.cpp -o CMakeFiles/test-class_lexer.dir/src/unit-class_lexer.cpp.s

# Object files for target test-class_lexer
test__class_lexer_OBJECTS = \
"CMakeFiles/test-class_lexer.dir/src/unit-class_lexer.cpp.o"

# External object files for target test-class_lexer
test__class_lexer_EXTERNAL_OBJECTS = \
"/Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-build/test/CMakeFiles/doctest_main.dir/src/unit.cpp.o"

_deps/json-build/test/test-class_lexer: _deps/json-build/test/CMakeFiles/test-class_lexer.dir/src/unit-class_lexer.cpp.o
_deps/json-build/test/test-class_lexer: _deps/json-build/test/CMakeFiles/doctest_main.dir/src/unit.cpp.o
_deps/json-build/test/test-class_lexer: _deps/json-build/test/CMakeFiles/test-class_lexer.dir/build.make
_deps/json-build/test/test-class_lexer: _deps/json-build/test/CMakeFiles/test-class_lexer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-class_lexer"
	cd /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-class_lexer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/json-build/test/CMakeFiles/test-class_lexer.dir/build: _deps/json-build/test/test-class_lexer

.PHONY : _deps/json-build/test/CMakeFiles/test-class_lexer.dir/build

_deps/json-build/test/CMakeFiles/test-class_lexer.dir/clean:
	cd /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-build/test && $(CMAKE_COMMAND) -P CMakeFiles/test-class_lexer.dir/cmake_clean.cmake
.PHONY : _deps/json-build/test/CMakeFiles/test-class_lexer.dir/clean

_deps/json-build/test/CMakeFiles/test-class_lexer.dir/depend:
	cd /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/freudmaster/CLionProjects/TP.IoT /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-src/test /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-build/test /Users/freudmaster/CLionProjects/TP.IoT/cmake-build-debug/_deps/json-build/test/CMakeFiles/test-class_lexer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/json-build/test/CMakeFiles/test-class_lexer.dir/depend

