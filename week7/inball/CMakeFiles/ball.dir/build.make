# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /home/frarese/Documenti/Algo/week7/inball

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/frarese/Documenti/Algo/week7/inball

# Include any dependencies generated for this target.
include CMakeFiles/ball.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ball.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ball.dir/flags.make

CMakeFiles/ball.dir/ball.cpp.o: CMakeFiles/ball.dir/flags.make
CMakeFiles/ball.dir/ball.cpp.o: ball.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frarese/Documenti/Algo/week7/inball/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ball.dir/ball.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ball.dir/ball.cpp.o -c /home/frarese/Documenti/Algo/week7/inball/ball.cpp

CMakeFiles/ball.dir/ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ball.dir/ball.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frarese/Documenti/Algo/week7/inball/ball.cpp > CMakeFiles/ball.dir/ball.cpp.i

CMakeFiles/ball.dir/ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ball.dir/ball.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frarese/Documenti/Algo/week7/inball/ball.cpp -o CMakeFiles/ball.dir/ball.cpp.s

# Object files for target ball
ball_OBJECTS = \
"CMakeFiles/ball.dir/ball.cpp.o"

# External object files for target ball
ball_EXTERNAL_OBJECTS =

ball: CMakeFiles/ball.dir/ball.cpp.o
ball: CMakeFiles/ball.dir/build.make
ball: /usr/lib/libCGAL.so.13.0.3
ball: /usr/lib/libmpfr.so
ball: /usr/lib/libgmp.so
ball: CMakeFiles/ball.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/frarese/Documenti/Algo/week7/inball/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ball"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ball.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ball.dir/build: ball

.PHONY : CMakeFiles/ball.dir/build

CMakeFiles/ball.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ball.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ball.dir/clean

CMakeFiles/ball.dir/depend:
	cd /home/frarese/Documenti/Algo/week7/inball && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/frarese/Documenti/Algo/week7/inball /home/frarese/Documenti/Algo/week7/inball /home/frarese/Documenti/Algo/week7/inball /home/frarese/Documenti/Algo/week7/inball /home/frarese/Documenti/Algo/week7/inball/CMakeFiles/ball.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ball.dir/depend

