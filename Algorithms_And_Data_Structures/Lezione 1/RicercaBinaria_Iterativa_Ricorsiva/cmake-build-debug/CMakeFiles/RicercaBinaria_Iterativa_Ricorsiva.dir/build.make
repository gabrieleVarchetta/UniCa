# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\ASD\Lezione 1\RicercaBinaria_Iterativa_Ricorsiva"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\ASD\Lezione 1\RicercaBinaria_Iterativa_Ricorsiva\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/flags.make

CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/main.c.obj: CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/flags.make
CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\ASD\Lezione 1\RicercaBinaria_Iterativa_Ricorsiva\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/main.c.obj"
	D:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\RicercaBinaria_Iterativa_Ricorsiva.dir\main.c.obj   -c "D:\ASD\Lezione 1\RicercaBinaria_Iterativa_Ricorsiva\main.c"

CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/main.c.i"
	D:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\ASD\Lezione 1\RicercaBinaria_Iterativa_Ricorsiva\main.c" > CMakeFiles\RicercaBinaria_Iterativa_Ricorsiva.dir\main.c.i

CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/main.c.s"
	D:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\ASD\Lezione 1\RicercaBinaria_Iterativa_Ricorsiva\main.c" -o CMakeFiles\RicercaBinaria_Iterativa_Ricorsiva.dir\main.c.s

# Object files for target RicercaBinaria_Iterativa_Ricorsiva
RicercaBinaria_Iterativa_Ricorsiva_OBJECTS = \
"CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/main.c.obj"

# External object files for target RicercaBinaria_Iterativa_Ricorsiva
RicercaBinaria_Iterativa_Ricorsiva_EXTERNAL_OBJECTS =

RicercaBinaria_Iterativa_Ricorsiva.exe: CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/main.c.obj
RicercaBinaria_Iterativa_Ricorsiva.exe: CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/build.make
RicercaBinaria_Iterativa_Ricorsiva.exe: CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/linklibs.rsp
RicercaBinaria_Iterativa_Ricorsiva.exe: CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/objects1.rsp
RicercaBinaria_Iterativa_Ricorsiva.exe: CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\ASD\Lezione 1\RicercaBinaria_Iterativa_Ricorsiva\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable RicercaBinaria_Iterativa_Ricorsiva.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RicercaBinaria_Iterativa_Ricorsiva.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/build: RicercaBinaria_Iterativa_Ricorsiva.exe

.PHONY : CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/build

CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RicercaBinaria_Iterativa_Ricorsiva.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/clean

CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\ASD\Lezione 1\RicercaBinaria_Iterativa_Ricorsiva" "D:\ASD\Lezione 1\RicercaBinaria_Iterativa_Ricorsiva" "D:\ASD\Lezione 1\RicercaBinaria_Iterativa_Ricorsiva\cmake-build-debug" "D:\ASD\Lezione 1\RicercaBinaria_Iterativa_Ricorsiva\cmake-build-debug" "D:\ASD\Lezione 1\RicercaBinaria_Iterativa_Ricorsiva\cmake-build-debug\CMakeFiles\RicercaBinaria_Iterativa_Ricorsiva.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/RicercaBinaria_Iterativa_Ricorsiva.dir/depend
