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
CMAKE_SOURCE_DIR = /mnt/nfs/homes/anclarma/rushes/wordle/rush

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/nfs/homes/anclarma/rushes/wordle/rush

# Include any dependencies generated for this target.
include libwordle/CMakeFiles/wordle.dir/depend.make

# Include the progress variables for this target.
include libwordle/CMakeFiles/wordle.dir/progress.make

# Include the compile flags for this target's objects.
include libwordle/CMakeFiles/wordle.dir/flags.make

libwordle/CMakeFiles/wordle.dir/wordle.cpp.o: libwordle/CMakeFiles/wordle.dir/flags.make
libwordle/CMakeFiles/wordle.dir/wordle.cpp.o: libwordle/wordle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/nfs/homes/anclarma/rushes/wordle/rush/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libwordle/CMakeFiles/wordle.dir/wordle.cpp.o"
	cd /mnt/nfs/homes/anclarma/rushes/wordle/rush/libwordle && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wordle.dir/wordle.cpp.o -c /mnt/nfs/homes/anclarma/rushes/wordle/rush/libwordle/wordle.cpp

libwordle/CMakeFiles/wordle.dir/wordle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wordle.dir/wordle.cpp.i"
	cd /mnt/nfs/homes/anclarma/rushes/wordle/rush/libwordle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/nfs/homes/anclarma/rushes/wordle/rush/libwordle/wordle.cpp > CMakeFiles/wordle.dir/wordle.cpp.i

libwordle/CMakeFiles/wordle.dir/wordle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wordle.dir/wordle.cpp.s"
	cd /mnt/nfs/homes/anclarma/rushes/wordle/rush/libwordle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/nfs/homes/anclarma/rushes/wordle/rush/libwordle/wordle.cpp -o CMakeFiles/wordle.dir/wordle.cpp.s

# Object files for target wordle
wordle_OBJECTS = \
"CMakeFiles/wordle.dir/wordle.cpp.o"

# External object files for target wordle
wordle_EXTERNAL_OBJECTS =

libwordle/libwordle.a: libwordle/CMakeFiles/wordle.dir/wordle.cpp.o
libwordle/libwordle.a: libwordle/CMakeFiles/wordle.dir/build.make
libwordle/libwordle.a: libwordle/CMakeFiles/wordle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/nfs/homes/anclarma/rushes/wordle/rush/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libwordle.a"
	cd /mnt/nfs/homes/anclarma/rushes/wordle/rush/libwordle && $(CMAKE_COMMAND) -P CMakeFiles/wordle.dir/cmake_clean_target.cmake
	cd /mnt/nfs/homes/anclarma/rushes/wordle/rush/libwordle && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wordle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libwordle/CMakeFiles/wordle.dir/build: libwordle/libwordle.a

.PHONY : libwordle/CMakeFiles/wordle.dir/build

libwordle/CMakeFiles/wordle.dir/clean:
	cd /mnt/nfs/homes/anclarma/rushes/wordle/rush/libwordle && $(CMAKE_COMMAND) -P CMakeFiles/wordle.dir/cmake_clean.cmake
.PHONY : libwordle/CMakeFiles/wordle.dir/clean

libwordle/CMakeFiles/wordle.dir/depend:
	cd /mnt/nfs/homes/anclarma/rushes/wordle/rush && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/nfs/homes/anclarma/rushes/wordle/rush /mnt/nfs/homes/anclarma/rushes/wordle/rush/libwordle /mnt/nfs/homes/anclarma/rushes/wordle/rush /mnt/nfs/homes/anclarma/rushes/wordle/rush/libwordle /mnt/nfs/homes/anclarma/rushes/wordle/rush/libwordle/CMakeFiles/wordle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libwordle/CMakeFiles/wordle.dir/depend

