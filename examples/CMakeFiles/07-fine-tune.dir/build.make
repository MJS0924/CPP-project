# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mjs/openai-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mjs/openai-cpp/CPP-project

# Include any dependencies generated for this target.
include examples/CMakeFiles/07-fine-tune.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/07-fine-tune.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/07-fine-tune.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/07-fine-tune.dir/flags.make

examples/CMakeFiles/07-fine-tune.dir/07-fine-tune.cpp.o: examples/CMakeFiles/07-fine-tune.dir/flags.make
examples/CMakeFiles/07-fine-tune.dir/07-fine-tune.cpp.o: ../examples/07-fine-tune.cpp
examples/CMakeFiles/07-fine-tune.dir/07-fine-tune.cpp.o: examples/CMakeFiles/07-fine-tune.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mjs/openai-cpp/CPP-project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/07-fine-tune.dir/07-fine-tune.cpp.o"
	cd /home/mjs/openai-cpp/CPP-project/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/CMakeFiles/07-fine-tune.dir/07-fine-tune.cpp.o -MF CMakeFiles/07-fine-tune.dir/07-fine-tune.cpp.o.d -o CMakeFiles/07-fine-tune.dir/07-fine-tune.cpp.o -c /home/mjs/openai-cpp/examples/07-fine-tune.cpp

examples/CMakeFiles/07-fine-tune.dir/07-fine-tune.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/07-fine-tune.dir/07-fine-tune.cpp.i"
	cd /home/mjs/openai-cpp/CPP-project/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mjs/openai-cpp/examples/07-fine-tune.cpp > CMakeFiles/07-fine-tune.dir/07-fine-tune.cpp.i

examples/CMakeFiles/07-fine-tune.dir/07-fine-tune.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/07-fine-tune.dir/07-fine-tune.cpp.s"
	cd /home/mjs/openai-cpp/CPP-project/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mjs/openai-cpp/examples/07-fine-tune.cpp -o CMakeFiles/07-fine-tune.dir/07-fine-tune.cpp.s

# Object files for target 07-fine-tune
07__fine__tune_OBJECTS = \
"CMakeFiles/07-fine-tune.dir/07-fine-tune.cpp.o"

# External object files for target 07-fine-tune
07__fine__tune_EXTERNAL_OBJECTS =

examples/07-fine-tune: examples/CMakeFiles/07-fine-tune.dir/07-fine-tune.cpp.o
examples/07-fine-tune: examples/CMakeFiles/07-fine-tune.dir/build.make
examples/07-fine-tune: /usr/lib/x86_64-linux-gnu/libcurl.so
examples/07-fine-tune: examples/CMakeFiles/07-fine-tune.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mjs/openai-cpp/CPP-project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 07-fine-tune"
	cd /home/mjs/openai-cpp/CPP-project/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/07-fine-tune.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/07-fine-tune.dir/build: examples/07-fine-tune
.PHONY : examples/CMakeFiles/07-fine-tune.dir/build

examples/CMakeFiles/07-fine-tune.dir/clean:
	cd /home/mjs/openai-cpp/CPP-project/examples && $(CMAKE_COMMAND) -P CMakeFiles/07-fine-tune.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/07-fine-tune.dir/clean

examples/CMakeFiles/07-fine-tune.dir/depend:
	cd /home/mjs/openai-cpp/CPP-project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mjs/openai-cpp /home/mjs/openai-cpp/examples /home/mjs/openai-cpp/CPP-project /home/mjs/openai-cpp/CPP-project/examples /home/mjs/openai-cpp/CPP-project/examples/CMakeFiles/07-fine-tune.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/07-fine-tune.dir/depend

