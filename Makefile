# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /cygdrive/c/Users/apaca/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/apaca/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/apaca/CLionProjects/AbstractVM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/apaca/CLionProjects/AbstractVM

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/cygdrive/c/Users/apaca/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/cygdrive/c/Users/apaca/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /cygdrive/c/Users/apaca/CLionProjects/AbstractVM/CMakeFiles /cygdrive/c/Users/apaca/CLionProjects/AbstractVM/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /cygdrive/c/Users/apaca/CLionProjects/AbstractVM/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named untitled

# Build rule for target.
untitled: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 untitled
.PHONY : untitled

# fast build rule for target.
untitled/fast:
	$(MAKE) -f CMakeFiles/untitled.dir/build.make CMakeFiles/untitled.dir/build
.PHONY : untitled/fast

source/Factory.o: source/Factory.cpp.o

.PHONY : source/Factory.o

# target to build an object file
source/Factory.cpp.o:
	$(MAKE) -f CMakeFiles/untitled.dir/build.make CMakeFiles/untitled.dir/source/Factory.cpp.o
.PHONY : source/Factory.cpp.o

source/Factory.i: source/Factory.cpp.i

.PHONY : source/Factory.i

# target to preprocess a source file
source/Factory.cpp.i:
	$(MAKE) -f CMakeFiles/untitled.dir/build.make CMakeFiles/untitled.dir/source/Factory.cpp.i
.PHONY : source/Factory.cpp.i

source/Factory.s: source/Factory.cpp.s

.PHONY : source/Factory.s

# target to generate assembly for a file
source/Factory.cpp.s:
	$(MAKE) -f CMakeFiles/untitled.dir/build.make CMakeFiles/untitled.dir/source/Factory.cpp.s
.PHONY : source/Factory.cpp.s

source/IOperand.o: source/IOperand.cpp.o

.PHONY : source/IOperand.o

# target to build an object file
source/IOperand.cpp.o:
	$(MAKE) -f CMakeFiles/untitled.dir/build.make CMakeFiles/untitled.dir/source/IOperand.cpp.o
.PHONY : source/IOperand.cpp.o

source/IOperand.i: source/IOperand.cpp.i

.PHONY : source/IOperand.i

# target to preprocess a source file
source/IOperand.cpp.i:
	$(MAKE) -f CMakeFiles/untitled.dir/build.make CMakeFiles/untitled.dir/source/IOperand.cpp.i
.PHONY : source/IOperand.cpp.i

source/IOperand.s: source/IOperand.cpp.s

.PHONY : source/IOperand.s

# target to generate assembly for a file
source/IOperand.cpp.s:
	$(MAKE) -f CMakeFiles/untitled.dir/build.make CMakeFiles/untitled.dir/source/IOperand.cpp.s
.PHONY : source/IOperand.cpp.s

source/main.o: source/main.cpp.o

.PHONY : source/main.o

# target to build an object file
source/main.cpp.o:
	$(MAKE) -f CMakeFiles/untitled.dir/build.make CMakeFiles/untitled.dir/source/main.cpp.o
.PHONY : source/main.cpp.o

source/main.i: source/main.cpp.i

.PHONY : source/main.i

# target to preprocess a source file
source/main.cpp.i:
	$(MAKE) -f CMakeFiles/untitled.dir/build.make CMakeFiles/untitled.dir/source/main.cpp.i
.PHONY : source/main.cpp.i

source/main.s: source/main.cpp.s

.PHONY : source/main.s

# target to generate assembly for a file
source/main.cpp.s:
	$(MAKE) -f CMakeFiles/untitled.dir/build.make CMakeFiles/untitled.dir/source/main.cpp.s
.PHONY : source/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... untitled"
	@echo "... source/Factory.o"
	@echo "... source/Factory.i"
	@echo "... source/Factory.s"
	@echo "... source/IOperand.o"
	@echo "... source/IOperand.i"
	@echo "... source/IOperand.s"
	@echo "... source/main.o"
	@echo "... source/main.i"
	@echo "... source/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

