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
CMAKE_SOURCE_DIR = /home/liutao/workflow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liutao/workflow/build.cmake

# Include any dependencies generated for this target.
include src/manager/CMakeFiles/manager.dir/depend.make

# Include the progress variables for this target.
include src/manager/CMakeFiles/manager.dir/progress.make

# Include the compile flags for this target's objects.
include src/manager/CMakeFiles/manager.dir/flags.make

src/manager/CMakeFiles/manager.dir/DnsCache.cc.o: src/manager/CMakeFiles/manager.dir/flags.make
src/manager/CMakeFiles/manager.dir/DnsCache.cc.o: ../src/manager/DnsCache.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liutao/workflow/build.cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/manager/CMakeFiles/manager.dir/DnsCache.cc.o"
	cd /home/liutao/workflow/build.cmake/src/manager && /opt/rh/devtoolset-9/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/manager.dir/DnsCache.cc.o -c /home/liutao/workflow/src/manager/DnsCache.cc

src/manager/CMakeFiles/manager.dir/DnsCache.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/manager.dir/DnsCache.cc.i"
	cd /home/liutao/workflow/build.cmake/src/manager && /opt/rh/devtoolset-9/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liutao/workflow/src/manager/DnsCache.cc > CMakeFiles/manager.dir/DnsCache.cc.i

src/manager/CMakeFiles/manager.dir/DnsCache.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/manager.dir/DnsCache.cc.s"
	cd /home/liutao/workflow/build.cmake/src/manager && /opt/rh/devtoolset-9/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liutao/workflow/src/manager/DnsCache.cc -o CMakeFiles/manager.dir/DnsCache.cc.s

src/manager/CMakeFiles/manager.dir/DnsCache.cc.o.requires:

.PHONY : src/manager/CMakeFiles/manager.dir/DnsCache.cc.o.requires

src/manager/CMakeFiles/manager.dir/DnsCache.cc.o.provides: src/manager/CMakeFiles/manager.dir/DnsCache.cc.o.requires
	$(MAKE) -f src/manager/CMakeFiles/manager.dir/build.make src/manager/CMakeFiles/manager.dir/DnsCache.cc.o.provides.build
.PHONY : src/manager/CMakeFiles/manager.dir/DnsCache.cc.o.provides

src/manager/CMakeFiles/manager.dir/DnsCache.cc.o.provides.build: src/manager/CMakeFiles/manager.dir/DnsCache.cc.o


src/manager/CMakeFiles/manager.dir/RouteManager.cc.o: src/manager/CMakeFiles/manager.dir/flags.make
src/manager/CMakeFiles/manager.dir/RouteManager.cc.o: ../src/manager/RouteManager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liutao/workflow/build.cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/manager/CMakeFiles/manager.dir/RouteManager.cc.o"
	cd /home/liutao/workflow/build.cmake/src/manager && /opt/rh/devtoolset-9/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/manager.dir/RouteManager.cc.o -c /home/liutao/workflow/src/manager/RouteManager.cc

src/manager/CMakeFiles/manager.dir/RouteManager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/manager.dir/RouteManager.cc.i"
	cd /home/liutao/workflow/build.cmake/src/manager && /opt/rh/devtoolset-9/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liutao/workflow/src/manager/RouteManager.cc > CMakeFiles/manager.dir/RouteManager.cc.i

src/manager/CMakeFiles/manager.dir/RouteManager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/manager.dir/RouteManager.cc.s"
	cd /home/liutao/workflow/build.cmake/src/manager && /opt/rh/devtoolset-9/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liutao/workflow/src/manager/RouteManager.cc -o CMakeFiles/manager.dir/RouteManager.cc.s

src/manager/CMakeFiles/manager.dir/RouteManager.cc.o.requires:

.PHONY : src/manager/CMakeFiles/manager.dir/RouteManager.cc.o.requires

src/manager/CMakeFiles/manager.dir/RouteManager.cc.o.provides: src/manager/CMakeFiles/manager.dir/RouteManager.cc.o.requires
	$(MAKE) -f src/manager/CMakeFiles/manager.dir/build.make src/manager/CMakeFiles/manager.dir/RouteManager.cc.o.provides.build
.PHONY : src/manager/CMakeFiles/manager.dir/RouteManager.cc.o.provides

src/manager/CMakeFiles/manager.dir/RouteManager.cc.o.provides.build: src/manager/CMakeFiles/manager.dir/RouteManager.cc.o


src/manager/CMakeFiles/manager.dir/WFGlobal.cc.o: src/manager/CMakeFiles/manager.dir/flags.make
src/manager/CMakeFiles/manager.dir/WFGlobal.cc.o: ../src/manager/WFGlobal.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liutao/workflow/build.cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/manager/CMakeFiles/manager.dir/WFGlobal.cc.o"
	cd /home/liutao/workflow/build.cmake/src/manager && /opt/rh/devtoolset-9/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/manager.dir/WFGlobal.cc.o -c /home/liutao/workflow/src/manager/WFGlobal.cc

