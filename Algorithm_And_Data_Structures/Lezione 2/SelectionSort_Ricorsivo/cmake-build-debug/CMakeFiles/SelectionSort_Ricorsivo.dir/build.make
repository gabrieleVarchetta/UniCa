# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/gabriele/Documents/Università/PRIMO_ANNO/SECONDO_SEMESTRE/ASD/Laboratorio/ASD/Lezione 2/SelectionSort_Ricorsivo"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/gabriele/Documents/Università/PRIMO_ANNO/SECONDO_SEMESTRE/ASD/Laboratorio/ASD/Lezione 2/SelectionSort_Ricorsivo/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/SelectionSort_Ricorsivo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SelectionSort_Ricorsivo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SelectionSort_Ricorsivo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SelectionSort_Ricorsivo.dir/flags.make

CMakeFiles/SelectionSort_Ricorsivo.dir/main.c.o: CMakeFiles/SelectionSort_Ricorsivo.dir/flags.make
CMakeFiles/SelectionSort_Ricorsivo.dir/main.c.o: ../main.c
CMakeFiles/SelectionSort_Ricorsivo.dir/main.c.o: CMakeFiles/SelectionSort_Ricorsivo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/gabriele/Documents/Università/PRIMO_ANNO/SECONDO_SEMESTRE/ASD/Laboratorio/ASD/Lezione 2/SelectionSort_Ricorsivo/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SelectionSort_Ricorsivo.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SelectionSort_Ricorsivo.dir/main.c.o -MF CMakeFiles/SelectionSort_Ricorsivo.dir/main.c.o.d -o CMakeFiles/SelectionSort_Ricorsivo.dir/main.c.o -c "/Users/gabriele/Documents/Università/PRIMO_ANNO/SECONDO_SEMESTRE/ASD/Laboratorio/ASD/Lezione 2/SelectionSort_Ricorsivo/main.c"

CMakeFiles/SelectionSort_Ricorsivo.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SelectionSort_Ricorsivo.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/gabriele/Documents/Università/PRIMO_ANNO/SECONDO_SEMESTRE/ASD/Laboratorio/ASD/Lezione 2/SelectionSort_Ricorsivo/main.c" > CMakeFiles/SelectionSort_Ricorsivo.dir/main.c.i

CMakeFiles/SelectionSort_Ricorsivo.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SelectionSort_Ricorsivo.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/gabriele/Documents/Università/PRIMO_ANNO/SECONDO_SEMESTRE/ASD/Laboratorio/ASD/Lezione 2/SelectionSort_Ricorsivo/main.c" -o CMakeFiles/SelectionSort_Ricorsivo.dir/main.c.s

# Object files for target SelectionSort_Ricorsivo
SelectionSort_Ricorsivo_OBJECTS = \
"CMakeFiles/SelectionSort_Ricorsivo.dir/main.c.o"

# External object files for target SelectionSort_Ricorsivo
SelectionSort_Ricorsivo_EXTERNAL_OBJECTS =

SelectionSort_Ricorsivo: CMakeFiles/SelectionSort_Ricorsivo.dir/main.c.o
SelectionSort_Ricorsivo: CMakeFiles/SelectionSort_Ricorsivo.dir/build.make
SelectionSort_Ricorsivo: CMakeFiles/SelectionSort_Ricorsivo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/gabriele/Documents/Università/PRIMO_ANNO/SECONDO_SEMESTRE/ASD/Laboratorio/ASD/Lezione 2/SelectionSort_Ricorsivo/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SelectionSort_Ricorsivo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SelectionSort_Ricorsivo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SelectionSort_Ricorsivo.dir/build: SelectionSort_Ricorsivo
.PHONY : CMakeFiles/SelectionSort_Ricorsivo.dir/build

CMakeFiles/SelectionSort_Ricorsivo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SelectionSort_Ricorsivo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SelectionSort_Ricorsivo.dir/clean

CMakeFiles/SelectionSort_Ricorsivo.dir/depend:
	cd "/Users/gabriele/Documents/Università/PRIMO_ANNO/SECONDO_SEMESTRE/ASD/Laboratorio/ASD/Lezione 2/SelectionSort_Ricorsivo/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/gabriele/Documents/Università/PRIMO_ANNO/SECONDO_SEMESTRE/ASD/Laboratorio/ASD/Lezione 2/SelectionSort_Ricorsivo" "/Users/gabriele/Documents/Università/PRIMO_ANNO/SECONDO_SEMESTRE/ASD/Laboratorio/ASD/Lezione 2/SelectionSort_Ricorsivo" "/Users/gabriele/Documents/Università/PRIMO_ANNO/SECONDO_SEMESTRE/ASD/Laboratorio/ASD/Lezione 2/SelectionSort_Ricorsivo/cmake-build-debug" "/Users/gabriele/Documents/Università/PRIMO_ANNO/SECONDO_SEMESTRE/ASD/Laboratorio/ASD/Lezione 2/SelectionSort_Ricorsivo/cmake-build-debug" "/Users/gabriele/Documents/Università/PRIMO_ANNO/SECONDO_SEMESTRE/ASD/Laboratorio/ASD/Lezione 2/SelectionSort_Ricorsivo/cmake-build-debug/CMakeFiles/SelectionSort_Ricorsivo.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/SelectionSort_Ricorsivo.dir/depend

