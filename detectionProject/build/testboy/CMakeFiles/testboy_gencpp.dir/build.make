# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pp/detectionProject/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pp/detectionProject/build

# Utility rule file for testboy_gencpp.

# Include the progress variables for this target.
include testboy/CMakeFiles/testboy_gencpp.dir/progress.make

testboy_gencpp: testboy/CMakeFiles/testboy_gencpp.dir/build.make

.PHONY : testboy_gencpp

# Rule to build all files generated by this target.
testboy/CMakeFiles/testboy_gencpp.dir/build: testboy_gencpp

.PHONY : testboy/CMakeFiles/testboy_gencpp.dir/build

testboy/CMakeFiles/testboy_gencpp.dir/clean:
	cd /home/pp/detectionProject/build/testboy && $(CMAKE_COMMAND) -P CMakeFiles/testboy_gencpp.dir/cmake_clean.cmake
.PHONY : testboy/CMakeFiles/testboy_gencpp.dir/clean

testboy/CMakeFiles/testboy_gencpp.dir/depend:
	cd /home/pp/detectionProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pp/detectionProject/src /home/pp/detectionProject/src/testboy /home/pp/detectionProject/build /home/pp/detectionProject/build/testboy /home/pp/detectionProject/build/testboy/CMakeFiles/testboy_gencpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : testboy/CMakeFiles/testboy_gencpp.dir/depend

