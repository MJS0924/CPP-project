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
include examples/CMakeFiles/11-audio.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/11-audio.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/11-audio.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/11-audio.dir/flags.make

examples/CMakeFiles/11-audio.dir/11-audio.cpp.o: examples/CMakeFiles/11-audio.dir/flags.make
examples/CMakeFiles/11-audio.dir/11-audio.cpp.o: ../examples/11-audio.cpp
examples/CMakeFiles/11-audio.dir/11-audio.cpp.o: examples/CMakeFiles/11-audio.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mjs/openai-cpp/CPP-project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/11-audio.dir/11-audio.cpp.o"
	cd /home/mjs/openai-cpp/CPP-project/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/CMakeFiles/11-audio.dir/11-audio.cpp.o -MF CMakeFiles/11-audio.dir/11-audio.cpp.o.d -o CMakeFiles/11-audio.dir/11-audio.cpp.o -c /home/mjs/openai-cpp/examples/11-audio.cpp

examples/CMakeFiles/11-audio.dir/11-audio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/11-audio.dir/11-audio.cpp.i"
	cd /home/mjs/openai-cpp/CPP-project/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mjs/openai-cpp/examples/11-audio.cpp > CMakeFiles/11-audio.dir/11-audio.cpp.i

examples/CMakeFiles/11-audio.dir/11-audio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/11-audio.dir/11-audio.cpp.s"
	cd /home/mjs/openai-cpp/CPP-project/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mjs/openai-cpp/examples/11-audio.cpp -o CMakeFiles/11-audio.dir/11-audio.cpp.s

# Object files for target 11-audio
11__audio_OBJECTS = \
"CMakeFiles/11-audio.dir/11-audio.cpp.o"

# External object files for target 11-audio
11__audio_EXTERNAL_OBJECTS =

examples/11-audio: examples/CMakeFiles/11-audio.dir/11-audio.cpp.o
examples/11-audio: examples/CMakeFiles/11-audio.dir/build.make
examples/11-audio: /usr/lib/x86_64-linux-gnu/libcurl.so
examples/11-audio: examples/CMakeFiles/11-audio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mjs/openai-cpp/CPP-project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 11-audio"
	cd /home/mjs/openai-cpp/CPP-project/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/11-audio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/11-audio.dir/build: examples/11-audio
.PHONY : examples/CMakeFiles/11-audio.dir/build

examples/CMakeFiles/11-audio.dir/clean:
	cd /home/mjs/openai-cpp/CPP-project/examples && $(CMAKE_COMMAND) -P CMakeFiles/11-audio.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/11-audio.dir/clean

examples/CMakeFiles/11-audio.dir/depend:
	cd /home/mjs/openai-cpp/CPP-project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mjs/openai-cpp /home/mjs/openai-cpp/examples /home/mjs/openai-cpp/CPP-project /home/mjs/openai-cpp/CPP-project/examples /home/mjs/openai-cpp/CPP-project/examples/CMakeFiles/11-audio.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/11-audio.dir/depend

