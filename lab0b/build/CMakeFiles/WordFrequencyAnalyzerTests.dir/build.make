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
CMAKE_SOURCE_DIR = /home/ivan/oopProjects/lab0b

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivan/oopProjects/lab0b/build

# Include any dependencies generated for this target.
include CMakeFiles/WordFrequencyAnalyzerTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/WordFrequencyAnalyzerTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/WordFrequencyAnalyzerTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WordFrequencyAnalyzerTests.dir/flags.make

CMakeFiles/WordFrequencyAnalyzerTests.dir/tests/test_main.cpp.o: CMakeFiles/WordFrequencyAnalyzerTests.dir/flags.make
CMakeFiles/WordFrequencyAnalyzerTests.dir/tests/test_main.cpp.o: ../tests/test_main.cpp
CMakeFiles/WordFrequencyAnalyzerTests.dir/tests/test_main.cpp.o: CMakeFiles/WordFrequencyAnalyzerTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/oopProjects/lab0b/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WordFrequencyAnalyzerTests.dir/tests/test_main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WordFrequencyAnalyzerTests.dir/tests/test_main.cpp.o -MF CMakeFiles/WordFrequencyAnalyzerTests.dir/tests/test_main.cpp.o.d -o CMakeFiles/WordFrequencyAnalyzerTests.dir/tests/test_main.cpp.o -c /home/ivan/oopProjects/lab0b/tests/test_main.cpp

CMakeFiles/WordFrequencyAnalyzerTests.dir/tests/test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WordFrequencyAnalyzerTests.dir/tests/test_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/oopProjects/lab0b/tests/test_main.cpp > CMakeFiles/WordFrequencyAnalyzerTests.dir/tests/test_main.cpp.i

CMakeFiles/WordFrequencyAnalyzerTests.dir/tests/test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WordFrequencyAnalyzerTests.dir/tests/test_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/oopProjects/lab0b/tests/test_main.cpp -o CMakeFiles/WordFrequencyAnalyzerTests.dir/tests/test_main.cpp.s

# Object files for target WordFrequencyAnalyzerTests
WordFrequencyAnalyzerTests_OBJECTS = \
"CMakeFiles/WordFrequencyAnalyzerTests.dir/tests/test_main.cpp.o"

# External object files for target WordFrequencyAnalyzerTests
WordFrequencyAnalyzerTests_EXTERNAL_OBJECTS =

WordFrequencyAnalyzerTests: CMakeFiles/WordFrequencyAnalyzerTests.dir/tests/test_main.cpp.o
WordFrequencyAnalyzerTests: CMakeFiles/WordFrequencyAnalyzerTests.dir/build.make
WordFrequencyAnalyzerTests: libWordFrequencyAnalyzerLib.a
WordFrequencyAnalyzerTests: /usr/lib/x86_64-linux-gnu/libgtest_main.a
WordFrequencyAnalyzerTests: /usr/lib/x86_64-linux-gnu/libgtest.a
WordFrequencyAnalyzerTests: CMakeFiles/WordFrequencyAnalyzerTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivan/oopProjects/lab0b/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable WordFrequencyAnalyzerTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WordFrequencyAnalyzerTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WordFrequencyAnalyzerTests.dir/build: WordFrequencyAnalyzerTests
.PHONY : CMakeFiles/WordFrequencyAnalyzerTests.dir/build

CMakeFiles/WordFrequencyAnalyzerTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WordFrequencyAnalyzerTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WordFrequencyAnalyzerTests.dir/clean

CMakeFiles/WordFrequencyAnalyzerTests.dir/depend:
	cd /home/ivan/oopProjects/lab0b/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivan/oopProjects/lab0b /home/ivan/oopProjects/lab0b /home/ivan/oopProjects/lab0b/build /home/ivan/oopProjects/lab0b/build /home/ivan/oopProjects/lab0b/build/CMakeFiles/WordFrequencyAnalyzerTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WordFrequencyAnalyzerTests.dir/depend

