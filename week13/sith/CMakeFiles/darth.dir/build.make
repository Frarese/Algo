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
CMAKE_SOURCE_DIR = /home/frarese/Documenti/Algo/week13/sith

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/frarese/Documenti/Algo/week13/sith

# Include any dependencies generated for this target.
include CMakeFiles/darth.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/darth.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/darth.dir/flags.make

CMakeFiles/darth.dir/darth.cpp.o: CMakeFiles/darth.dir/flags.make
CMakeFiles/darth.dir/darth.cpp.o: darth.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frarese/Documenti/Algo/week13/sith/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/darth.dir/darth.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/darth.dir/darth.cpp.o -c /home/frarese/Documenti/Algo/week13/sith/darth.cpp

CMakeFiles/darth.dir/darth.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/darth.dir/darth.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frarese/Documenti/Algo/week13/sith/darth.cpp > CMakeFiles/darth.dir/darth.cpp.i

CMakeFiles/darth.dir/darth.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/darth.dir/darth.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frarese/Documenti/Algo/week13/sith/darth.cpp -o CMakeFiles/darth.dir/darth.cpp.s

# Object files for target darth
darth_OBJECTS = \
"CMakeFiles/darth.dir/darth.cpp.o"

# External object files for target darth
darth_EXTERNAL_OBJECTS =

darth: CMakeFiles/darth.dir/darth.cpp.o
darth: CMakeFiles/darth.dir/build.make
darth: /usr/lib/libCGAL_Core.so.13.0.3
darth: /usr/lib/libCGAL.so.13.0.3
darth: /usr/lib/libmpfr.so
darth: /usr/lib/libgmp.so
darth: /usr/lib64/libboost_thread.so.1.71.0
darth: CMakeFiles/darth.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/frarese/Documenti/Algo/week13/sith/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable darth"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/darth.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/darth.dir/build: darth

.PHONY : CMakeFiles/darth.dir/build

CMakeFiles/darth.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/darth.dir/cmake_clean.cmake
.PHONY : CMakeFiles/darth.dir/clean

CMakeFiles/darth.dir/depend:
	cd /home/frarese/Documenti/Algo/week13/sith && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/frarese/Documenti/Algo/week13/sith /home/frarese/Documenti/Algo/week13/sith /home/frarese/Documenti/Algo/week13/sith /home/frarese/Documenti/Algo/week13/sith /home/frarese/Documenti/Algo/week13/sith/CMakeFiles/darth.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/darth.dir/depend

