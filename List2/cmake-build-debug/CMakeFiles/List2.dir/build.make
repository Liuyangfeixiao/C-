# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2018.2.6\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2018.2.6\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\CLion 2018.2.6\CLion 2019.1.2\project\List2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\CLion 2018.2.6\CLion 2019.1.2\project\List2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/List2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/List2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/List2.dir/flags.make

CMakeFiles/List2.dir/main.cpp.obj: CMakeFiles/List2.dir/flags.make
CMakeFiles/List2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CLion 2018.2.6\CLion 2019.1.2\project\List2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/List2.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\List2.dir\main.cpp.obj -c "D:\CLion 2018.2.6\CLion 2019.1.2\project\List2\main.cpp"

CMakeFiles/List2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/List2.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\CLion 2018.2.6\CLion 2019.1.2\project\List2\main.cpp" > CMakeFiles\List2.dir\main.cpp.i

CMakeFiles/List2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/List2.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\CLion 2018.2.6\CLion 2019.1.2\project\List2\main.cpp" -o CMakeFiles\List2.dir\main.cpp.s

# Object files for target List2
List2_OBJECTS = \
"CMakeFiles/List2.dir/main.cpp.obj"

# External object files for target List2
List2_EXTERNAL_OBJECTS =

List2.exe: CMakeFiles/List2.dir/main.cpp.obj
List2.exe: CMakeFiles/List2.dir/build.make
List2.exe: CMakeFiles/List2.dir/linklibs.rsp
List2.exe: CMakeFiles/List2.dir/objects1.rsp
List2.exe: CMakeFiles/List2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\CLion 2018.2.6\CLion 2019.1.2\project\List2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable List2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\List2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/List2.dir/build: List2.exe

.PHONY : CMakeFiles/List2.dir/build

CMakeFiles/List2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\List2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/List2.dir/clean

CMakeFiles/List2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\CLion 2018.2.6\CLion 2019.1.2\project\List2" "D:\CLion 2018.2.6\CLion 2019.1.2\project\List2" "D:\CLion 2018.2.6\CLion 2019.1.2\project\List2\cmake-build-debug" "D:\CLion 2018.2.6\CLion 2019.1.2\project\List2\cmake-build-debug" "D:\CLion 2018.2.6\CLion 2019.1.2\project\List2\cmake-build-debug\CMakeFiles\List2.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/List2.dir/depend
