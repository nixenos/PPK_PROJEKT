# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/92/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/92/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nixen/Projects/uczelnia/PPK/github_repo/nowa_sekcja/e1f9ddbe-gr32-repo/projekt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nixen/Projects/uczelnia/PPK/github_repo/nowa_sekcja/e1f9ddbe-gr32-repo/projekt/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/projekt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/projekt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projekt.dir/flags.make

CMakeFiles/projekt.dir/main.cpp.o: CMakeFiles/projekt.dir/flags.make
CMakeFiles/projekt.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nixen/Projects/uczelnia/PPK/github_repo/nowa_sekcja/e1f9ddbe-gr32-repo/projekt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/projekt.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projekt.dir/main.cpp.o -c /home/nixen/Projects/uczelnia/PPK/github_repo/nowa_sekcja/e1f9ddbe-gr32-repo/projekt/main.cpp

CMakeFiles/projekt.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projekt.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nixen/Projects/uczelnia/PPK/github_repo/nowa_sekcja/e1f9ddbe-gr32-repo/projekt/main.cpp > CMakeFiles/projekt.dir/main.cpp.i

CMakeFiles/projekt.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projekt.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nixen/Projects/uczelnia/PPK/github_repo/nowa_sekcja/e1f9ddbe-gr32-repo/projekt/main.cpp -o CMakeFiles/projekt.dir/main.cpp.s

# Object files for target projekt
projekt_OBJECTS = \
"CMakeFiles/projekt.dir/main.cpp.o"

# External object files for target projekt
projekt_EXTERNAL_OBJECTS =

projekt: CMakeFiles/projekt.dir/main.cpp.o
projekt: CMakeFiles/projekt.dir/build.make
projekt: CMakeFiles/projekt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nixen/Projects/uczelnia/PPK/github_repo/nowa_sekcja/e1f9ddbe-gr32-repo/projekt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable projekt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projekt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projekt.dir/build: projekt

.PHONY : CMakeFiles/projekt.dir/build

CMakeFiles/projekt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projekt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projekt.dir/clean

CMakeFiles/projekt.dir/depend:
	cd /home/nixen/Projects/uczelnia/PPK/github_repo/nowa_sekcja/e1f9ddbe-gr32-repo/projekt/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nixen/Projects/uczelnia/PPK/github_repo/nowa_sekcja/e1f9ddbe-gr32-repo/projekt /home/nixen/Projects/uczelnia/PPK/github_repo/nowa_sekcja/e1f9ddbe-gr32-repo/projekt /home/nixen/Projects/uczelnia/PPK/github_repo/nowa_sekcja/e1f9ddbe-gr32-repo/projekt/cmake-build-debug /home/nixen/Projects/uczelnia/PPK/github_repo/nowa_sekcja/e1f9ddbe-gr32-repo/projekt/cmake-build-debug /home/nixen/Projects/uczelnia/PPK/github_repo/nowa_sekcja/e1f9ddbe-gr32-repo/projekt/cmake-build-debug/CMakeFiles/projekt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projekt.dir/depend