src/manager/CMakeFiles/manager.dir/WFGlobal.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/manager.dir/WFGlobal.cc.i"
	cd /home/liutao/workflow/build.cmake/src/manager && /opt/rh/devtoolset-9/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liutao/workflow/src/manager/WFGlobal.cc > CMakeFiles/manager.dir/WFGlobal.cc.i

src/manager/CMakeFiles/manager.dir/WFGlobal.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/manager.dir/WFGlobal.cc.s"
	cd /home/liutao/workflow/build.cmake/src/manager && /opt/rh/devtoolset-9/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liutao/workflow/src/manager/WFGlobal.cc -o CMakeFiles/manager.dir/WFGlobal.cc.s

src/manager/CMakeFiles/manager.dir/WFGlobal.cc.o.requires:

.PHONY : src/manager/CMakeFiles/manager.dir/WFGlobal.cc.o.requires

src/manager/CMakeFiles/manager.dir/WFGlobal.cc.o.provides: src/manager/CMakeFiles/manager.dir/WFGlobal.cc.o.requires
	$(MAKE) -f src/manager/CMakeFiles/manager.dir/build.make src/manager/CMakeFiles/manager.dir/WFGlobal.cc.o.provides.build
.PHONY : src/manager/CMakeFiles/manager.dir/WFGlobal.cc.o.provides

src/manager/CMakeFiles/manager.dir/WFGlobal.cc.o.provides.build: src/manager/CMakeFiles/manager.dir/WFGlobal.cc.o


src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.o: src/manager/CMakeFiles/manager.dir/flags.make
src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.o: ../src/manager/UpstreamManager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liutao/workflow/build.cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.o"
	cd /home/liutao/workflow/build.cmake/src/manager && /opt/rh/devtoolset-9/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/manager.dir/UpstreamManager.cc.o -c /home/liutao/workflow/src/manager/UpstreamManager.cc

src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/manager.dir/UpstreamManager.cc.i"
	cd /home/liutao/workflow/build.cmake/src/manager && /opt/rh/devtoolset-9/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liutao/workflow/src/manager/UpstreamManager.cc > CMakeFiles/manager.dir/UpstreamManager.cc.i

src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/manager.dir/UpstreamManager.cc.s"
	cd /home/liutao/workflow/build.cmake/src/manager && /opt/rh/devtoolset-9/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liutao/workflow/src/manager/UpstreamManager.cc -o CMakeFiles/manager.dir/UpstreamManager.cc.s

src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.o.requires:

.PHONY : src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.o.requires

src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.o.provides: src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.o.requires
	$(MAKE) -f src/manager/CMakeFiles/manager.dir/build.make src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.o.provides.build
.PHONY : src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.o.provides

src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.o.provides.build: src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.o


manager: src/manager/CMakeFiles/manager.dir/DnsCache.cc.o
manager: src/manager/CMakeFiles/manager.dir/RouteManager.cc.o
manager: src/manager/CMakeFiles/manager.dir/WFGlobal.cc.o
manager: src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.o
manager: src/manager/CMakeFiles/manager.dir/build.make

.PHONY : manager

# Rule to build all files generated by this target.
src/manager/CMakeFiles/manager.dir/build: manager

.PHONY : src/manager/CMakeFiles/manager.dir/build

src/manager/CMakeFiles/manager.dir/requires: src/manager/CMakeFiles/manager.dir/DnsCache.cc.o.requires
src/manager/CMakeFiles/manager.dir/requires: src/manager/CMakeFiles/manager.dir/RouteManager.cc.o.requires
src/manager/CMakeFiles/manager.dir/requires: src/manager/CMakeFiles/manager.dir/WFGlobal.cc.o.requires
src/manager/CMakeFiles/manager.dir/requires: src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.o.requires

.PHONY : src/manager/CMakeFiles/manager.dir/requires

src/manager/CMakeFiles/manager.dir/clean:
	cd /home/liutao/workflow/build.cmake/src/manager && $(CMAKE_COMMAND) -P CMakeFiles/manager.dir/cmake_clean.cmake
.PHONY : src/manager/CMakeFiles/manager.dir/clean

src/manager/CMakeFiles/manager.dir/depend:
	cd /home/liutao/workflow/build.cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liutao/workflow /home/liutao/workflow/src/manager /home/liutao/workflow/build.cmake /home/liutao/workflow/build.cmake/src/manager /home/liutao/workflow/build.cmake/src/manager/CMakeFiles/manager.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/manager/CMakeFiles/manager.dir/depend
