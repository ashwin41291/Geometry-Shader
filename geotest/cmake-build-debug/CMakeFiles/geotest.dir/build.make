# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Ash/CLionProjects/geotest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Ash/CLionProjects/geotest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/geotest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/geotest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/geotest.dir/flags.make

CMakeFiles/geotest.dir/gl3w.c.o: CMakeFiles/geotest.dir/flags.make
CMakeFiles/geotest.dir/gl3w.c.o: ../gl3w.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Ash/CLionProjects/geotest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/geotest.dir/gl3w.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/geotest.dir/gl3w.c.o   -c /Users/Ash/CLionProjects/geotest/gl3w.c

CMakeFiles/geotest.dir/gl3w.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/geotest.dir/gl3w.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Ash/CLionProjects/geotest/gl3w.c > CMakeFiles/geotest.dir/gl3w.c.i

CMakeFiles/geotest.dir/gl3w.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/geotest.dir/gl3w.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Ash/CLionProjects/geotest/gl3w.c -o CMakeFiles/geotest.dir/gl3w.c.s

CMakeFiles/geotest.dir/gl3w.c.o.requires:

.PHONY : CMakeFiles/geotest.dir/gl3w.c.o.requires

CMakeFiles/geotest.dir/gl3w.c.o.provides: CMakeFiles/geotest.dir/gl3w.c.o.requires
	$(MAKE) -f CMakeFiles/geotest.dir/build.make CMakeFiles/geotest.dir/gl3w.c.o.provides.build
.PHONY : CMakeFiles/geotest.dir/gl3w.c.o.provides

CMakeFiles/geotest.dir/gl3w.c.o.provides.build: CMakeFiles/geotest.dir/gl3w.c.o


CMakeFiles/geotest.dir/LoadShaders.cpp.o: CMakeFiles/geotest.dir/flags.make
CMakeFiles/geotest.dir/LoadShaders.cpp.o: ../LoadShaders.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Ash/CLionProjects/geotest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/geotest.dir/LoadShaders.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geotest.dir/LoadShaders.cpp.o -c /Users/Ash/CLionProjects/geotest/LoadShaders.cpp

CMakeFiles/geotest.dir/LoadShaders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geotest.dir/LoadShaders.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Ash/CLionProjects/geotest/LoadShaders.cpp > CMakeFiles/geotest.dir/LoadShaders.cpp.i

CMakeFiles/geotest.dir/LoadShaders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geotest.dir/LoadShaders.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Ash/CLionProjects/geotest/LoadShaders.cpp -o CMakeFiles/geotest.dir/LoadShaders.cpp.s

CMakeFiles/geotest.dir/LoadShaders.cpp.o.requires:

.PHONY : CMakeFiles/geotest.dir/LoadShaders.cpp.o.requires

CMakeFiles/geotest.dir/LoadShaders.cpp.o.provides: CMakeFiles/geotest.dir/LoadShaders.cpp.o.requires
	$(MAKE) -f CMakeFiles/geotest.dir/build.make CMakeFiles/geotest.dir/LoadShaders.cpp.o.provides.build
.PHONY : CMakeFiles/geotest.dir/LoadShaders.cpp.o.provides

CMakeFiles/geotest.dir/LoadShaders.cpp.o.provides.build: CMakeFiles/geotest.dir/LoadShaders.cpp.o


CMakeFiles/geotest.dir/viewer.cpp.o: CMakeFiles/geotest.dir/flags.make
CMakeFiles/geotest.dir/viewer.cpp.o: ../viewer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Ash/CLionProjects/geotest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/geotest.dir/viewer.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geotest.dir/viewer.cpp.o -c /Users/Ash/CLionProjects/geotest/viewer.cpp

CMakeFiles/geotest.dir/viewer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geotest.dir/viewer.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Ash/CLionProjects/geotest/viewer.cpp > CMakeFiles/geotest.dir/viewer.cpp.i

CMakeFiles/geotest.dir/viewer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geotest.dir/viewer.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Ash/CLionProjects/geotest/viewer.cpp -o CMakeFiles/geotest.dir/viewer.cpp.s

CMakeFiles/geotest.dir/viewer.cpp.o.requires:

.PHONY : CMakeFiles/geotest.dir/viewer.cpp.o.requires

CMakeFiles/geotest.dir/viewer.cpp.o.provides: CMakeFiles/geotest.dir/viewer.cpp.o.requires
	$(MAKE) -f CMakeFiles/geotest.dir/build.make CMakeFiles/geotest.dir/viewer.cpp.o.provides.build
.PHONY : CMakeFiles/geotest.dir/viewer.cpp.o.provides

CMakeFiles/geotest.dir/viewer.cpp.o.provides.build: CMakeFiles/geotest.dir/viewer.cpp.o


CMakeFiles/geotest.dir/loadObj.cpp.o: CMakeFiles/geotest.dir/flags.make
CMakeFiles/geotest.dir/loadObj.cpp.o: ../loadObj.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Ash/CLionProjects/geotest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/geotest.dir/loadObj.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geotest.dir/loadObj.cpp.o -c /Users/Ash/CLionProjects/geotest/loadObj.cpp

