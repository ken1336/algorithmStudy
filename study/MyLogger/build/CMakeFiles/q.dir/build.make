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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/min/Desktop/cpp/study/algorithm/study/MyLogger

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/min/Desktop/cpp/study/algorithm/study/MyLogger/build

# Include any dependencies generated for this target.
include CMakeFiles/q.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/q.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/q.dir/flags.make

CMakeFiles/q.dir/main.o: CMakeFiles/q.dir/flags.make
CMakeFiles/q.dir/main.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/min/Desktop/cpp/study/algorithm/study/MyLogger/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/q.dir/main.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/q.dir/main.o -c /Users/min/Desktop/cpp/study/algorithm/study/MyLogger/main.cpp

CMakeFiles/q.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/q.dir/main.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/min/Desktop/cpp/study/algorithm/study/MyLogger/main.cpp > CMakeFiles/q.dir/main.i

CMakeFiles/q.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/q.dir/main.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/min/Desktop/cpp/study/algorithm/study/MyLogger/main.cpp -o CMakeFiles/q.dir/main.s

# Object files for target q
q_OBJECTS = \
"CMakeFiles/q.dir/main.o"

# External object files for target q
q_EXTERNAL_OBJECTS =

q : CMakeFiles/q.dir/main.o
q : CMakeFiles/q.dir/build.make
q : CMakeFiles/q.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/min/Desktop/cpp/study/algorithm/study/MyLogger/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable q"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/q.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/q.dir/build: q

.PHONY : CMakeFiles/q.dir/build

CMakeFiles/q.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/q.dir/cmake_clean.cmake
.PHONY : CMakeFiles/q.dir/clean

CMakeFiles/q.dir/depend:
	cd /Users/min/Desktop/cpp/study/algorithm/study/MyLogger/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/min/Desktop/cpp/study/algorithm/study/MyLogger /Users/min/Desktop/cpp/study/algorithm/study/MyLogger /Users/min/Desktop/cpp/study/algorithm/study/MyLogger/build /Users/min/Desktop/cpp/study/algorithm/study/MyLogger/build /Users/min/Desktop/cpp/study/algorithm/study/MyLogger/build/CMakeFiles/q.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/q.dir/depend

