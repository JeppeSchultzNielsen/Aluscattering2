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
CMAKE_COMMAND = /home/jeppe/clion-2021.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/jeppe/clion-2021.3.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jeppe/devel/projects/Aluscattering2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jeppe/devel/projects/Aluscattering2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Vinkler.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Vinkler.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Vinkler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Vinkler.dir/flags.make

CMakeFiles/Vinkler.dir/Vinkelhistogrammer.cpp.o: CMakeFiles/Vinkler.dir/flags.make
CMakeFiles/Vinkler.dir/Vinkelhistogrammer.cpp.o: ../Vinkelhistogrammer.cpp
CMakeFiles/Vinkler.dir/Vinkelhistogrammer.cpp.o: CMakeFiles/Vinkler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeppe/devel/projects/Aluscattering2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Vinkler.dir/Vinkelhistogrammer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Vinkler.dir/Vinkelhistogrammer.cpp.o -MF CMakeFiles/Vinkler.dir/Vinkelhistogrammer.cpp.o.d -o CMakeFiles/Vinkler.dir/Vinkelhistogrammer.cpp.o -c /home/jeppe/devel/projects/Aluscattering2/Vinkelhistogrammer.cpp

CMakeFiles/Vinkler.dir/Vinkelhistogrammer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vinkler.dir/Vinkelhistogrammer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeppe/devel/projects/Aluscattering2/Vinkelhistogrammer.cpp > CMakeFiles/Vinkler.dir/Vinkelhistogrammer.cpp.i

CMakeFiles/Vinkler.dir/Vinkelhistogrammer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vinkler.dir/Vinkelhistogrammer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeppe/devel/projects/Aluscattering2/Vinkelhistogrammer.cpp -o CMakeFiles/Vinkler.dir/Vinkelhistogrammer.cpp.s

# Object files for target Vinkler
Vinkler_OBJECTS = \
"CMakeFiles/Vinkler.dir/Vinkelhistogrammer.cpp.o"

# External object files for target Vinkler
Vinkler_EXTERNAL_OBJECTS =

Vinkler: CMakeFiles/Vinkler.dir/Vinkelhistogrammer.cpp.o
Vinkler: CMakeFiles/Vinkler.dir/build.make
Vinkler: /usr/local/lib/libAUSA.a
Vinkler: /usr/local/lib/root/libPhysics.so.6.24.06
Vinkler: /usr/local/lib/root/libTreePlayer.so.6.24.06
Vinkler: /usr/local/lib/root/libGraf3d.so.6.24.06
Vinkler: /usr/local/lib/root/libGpad.so.6.24.06
Vinkler: /usr/local/lib/root/libGraf.so.6.24.06
Vinkler: /usr/local/lib/root/libTree.so.6.24.06
Vinkler: /usr/local/lib/root/libMathMore.so.6.24.06
Vinkler: /usr/local/lib/root/libSpectrum.so.6.24.06
Vinkler: /usr/local/lib/root/libHist.so.6.24.06
Vinkler: /usr/local/lib/root/libMatrix.so.6.24.06
Vinkler: /usr/local/lib/root/libMathCore.so.6.24.06
Vinkler: /usr/local/lib/root/libImt.so.6.24.06
Vinkler: /usr/local/lib/root/libMultiProc.so.6.24.06
Vinkler: /usr/local/lib/root/libNet.so.6.24.06
Vinkler: /usr/local/lib/root/libRIO.so.6.24.06
Vinkler: /usr/local/lib/root/libThread.so.6.24.06
Vinkler: /usr/local/lib/root/libCore.so.6.24.06
Vinkler: /usr/local/lib/root/libCling.so.6.24.06
Vinkler: /usr/lib/x86_64-linux-gnu/libfmt.a
Vinkler: /usr/lib/x86_64-linux-gnu/libgsl.so
Vinkler: /usr/lib/x86_64-linux-gnu/libgslcblas.so
Vinkler: /usr/lib/x86_64-linux-gnu/libcurl.so
Vinkler: CMakeFiles/Vinkler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jeppe/devel/projects/Aluscattering2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Vinkler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Vinkler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Vinkler.dir/build: Vinkler
.PHONY : CMakeFiles/Vinkler.dir/build

CMakeFiles/Vinkler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Vinkler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Vinkler.dir/clean

CMakeFiles/Vinkler.dir/depend:
	cd /home/jeppe/devel/projects/Aluscattering2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeppe/devel/projects/Aluscattering2 /home/jeppe/devel/projects/Aluscattering2 /home/jeppe/devel/projects/Aluscattering2/cmake-build-debug /home/jeppe/devel/projects/Aluscattering2/cmake-build-debug /home/jeppe/devel/projects/Aluscattering2/cmake-build-debug/CMakeFiles/Vinkler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Vinkler.dir/depend

