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
CMAKE_SOURCE_DIR = /home/frarese/Documenti/Algo/week11/goldeneye

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/frarese/Documenti/Algo/week11/goldeneye

# Include any dependencies generated for this target.
include CMakeFiles/eye.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/eye.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/eye.dir/flags.make

CMakeFiles/eye.dir/eye.cpp.o: CMakeFiles/eye.dir/flags.make
CMakeFiles/eye.dir/eye.cpp.o: eye.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frarese/Documenti/Algo/week11/goldeneye/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/eye.dir/eye.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/eye.dir/eye.cpp.o -c /home/frarese/Documenti/Algo/week11/goldeneye/eye.cpp

CMakeFiles/eye.dir/eye.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/eye.dir/eye.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frarese/Documenti/Algo/week11/goldeneye/eye.cpp > CMakeFiles/eye.dir/eye.cpp.i

CMakeFiles/eye.dir/eye.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/eye.dir/eye.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frarese/Documenti/Algo/week11/goldeneye/eye.cpp -o CMakeFiles/eye.dir/eye.cpp.s

# Object files for target eye
eye_OBJECTS = \
"CMakeFiles/eye.dir/eye.cpp.o"

# External object files for target eye
eye_EXTERNAL_OBJECTS =

eye: CMakeFiles/eye.dir/eye.cpp.o
eye: CMakeFiles/eye.dir/build.make
eye: /usr/lib/libCGAL_Core.so.13.0.3
eye: /usr/lib/libCGAL.so.13.0.3
eye: /usr/lib/libmpfr.so
eye: /usr/lib/libgmp.so
eye: /usr/lib64/libboost_thread.so.1.71.0
eye: CMakeFiles/eye.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/frarese/Documenti/Algo/week11/goldeneye/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable eye"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/eye.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/eye.dir/build: eye

.PHONY : CMakeFiles/eye.dir/build

CMakeFiles/eye.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/eye.dir/cmake_clean.cmake
.PHONY : CMakeFiles/eye.dir/clean

CMakeFiles/eye.dir/depend:
	cd /home/frarese/Documenti/Algo/week11/goldeneye && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/frarese/Documenti/Algo/week11/goldeneye /home/frarese/Documenti/Algo/week11/goldeneye /home/frarese/Documenti/Algo/week11/goldeneye /home/frarese/Documenti/Algo/week11/goldeneye /home/frarese/Documenti/Algo/week11/goldeneye/CMakeFiles/eye.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/eye.dir/depend

