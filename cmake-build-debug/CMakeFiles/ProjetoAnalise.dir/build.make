# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/guilherme/Downloads/clion-2017.1.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/guilherme/Downloads/clion-2017.1.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/guilherme/Documents/ProjetoAnalise

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/guilherme/Documents/ProjetoAnalise/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProjetoAnalise.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjetoAnalise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjetoAnalise.dir/flags.make

CMakeFiles/ProjetoAnalise.dir/main.c.o: CMakeFiles/ProjetoAnalise.dir/flags.make
CMakeFiles/ProjetoAnalise.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guilherme/Documents/ProjetoAnalise/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ProjetoAnalise.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ProjetoAnalise.dir/main.c.o   -c /home/guilherme/Documents/ProjetoAnalise/main.c

CMakeFiles/ProjetoAnalise.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjetoAnalise.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/guilherme/Documents/ProjetoAnalise/main.c > CMakeFiles/ProjetoAnalise.dir/main.c.i

CMakeFiles/ProjetoAnalise.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjetoAnalise.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/guilherme/Documents/ProjetoAnalise/main.c -o CMakeFiles/ProjetoAnalise.dir/main.c.s

CMakeFiles/ProjetoAnalise.dir/main.c.o.requires:

.PHONY : CMakeFiles/ProjetoAnalise.dir/main.c.o.requires

CMakeFiles/ProjetoAnalise.dir/main.c.o.provides: CMakeFiles/ProjetoAnalise.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/ProjetoAnalise.dir/build.make CMakeFiles/ProjetoAnalise.dir/main.c.o.provides.build
.PHONY : CMakeFiles/ProjetoAnalise.dir/main.c.o.provides

CMakeFiles/ProjetoAnalise.dir/main.c.o.provides.build: CMakeFiles/ProjetoAnalise.dir/main.c.o


CMakeFiles/ProjetoAnalise.dir/algs.c.o: CMakeFiles/ProjetoAnalise.dir/flags.make
CMakeFiles/ProjetoAnalise.dir/algs.c.o: ../algs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guilherme/Documents/ProjetoAnalise/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ProjetoAnalise.dir/algs.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ProjetoAnalise.dir/algs.c.o   -c /home/guilherme/Documents/ProjetoAnalise/algs.c

CMakeFiles/ProjetoAnalise.dir/algs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjetoAnalise.dir/algs.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/guilherme/Documents/ProjetoAnalise/algs.c > CMakeFiles/ProjetoAnalise.dir/algs.c.i

CMakeFiles/ProjetoAnalise.dir/algs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjetoAnalise.dir/algs.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/guilherme/Documents/ProjetoAnalise/algs.c -o CMakeFiles/ProjetoAnalise.dir/algs.c.s

CMakeFiles/ProjetoAnalise.dir/algs.c.o.requires:

.PHONY : CMakeFiles/ProjetoAnalise.dir/algs.c.o.requires

CMakeFiles/ProjetoAnalise.dir/algs.c.o.provides: CMakeFiles/ProjetoAnalise.dir/algs.c.o.requires
	$(MAKE) -f CMakeFiles/ProjetoAnalise.dir/build.make CMakeFiles/ProjetoAnalise.dir/algs.c.o.provides.build
.PHONY : CMakeFiles/ProjetoAnalise.dir/algs.c.o.provides

CMakeFiles/ProjetoAnalise.dir/algs.c.o.provides.build: CMakeFiles/ProjetoAnalise.dir/algs.c.o


CMakeFiles/ProjetoAnalise.dir/gerador.c.o: CMakeFiles/ProjetoAnalise.dir/flags.make
CMakeFiles/ProjetoAnalise.dir/gerador.c.o: ../gerador.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/guilherme/Documents/ProjetoAnalise/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ProjetoAnalise.dir/gerador.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ProjetoAnalise.dir/gerador.c.o   -c /home/guilherme/Documents/ProjetoAnalise/gerador.c

CMakeFiles/ProjetoAnalise.dir/gerador.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjetoAnalise.dir/gerador.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/guilherme/Documents/ProjetoAnalise/gerador.c > CMakeFiles/ProjetoAnalise.dir/gerador.c.i

CMakeFiles/ProjetoAnalise.dir/gerador.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjetoAnalise.dir/gerador.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/guilherme/Documents/ProjetoAnalise/gerador.c -o CMakeFiles/ProjetoAnalise.dir/gerador.c.s

CMakeFiles/ProjetoAnalise.dir/gerador.c.o.requires:

.PHONY : CMakeFiles/ProjetoAnalise.dir/gerador.c.o.requires

CMakeFiles/ProjetoAnalise.dir/gerador.c.o.provides: CMakeFiles/ProjetoAnalise.dir/gerador.c.o.requires
	$(MAKE) -f CMakeFiles/ProjetoAnalise.dir/build.make CMakeFiles/ProjetoAnalise.dir/gerador.c.o.provides.build
.PHONY : CMakeFiles/ProjetoAnalise.dir/gerador.c.o.provides

CMakeFiles/ProjetoAnalise.dir/gerador.c.o.provides.build: CMakeFiles/ProjetoAnalise.dir/gerador.c.o


# Object files for target ProjetoAnalise
ProjetoAnalise_OBJECTS = \
"CMakeFiles/ProjetoAnalise.dir/main.c.o" \
"CMakeFiles/ProjetoAnalise.dir/algs.c.o" \
"CMakeFiles/ProjetoAnalise.dir/gerador.c.o"

# External object files for target ProjetoAnalise
ProjetoAnalise_EXTERNAL_OBJECTS =

ProjetoAnalise: CMakeFiles/ProjetoAnalise.dir/main.c.o
ProjetoAnalise: CMakeFiles/ProjetoAnalise.dir/algs.c.o
ProjetoAnalise: CMakeFiles/ProjetoAnalise.dir/gerador.c.o
ProjetoAnalise: CMakeFiles/ProjetoAnalise.dir/build.make
ProjetoAnalise: CMakeFiles/ProjetoAnalise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/guilherme/Documents/ProjetoAnalise/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable ProjetoAnalise"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProjetoAnalise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjetoAnalise.dir/build: ProjetoAnalise

.PHONY : CMakeFiles/ProjetoAnalise.dir/build

CMakeFiles/ProjetoAnalise.dir/requires: CMakeFiles/ProjetoAnalise.dir/main.c.o.requires
CMakeFiles/ProjetoAnalise.dir/requires: CMakeFiles/ProjetoAnalise.dir/algs.c.o.requires
CMakeFiles/ProjetoAnalise.dir/requires: CMakeFiles/ProjetoAnalise.dir/gerador.c.o.requires

.PHONY : CMakeFiles/ProjetoAnalise.dir/requires

CMakeFiles/ProjetoAnalise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProjetoAnalise.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProjetoAnalise.dir/clean

CMakeFiles/ProjetoAnalise.dir/depend:
	cd /home/guilherme/Documents/ProjetoAnalise/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/guilherme/Documents/ProjetoAnalise /home/guilherme/Documents/ProjetoAnalise /home/guilherme/Documents/ProjetoAnalise/cmake-build-debug /home/guilherme/Documents/ProjetoAnalise/cmake-build-debug /home/guilherme/Documents/ProjetoAnalise/cmake-build-debug/CMakeFiles/ProjetoAnalise.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjetoAnalise.dir/depend

