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
CMAKE_SOURCE_DIR = /home/frarese/Documenti/Algo/week3/antenna

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/frarese/Documenti/Algo/week3/antenna

# Include any dependencies generated for this target.
include CMakeFiles/antenna.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/antenna.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/antenna.dir/flags.make

CMakeFiles/antenna.dir/antenna.cpp.o: CMakeFiles/antenna.dir/flags.make
CMakeFiles/antenna.dir/antenna.cpp.o: antenna.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frarese/Documenti/Algo/week3/antenna/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/antenna.dir/antenna.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/antenna.dir/antenna.cpp.o -c /home/frarese/Documenti/Algo/week3/antenna/antenna.cpp

CMakeFiles/antenna.dir/antenna.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/antenna.dir/antenna.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frarese/Documenti/Algo/week3/antenna/antenna.cpp > CMakeFiles/antenna.dir/antenna.cpp.i

CMakeFiles/antenna.dir/antenna.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/antenna.dir/antenna.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frarese/Documenti/Algo/week3/antenna/antenna.cpp -o CMakeFiles/antenna.dir/antenna.cpp.s

# Object files for target antenna
antenna_OBJECTS = \
"CMakeFiles/antenna.dir/antenna.cpp.o"

# External object files for target antenna
antenna_EXTERNAL_OBJECTS =

antenna: CMakeFiles/antenna.dir/antenna.cpp.o
antenna: CMakeFiles/antenna.dir/build.make
antenna: /usr/lib/libCGAL.so.13.0.3
antenna: /usr/lib/libmpfr.so
antenna: /usr/lib/libgmp.so
antenna: CMakeFiles/antenna.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/frarese/Documenti/Algo/week3/antenna/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable antenna"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/antenna.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/antenna.dir/build: antenna

.PHONY : CMakeFiles/antenna.dir/build

CMakeFiles/antenna.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/antenna.dir/cmake_clean.cmake
.PHONY : CMakeFiles/antenna.dir/clean

CMakeFiles/antenna.dir/depend:
	cd /home/frarese/Documenti/Algo/week3/antenna && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/frarese/Documenti/Algo/week3/antenna /home/frarese/Documenti/Algo/week3/antenna /home/frarese/Documenti/Algo/week3/antenna /home/frarese/Documenti/Algo/week3/antenna /home/frarese/Documenti/Algo/week3/antenna/CMakeFiles/antenna.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/antenna.dir/depend

