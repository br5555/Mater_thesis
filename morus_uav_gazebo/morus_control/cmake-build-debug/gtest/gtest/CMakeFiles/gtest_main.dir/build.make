# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/osboxes/ros_ws/src/morus_uav_gazebo/morus_control

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/osboxes/ros_ws/src/morus_uav_gazebo/morus_control/cmake-build-debug

# Include any dependencies generated for this target.
include gtest/gtest/CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include gtest/gtest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include gtest/gtest/CMakeFiles/gtest_main.dir/flags.make

gtest/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: gtest/gtest/CMakeFiles/gtest_main.dir/flags.make
gtest/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: /usr/src/gtest/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/osboxes/ros_ws/src/morus_uav_gazebo/morus_control/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object gtest/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd /home/osboxes/ros_ws/src/morus_uav_gazebo/morus_control/cmake-build-debug/gtest/gtest && /usr/lib/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c /usr/src/gtest/src/gtest_main.cc

gtest/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /home/osboxes/ros_ws/src/morus_uav_gazebo/morus_control/cmake-build-debug/gtest/gtest && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/src/gtest/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

gtest/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /home/osboxes/ros_ws/src/morus_uav_gazebo/morus_control/cmake-build-debug/gtest/gtest && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/src/gtest/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

gtest/gtest/libgtest_main.so: gtest/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
gtest/gtest/libgtest_main.so: gtest/gtest/CMakeFiles/gtest_main.dir/build.make
gtest/gtest/libgtest_main.so: gtest/gtest/libgtest.so
gtest/gtest/libgtest_main.so: gtest/gtest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/osboxes/ros_ws/src/morus_uav_gazebo/morus_control/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libgtest_main.so"
	cd /home/osboxes/ros_ws/src/morus_uav_gazebo/morus_control/cmake-build-debug/gtest/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gtest/gtest/CMakeFiles/gtest_main.dir/build: gtest/gtest/libgtest_main.so

.PHONY : gtest/gtest/CMakeFiles/gtest_main.dir/build

gtest/gtest/CMakeFiles/gtest_main.dir/clean:
	cd /home/osboxes/ros_ws/src/morus_uav_gazebo/morus_control/cmake-build-debug/gtest/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : gtest/gtest/CMakeFiles/gtest_main.dir/clean

gtest/gtest/CMakeFiles/gtest_main.dir/depend:
	cd /home/osboxes/ros_ws/src/morus_uav_gazebo/morus_control/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/osboxes/ros_ws/src/morus_uav_gazebo/morus_control /usr/src/gtest /home/osboxes/ros_ws/src/morus_uav_gazebo/morus_control/cmake-build-debug /home/osboxes/ros_ws/src/morus_uav_gazebo/morus_control/cmake-build-debug/gtest/gtest /home/osboxes/ros_ws/src/morus_uav_gazebo/morus_control/cmake-build-debug/gtest/gtest/CMakeFiles/gtest_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gtest/gtest/CMakeFiles/gtest_main.dir/depend

