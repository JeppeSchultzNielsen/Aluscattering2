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
include CMakeFiles/Run.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Run.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Run.dir/flags.make

CMakeFiles/Run.dir/run.cpp.o: CMakeFiles/Run.dir/flags.make
CMakeFiles/Run.dir/run.cpp.o: ../run.cpp
CMakeFiles/Run.dir/run.cpp.o: CMakeFiles/Run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeppe/devel/projects/Aluscattering2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Run.dir/run.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Run.dir/run.cpp.o -MF CMakeFiles/Run.dir/run.cpp.o.d -o CMakeFiles/Run.dir/run.cpp.o -c /home/jeppe/devel/projects/Aluscattering2/run.cpp

CMakeFiles/Run.dir/run.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Run.dir/run.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeppe/devel/projects/Aluscattering2/run.cpp > CMakeFiles/Run.dir/run.cpp.i

CMakeFiles/Run.dir/run.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Run.dir/run.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeppe/devel/projects/Aluscattering2/run.cpp -o CMakeFiles/Run.dir/run.cpp.s

CMakeFiles/Run.dir/Vinkelhistogrammer.cpp.o: CMakeFiles/Run.dir/flags.make
CMakeFiles/Run.dir/Vinkelhistogrammer.cpp.o: ../Vinkelhistogrammer.cpp
CMakeFiles/Run.dir/Vinkelhistogrammer.cpp.o: CMakeFiles/Run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeppe/devel/projects/Aluscattering2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Run.dir/Vinkelhistogrammer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Run.dir/Vinkelhistogrammer.cpp.o -MF CMakeFiles/Run.dir/Vinkelhistogrammer.cpp.o.d -o CMakeFiles/Run.dir/Vinkelhistogrammer.cpp.o -c /home/jeppe/devel/projects/Aluscattering2/Vinkelhistogrammer.cpp

CMakeFiles/Run.dir/Vinkelhistogrammer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Run.dir/Vinkelhistogrammer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeppe/devel/projects/Aluscattering2/Vinkelhistogrammer.cpp > CMakeFiles/Run.dir/Vinkelhistogrammer.cpp.i

CMakeFiles/Run.dir/Vinkelhistogrammer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Run.dir/Vinkelhistogrammer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeppe/devel/projects/Aluscattering2/Vinkelhistogrammer.cpp -o CMakeFiles/Run.dir/Vinkelhistogrammer.cpp.s

CMakeFiles/Run.dir/Analyse.cpp.o: CMakeFiles/Run.dir/flags.make
CMakeFiles/Run.dir/Analyse.cpp.o: ../Analyse.cpp
CMakeFiles/Run.dir/Analyse.cpp.o: CMakeFiles/Run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeppe/devel/projects/Aluscattering2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Run.dir/Analyse.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Run.dir/Analyse.cpp.o -MF CMakeFiles/Run.dir/Analyse.cpp.o.d -o CMakeFiles/Run.dir/Analyse.cpp.o -c /home/jeppe/devel/projects/Aluscattering2/Analyse.cpp

CMakeFiles/Run.dir/Analyse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Run.dir/Analyse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeppe/devel/projects/Aluscattering2/Analyse.cpp > CMakeFiles/Run.dir/Analyse.cpp.i

CMakeFiles/Run.dir/Analyse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Run.dir/Analyse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeppe/devel/projects/Aluscattering2/Analyse.cpp -o CMakeFiles/Run.dir/Analyse.cpp.s

CMakeFiles/Run.dir/Thickness.cpp.o: CMakeFiles/Run.dir/flags.make
CMakeFiles/Run.dir/Thickness.cpp.o: ../Thickness.cpp
CMakeFiles/Run.dir/Thickness.cpp.o: CMakeFiles/Run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeppe/devel/projects/Aluscattering2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Run.dir/Thickness.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Run.dir/Thickness.cpp.o -MF CMakeFiles/Run.dir/Thickness.cpp.o.d -o CMakeFiles/Run.dir/Thickness.cpp.o -c /home/jeppe/devel/projects/Aluscattering2/Thickness.cpp

CMakeFiles/Run.dir/Thickness.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Run.dir/Thickness.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeppe/devel/projects/Aluscattering2/Thickness.cpp > CMakeFiles/Run.dir/Thickness.cpp.i

CMakeFiles/Run.dir/Thickness.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Run.dir/Thickness.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeppe/devel/projects/Aluscattering2/Thickness.cpp -o CMakeFiles/Run.dir/Thickness.cpp.s

# Object files for target Run
Run_OBJECTS = \
"CMakeFiles/Run.dir/run.cpp.o" \
"CMakeFiles/Run.dir/Vinkelhistogrammer.cpp.o" \
"CMakeFiles/Run.dir/Analyse.cpp.o" \
"CMakeFiles/Run.dir/Thickness.cpp.o"

# External object files for target Run
Run_EXTERNAL_OBJECTS =

Run: CMakeFiles/Run.dir/run.cpp.o
Run: CMakeFiles/Run.dir/Vinkelhistogrammer.cpp.o
Run: CMakeFiles/Run.dir/Analyse.cpp.o
Run: CMakeFiles/Run.dir/Thickness.cpp.o
Run: CMakeFiles/Run.dir/build.make
Run: /usr/local/lib/libAUSA.a
Run: /usr/local/lib/root/libPhysics.so.6.24.06
Run: /usr/local/lib/root/libTreePlayer.so.6.24.06
Run: /usr/local/lib/root/libGraf3d.so.6.24.06
Run: /usr/local/lib/root/libGpad.so.6.24.06
Run: /usr/local/lib/root/libGraf.so.6.24.06
Run: /usr/local/lib/root/libTree.so.6.24.06
Run: /usr/local/lib/root/libMathMore.so.6.24.06
Run: /usr/local/lib/root/libSpectrum.so.6.24.06
Run: /usr/local/lib/root/libHist.so.6.24.06
Run: /usr/local/lib/root/libMatrix.so.6.24.06
Run: /usr/local/lib/root/libMathCore.so.6.24.06
Run: /usr/local/lib/root/libImt.so.6.24.06
Run: /usr/local/lib/root/libMultiProc.so.6.24.06
Run: /usr/local/lib/root/libNet.so.6.24.06
Run: /usr/local/lib/root/libRIO.so.6.24.06
Run: /usr/local/lib/root/libThread.so.6.24.06
Run: /usr/local/lib/root/libCore.so.6.24.06
Run: /usr/local/lib/root/libCling.so.6.24.06
Run: /usr/lib/x86_64-linux-gnu/libfmt.a
Run: /usr/lib/x86_64-linux-gnu/libgsl.so
Run: /usr/lib/x86_64-linux-gnu/libgslcblas.so
Run: /usr/lib/x86_64-linux-gnu/libcurl.so
Run: CMakeFiles/Run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jeppe/devel/projects/Aluscattering2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Run.dir/build: Run
.PHONY : CMakeFiles/Run.dir/build

CMakeFiles/Run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Run.dir/clean

CMakeFiles/Run.dir/depend:
	cd /home/jeppe/devel/projects/Aluscattering2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeppe/devel/projects/Aluscattering2 /home/jeppe/devel/projects/Aluscattering2 /home/jeppe/devel/projects/Aluscattering2/cmake-build-debug /home/jeppe/devel/projects/Aluscattering2/cmake-build-debug /home/jeppe/devel/projects/Aluscattering2/cmake-build-debug/CMakeFiles/Run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Run.dir/depend