CMakeFiles/geotest.dir/loadObj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geotest.dir/loadObj.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Ash/CLionProjects/geotest/loadObj.cpp > CMakeFiles/geotest.dir/loadObj.cpp.i

CMakeFiles/geotest.dir/loadObj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geotest.dir/loadObj.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Ash/CLionProjects/geotest/loadObj.cpp -o CMakeFiles/geotest.dir/loadObj.cpp.s

CMakeFiles/geotest.dir/loadObj.cpp.o.requires:

.PHONY : CMakeFiles/geotest.dir/loadObj.cpp.o.requires

CMakeFiles/geotest.dir/loadObj.cpp.o.provides: CMakeFiles/geotest.dir/loadObj.cpp.o.requires
	$(MAKE) -f CMakeFiles/geotest.dir/build.make CMakeFiles/geotest.dir/loadObj.cpp.o.provides.build
.PHONY : CMakeFiles/geotest.dir/loadObj.cpp.o.provides

CMakeFiles/geotest.dir/loadObj.cpp.o.provides.build: CMakeFiles/geotest.dir/loadObj.cpp.o


CMakeFiles/geotest.dir/ReadScene.cpp.o: CMakeFiles/geotest.dir/flags.make
CMakeFiles/geotest.dir/ReadScene.cpp.o: ../ReadScene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Ash/CLionProjects/geotest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/geotest.dir/ReadScene.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geotest.dir/ReadScene.cpp.o -c /Users/Ash/CLionProjects/geotest/ReadScene.cpp

CMakeFiles/geotest.dir/ReadScene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geotest.dir/ReadScene.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Ash/CLionProjects/geotest/ReadScene.cpp > CMakeFiles/geotest.dir/ReadScene.cpp.i

CMakeFiles/geotest.dir/ReadScene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geotest.dir/ReadScene.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Ash/CLionProjects/geotest/ReadScene.cpp -o CMakeFiles/geotest.dir/ReadScene.cpp.s

CMakeFiles/geotest.dir/ReadScene.cpp.o.requires:

.PHONY : CMakeFiles/geotest.dir/ReadScene.cpp.o.requires

CMakeFiles/geotest.dir/ReadScene.cpp.o.provides: CMakeFiles/geotest.dir/ReadScene.cpp.o.requires
	$(MAKE) -f CMakeFiles/geotest.dir/build.make CMakeFiles/geotest.dir/ReadScene.cpp.o.provides.build
.PHONY : CMakeFiles/geotest.dir/ReadScene.cpp.o.provides

CMakeFiles/geotest.dir/ReadScene.cpp.o.provides.build: CMakeFiles/geotest.dir/ReadScene.cpp.o


# Object files for target geotest
geotest_OBJECTS = \
"CMakeFiles/geotest.dir/gl3w.c.o" \
"CMakeFiles/geotest.dir/LoadShaders.cpp.o" \
"CMakeFiles/geotest.dir/viewer.cpp.o" \
"CMakeFiles/geotest.dir/loadObj.cpp.o" \
"CMakeFiles/geotest.dir/ReadScene.cpp.o"

# External object files for target geotest
geotest_EXTERNAL_OBJECTS =

geotest: CMakeFiles/geotest.dir/gl3w.c.o
geotest: CMakeFiles/geotest.dir/LoadShaders.cpp.o
geotest: CMakeFiles/geotest.dir/viewer.cpp.o
geotest: CMakeFiles/geotest.dir/loadObj.cpp.o
geotest: CMakeFiles/geotest.dir/ReadScene.cpp.o
geotest: CMakeFiles/geotest.dir/build.make
geotest: CMakeFiles/geotest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Ash/CLionProjects/geotest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable geotest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/geotest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/geotest.dir/build: geotest

.PHONY : CMakeFiles/geotest.dir/build

CMakeFiles/geotest.dir/requires: CMakeFiles/geotest.dir/gl3w.c.o.requires
CMakeFiles/geotest.dir/requires: CMakeFiles/geotest.dir/LoadShaders.cpp.o.requires
CMakeFiles/geotest.dir/requires: CMakeFiles/geotest.dir/viewer.cpp.o.requires
CMakeFiles/geotest.dir/requires: CMakeFiles/geotest.dir/loadObj.cpp.o.requires
CMakeFiles/geotest.dir/requires: CMakeFiles/geotest.dir/ReadScene.cpp.o.requires

.PHONY : CMakeFiles/geotest.dir/requires

CMakeFiles/geotest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/geotest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/geotest.dir/clean

CMakeFiles/geotest.dir/depend:
	cd /Users/Ash/CLionProjects/geotest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Ash/CLionProjects/geotest /Users/Ash/CLionProjects/geotest /Users/Ash/CLionProjects/geotest/cmake-build-debug /Users/Ash/CLionProjects/geotest/cmake-build-debug /Users/Ash/CLionProjects/geotest/cmake-build-debug/CMakeFiles/geotest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/geotest.dir/depend

