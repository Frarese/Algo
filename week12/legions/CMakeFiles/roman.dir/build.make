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
CMAKE_SOURCE_DIR = /home/frarese/Documenti/Algo/week12/legions

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/frarese/Documenti/Algo/week12/legions

# Include any dependencies generated for this target.
include CMakeFiles/roman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/roman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/roman.dir/flags.make

CMakeFiles/roman.dir/roman.cpp.o: CMakeFiles/roman.dir/flags.make
CMakeFiles/roman.dir/roman.cpp.o: roman.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/frarese/Documenti/Algo/week12/legions/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/roman.dir/roman.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roman.dir/roman.cpp.o -c /home/frarese/Documenti/Algo/week12/legions/roman.cpp

CMakeFiles/roman.dir/roman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roman.dir/roman.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/frarese/Documenti/Algo/week12/legions/roman.cpp > CMakeFiles/roman.dir/roman.cpp.i

CMakeFiles/roman.dir/roman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roman.dir/roman.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/frarese/Documenti/Algo/week12/legions/roman.cpp -o CMakeFiles/roman.dir/roman.cpp.s

# Object files for target roman
roman_OBJECTS = \
"CMakeFiles/roman.dir/roman.cpp.o"

# External object files for target roman
roman_EXTERNAL_OBJECTS =

roman: CMakeFiles/roman.dir/roman.cpp.o
roman: CMakeFiles/roman.dir/build.make
roman: /usr/lib/libCGAL_Core.so.13.0.3
roman: /usr/lib/libCGAL.so.13.0.3
roman: /usr/lib/libmpfr.so
roman: /usr/lib/libgmp.so
roman: /usr/lib64/libboost_thread.so.1.71.0
roman: CMakeFiles/roman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/frarese/Documenti/Algo/week12/legions/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable roman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/roman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/roman.dir/build: roman

.PHONY : CMakeFiles/roman.dir/build

CMakeFiles/roman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/roman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/roman.dir/clean

CMakeFiles/roman.dir/depend:
	cd /home/frarese/Documenti/Algo/week12/legions && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/frarese/Documenti/Algo/week12/legions /home/frarese/Documenti/Algo/week12/legions /home/frarese/Documenti/Algo/week12/legions /home/frarese/Documenti/Algo/week12/legions /home/frarese/Documenti/Algo/week12/legions/CMakeFiles/roman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/roman.dir/depend

