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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liutao/workflow/tutorial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liutao/workflow/tutorial/build.cmake

# Include any dependencies generated for this target.
include CMakeFiles/server-uds.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server-uds.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server-uds.dir/flags.make

CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.o: CMakeFiles/server-uds.dir/flags.make
CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.o: ../tutorial-10-user_defined_protocol/server-uds.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liutao/workflow/tutorial/build.cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.o"
	/opt/rh/devtoolset-9/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.o -c /home/liutao/workflow/tutorial/tutorial-10-user_defined_protocol/server-uds.cc

CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.i"
	/opt/rh/devtoolset-9/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liutao/workflow/tutorial/tutorial-10-user_defined_protocol/server-uds.cc > CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.i

CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.s"
	/opt/rh/devtoolset-9/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liutao/workflow/tutorial/tutorial-10-user_defined_protocol/server-uds.cc -o CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.s

CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.o.requires:

.PHONY : CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.o.requires

CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.o.provides: CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.o.requires
	$(MAKE) -f CMakeFiles/server-uds.dir/build.make CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.o.provides.build
.PHONY : CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.o.provides

CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.o.provides.build: CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.o


CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.o: CMakeFiles/server-uds.dir/flags.make
CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.o: ../tutorial-10-user_defined_protocol/message.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liutao/workflow/tutorial/build.cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.o"
	/opt/rh/devtoolset-9/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.o -c /home/liutao/workflow/tutorial/tutorial-10-user_defined_protocol/message.cc

CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.i"
	/opt/rh/devtoolset-9/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liutao/workflow/tutorial/tutorial-10-user_defined_protocol/message.cc > CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.i

CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.s"
	/opt/rh/devtoolset-9/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liutao/workflow/tutorial/tutorial-10-user_defined_protocol/message.cc -o CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.s

CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.o.requires:

.PHONY : CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.o.requires

CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.o.provides: CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.o.requires
	$(MAKE) -f CMakeFiles/server-uds.dir/build.make CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.o.provides.build
.PHONY : CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.o.provides

CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.o.provides.build: CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.o


# Object files for target server-uds
server__uds_OBJECTS = \
"CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.o" \
"CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.o"

# External object files for target server-uds
server__uds_EXTERNAL_OBJECTS =

../tutorial-10-user_defined_protocol/server-uds: CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.o
../tutorial-10-user_defined_protocol/server-uds: CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.o
../tutorial-10-user_defined_protocol/server-uds: CMakeFiles/server-uds.dir/build.make
../tutorial-10-user_defined_protocol/server-uds: /usr/lib64/libssl.so
../tutorial-10-user_defined_protocol/server-uds: /usr/lib64/libcrypto.so
../tutorial-10-user_defined_protocol/server-uds: /usr/lib64/librt.so
../tutorial-10-user_defined_protocol/server-uds: CMakeFiles/server-uds.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liutao/workflow/tutorial/build.cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../tutorial-10-user_defined_protocol/server-uds"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server-uds.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server-uds.dir/build: ../tutorial-10-user_defined_protocol/server-uds

.PHONY : CMakeFiles/server-uds.dir/build

CMakeFiles/server-uds.dir/requires: CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/server-uds.cc.o.requires
CMakeFiles/server-uds.dir/requires: CMakeFiles/server-uds.dir/tutorial-10-user_defined_protocol/message.cc.o.requires

.PHONY : CMakeFiles/server-uds.dir/requires

CMakeFiles/server-uds.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server-uds.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server-uds.dir/clean

CMakeFiles/server-uds.dir/depend:
	cd /home/liutao/workflow/tutorial/build.cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liutao/workflow/tutorial /home/liutao/workflow/tutorial /home/liutao/workflow/tutorial/build.cmake /home/liutao/workflow/tutorial/build.cmake /home/liutao/workflow/tutorial/build.cmake/CMakeFiles/server-uds.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server-uds.dir/depend
