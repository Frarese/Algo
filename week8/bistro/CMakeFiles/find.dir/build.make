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
CMAKE_SOURCE_DIR = /home/frarese/Documenti/Algo/week8/bistro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/frarese/Documenti/Algo/week8/bistro

# Include any dependencies generated for this target.
include CMakeFiles/find.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/find.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/find.dir/flags.make

CMakeFiles/find.dir/find.cpp.o: CMakeFiles/find.dir/flags.make
CMakeFiles/find.dir/find.cpp.o: find.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frarese/Documenti/Algo/week8/bistro/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/find.dir/find.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/find.dir/find.cpp.o -c /home/frarese/Documenti/Algo/week8/bistro/find.cpp

CMakeFiles/find.dir/find.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/find.dir/find.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frarese/Documenti/Algo/week8/bistro/find.cpp > CMakeFiles/find.dir/find.cpp.i

CMakeFiles/find.dir/find.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/find.dir/find.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frarese/Documenti/Algo/week8/bistro/find.cpp -o CMakeFiles/find.dir/find.cpp.s

# Object files for target find
find_OBJECTS = \
"CMakeFiles/find.dir/find.cpp.o"

# External object files for target find
find_EXTERNAL_OBJECTS =

find: CMakeFiles/find.dir/find.cpp.o
find: CMakeFiles/find.dir/build.make
find: /usr/lib/libCGAL.so.13.0.3
find: /usr/lib/libmpfr.so
find: /usr/lib/libgmp.so
find: CMakeFiles/find.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/frarese/Documenti/Algo/week8/bistro/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable find"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/find.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/find.dir/build: find

.PHONY : CMakeFiles/find.dir/build

CMakeFiles/find.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/find.dir/cmake_clean.cmake
.PHONY : CMakeFiles/find.dir/clean

CMakeFiles/find.dir/depend:
	cd /home/frarese/Documenti/Algo/week8/bistro && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/frarese/Documenti/Algo/week8/bistro /home/frarese/Documenti/Algo/week8/bistro /home/frarese/Documenti/Algo/week8/bistro /home/frarese/Documenti/Algo/week8/bistro /home/frarese/Documenti/Algo/week8/bistro/CMakeFiles/find.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/find.dir/depend

