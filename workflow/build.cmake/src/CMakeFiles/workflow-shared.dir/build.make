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
include src/CMakeFiles/workflow-shared.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/workflow-shared.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/workflow-shared.dir/flags.make

# Object files for target workflow-shared
workflow__shared_OBJECTS =

# External object files for target workflow-shared
workflow__shared_EXTERNAL_OBJECTS = \
"/home/liutao/workflow/build.cmake/src/kernel/CMakeFiles/kernel.dir/IOService_linux.cc.o" \
"/home/liutao/workflow/build.cmake/src/kernel/CMakeFiles/kernel.dir/mpoller.c.o" \
"/home/liutao/workflow/build.cmake/src/kernel/CMakeFiles/kernel.dir/poller.c.o" \
"/home/liutao/workflow/build.cmake/src/kernel/CMakeFiles/kernel.dir/rbtree.c.o" \
"/home/liutao/workflow/build.cmake/src/kernel/CMakeFiles/kernel.dir/msgqueue.c.o" \
"/home/liutao/workflow/build.cmake/src/kernel/CMakeFiles/kernel.dir/thrdpool.c.o" \
"/home/liutao/workflow/build.cmake/src/kernel/CMakeFiles/kernel.dir/CommRequest.cc.o" \
"/home/liutao/workflow/build.cmake/src/kernel/CMakeFiles/kernel.dir/CommScheduler.cc.o" \
"/home/liutao/workflow/build.cmake/src/kernel/CMakeFiles/kernel.dir/Communicator.cc.o" \
"/home/liutao/workflow/build.cmake/src/kernel/CMakeFiles/kernel.dir/Executor.cc.o" \
"/home/liutao/workflow/build.cmake/src/kernel/CMakeFiles/kernel.dir/SubTask.cc.o" \
"/home/liutao/workflow/build.cmake/src/util/CMakeFiles/util.dir/json_parser.c.o" \
"/home/liutao/workflow/build.cmake/src/util/CMakeFiles/util.dir/EncodeStream.cc.o" \
"/home/liutao/workflow/build.cmake/src/util/CMakeFiles/util.dir/StringUtil.cc.o" \
"/home/liutao/workflow/build.cmake/src/util/CMakeFiles/util.dir/URIParser.cc.o" \
"/home/liutao/workflow/build.cmake/src/manager/CMakeFiles/manager.dir/DnsCache.cc.o" \
"/home/liutao/workflow/build.cmake/src/manager/CMakeFiles/manager.dir/RouteManager.cc.o" \
"/home/liutao/workflow/build.cmake/src/manager/CMakeFiles/manager.dir/WFGlobal.cc.o" \
"/home/liutao/workflow/build.cmake/src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.o" \
"/home/liutao/workflow/build.cmake/src/algorithm/CMakeFiles/algorithm.dir/DnsRoutine.cc.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/PackageWrapper.cc.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/SSLWrapper.cc.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/dns_parser.c.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/DnsMessage.cc.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/DnsUtil.cc.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/http_parser.c.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/HttpMessage.cc.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/HttpUtil.cc.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/mysql_stream.c.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/mysql_parser.c.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/mysql_byteorder.c.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/MySQLMessage.cc.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/MySQLResult.cc.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/MySQLUtil.cc.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/redis_parser.c.o" \
"/home/liutao/workflow/build.cmake/src/protocol/CMakeFiles/protocol.dir/RedisMessage.cc.o" \
"/home/liutao/workflow/build.cmake/src/factory/CMakeFiles/factory.dir/WFGraphTask.cc.o" \
"/home/liutao/workflow/build.cmake/src/factory/CMakeFiles/factory.dir/DnsTaskImpl.cc.o" \
"/home/liutao/workflow/build.cmake/src/factory/CMakeFiles/factory.dir/WFTaskFactory.cc.o" \
"/home/liutao/workflow/build.cmake/src/factory/CMakeFiles/factory.dir/Workflow.cc.o" \
"/home/liutao/workflow/build.cmake/src/factory/CMakeFiles/factory.dir/HttpTaskImpl.cc.o" \
"/home/liutao/workflow/build.cmake/src/factory/CMakeFiles/factory.dir/WFResourcePool.cc.o" \
"/home/liutao/workflow/build.cmake/src/factory/CMakeFiles/factory.dir/WFMessageQueue.cc.o" \
"/home/liutao/workflow/build.cmake/src/factory/CMakeFiles/factory.dir/FileTaskImpl.cc.o" \
"/home/liutao/workflow/build.cmake/src/factory/CMakeFiles/factory.dir/MySQLTaskImpl.cc.o" \
"/home/liutao/workflow/build.cmake/src/factory/CMakeFiles/factory.dir/RedisTaskImpl.cc.o" \
"/home/liutao/workflow/build.cmake/src/nameservice/CMakeFiles/nameservice.dir/WFNameService.cc.o" \
"/home/liutao/workflow/build.cmake/src/nameservice/CMakeFiles/nameservice.dir/WFDnsResolver.cc.o" \
"/home/liutao/workflow/build.cmake/src/nameservice/CMakeFiles/nameservice.dir/WFServiceGovernance.cc.o" \
"/home/liutao/workflow/build.cmake/src/nameservice/CMakeFiles/nameservice.dir/UpstreamPolicies.cc.o" \
"/home/liutao/workflow/build.cmake/src/server/CMakeFiles/server.dir/WFServer.cc.o" \
"/home/liutao/workflow/build.cmake/src/server/CMakeFiles/server.dir/WFMySQLServer.cc.o" \
"/home/liutao/workflow/build.cmake/src/client/CMakeFiles/client.dir/WFDnsClient.cc.o" \
"/home/liutao/workflow/build.cmake/src/client/CMakeFiles/client.dir/WFMySQLConnection.cc.o" \
"/home/liutao/workflow/build.cmake/src/client/CMakeFiles/client.dir/WFConsulClient.cc.o"

../_lib/libworkflow.so.0.10.4: src/kernel/CMakeFiles/kernel.dir/IOService_linux.cc.o
../_lib/libworkflow.so.0.10.4: src/kernel/CMakeFiles/kernel.dir/mpoller.c.o
../_lib/libworkflow.so.0.10.4: src/kernel/CMakeFiles/kernel.dir/poller.c.o
../_lib/libworkflow.so.0.10.4: src/kernel/CMakeFiles/kernel.dir/rbtree.c.o
../_lib/libworkflow.so.0.10.4: src/kernel/CMakeFiles/kernel.dir/msgqueue.c.o
../_lib/libworkflow.so.0.10.4: src/kernel/CMakeFiles/kernel.dir/thrdpool.c.o
../_lib/libworkflow.so.0.10.4: src/kernel/CMakeFiles/kernel.dir/CommRequest.cc.o
../_lib/libworkflow.so.0.10.4: src/kernel/CMakeFiles/kernel.dir/CommScheduler.cc.o
../_lib/libworkflow.so.0.10.4: src/kernel/CMakeFiles/kernel.dir/Communicator.cc.o
../_lib/libworkflow.so.0.10.4: src/kernel/CMakeFiles/kernel.dir/Executor.cc.o
../_lib/libworkflow.so.0.10.4: src/kernel/CMakeFiles/kernel.dir/SubTask.cc.o
../_lib/libworkflow.so.0.10.4: src/util/CMakeFiles/util.dir/json_parser.c.o
../_lib/libworkflow.so.0.10.4: src/util/CMakeFiles/util.dir/EncodeStream.cc.o
../_lib/libworkflow.so.0.10.4: src/util/CMakeFiles/util.dir/StringUtil.cc.o
../_lib/libworkflow.so.0.10.4: src/util/CMakeFiles/util.dir/URIParser.cc.o
../_lib/libworkflow.so.0.10.4: src/manager/CMakeFiles/manager.dir/DnsCache.cc.o
../_lib/libworkflow.so.0.10.4: src/manager/CMakeFiles/manager.dir/RouteManager.cc.o
../_lib/libworkflow.so.0.10.4: src/manager/CMakeFiles/manager.dir/WFGlobal.cc.o
../_lib/libworkflow.so.0.10.4: src/manager/CMakeFiles/manager.dir/UpstreamManager.cc.o
../_lib/libworkflow.so.0.10.4: src/algorithm/CMakeFiles/algorithm.dir/DnsRoutine.cc.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/PackageWrapper.cc.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/SSLWrapper.cc.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/dns_parser.c.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/DnsMessage.cc.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/DnsUtil.cc.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/http_parser.c.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/HttpMessage.cc.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/HttpUtil.cc.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/mysql_stream.c.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/mysql_parser.c.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/mysql_byteorder.c.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/MySQLMessage.cc.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/MySQLResult.cc.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/MySQLUtil.cc.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/redis_parser.c.o
../_lib/libworkflow.so.0.10.4: src/protocol/CMakeFiles/protocol.dir/RedisMessage.cc.o
../_lib/libworkflow.so.0.10.4: src/factory/CMakeFiles/factory.dir/WFGraphTask.cc.o
../_lib/libworkflow.so.0.10.4: src/factory/CMakeFiles/factory.dir/DnsTaskImpl.cc.o
../_lib/libworkflow.so.0.10.4: src/factory/CMakeFiles/factory.dir/WFTaskFactory.cc.o
../_lib/libworkflow.so.0.10.4: src/factory/CMakeFiles/factory.dir/Workflow.cc.o
../_lib/libworkflow.so.0.10.4: src/factory/CMakeFiles/factory.dir/HttpTaskImpl.cc.o
../_lib/libworkflow.so.0.10.4: src/factory/CMakeFiles/factory.dir/WFResourcePool.cc.o
../_lib/libworkflow.so.0.10.4: src/factory/CMakeFiles/factory.dir/WFMessageQueue.cc.o
../_lib/libworkflow.so.0.10.4: src/factory/CMakeFiles/factory.dir/FileTaskImpl.cc.o
../_lib/libworkflow.so.0.10.4: src/factory/CMakeFiles/factory.dir/MySQLTaskImpl.cc.o
../_lib/libworkflow.so.0.10.4: src/factory/CMakeFiles/factory.dir/RedisTaskImpl.cc.o
../_lib/libworkflow.so.0.10.4: src/nameservice/CMakeFiles/nameservice.dir/WFNameService.cc.o
../_lib/libworkflow.so.0.10.4: src/nameservice/CMakeFiles/nameservice.dir/WFDnsResolver.cc.o
../_lib/libworkflow.so.0.10.4: src/nameservice/CMakeFiles/nameservice.dir/WFServiceGovernance.cc.o
../_lib/libworkflow.so.0.10.4: src/nameservice/CMakeFiles/nameservice.dir/UpstreamPolicies.cc.o
../_lib/libworkflow.so.0.10.4: src/server/CMakeFiles/server.dir/WFServer.cc.o
../_lib/libworkflow.so.0.10.4: src/server/CMakeFiles/server.dir/WFMySQLServer.cc.o
../_lib/libworkflow.so.0.10.4: src/client/CMakeFiles/client.dir/WFDnsClient.cc.o
../_lib/libworkflow.so.0.10.4: src/client/CMakeFiles/client.dir/WFMySQLConnection.cc.o
../_lib/libworkflow.so.0.10.4: src/client/CMakeFiles/client.dir/WFConsulClient.cc.o
../_lib/libworkflow.so.0.10.4: src/CMakeFiles/workflow-shared.dir/build.make
../_lib/libworkflow.so.0.10.4: /usr/lib64/libssl.so
../_lib/libworkflow.so.0.10.4: /usr/lib64/libcrypto.so
../_lib/libworkflow.so.0.10.4: src/CMakeFiles/workflow-shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liutao/workflow/build.cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX shared library ../../_lib/libworkflow.so"
	cd /home/liutao/workflow/build.cmake/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/workflow-shared.dir/link.txt --verbose=$(VERBOSE)
	cd /home/liutao/workflow/build.cmake/src && $(CMAKE_COMMAND) -E cmake_symlink_library ../../_lib/libworkflow.so.0.10.4 ../../_lib/libworkflow.so.0 ../../_lib/libworkflow.so

../_lib/libworkflow.so.0: ../_lib/libworkflow.so.0.10.4
	@$(CMAKE_COMMAND) -E touch_nocreate ../_lib/libworkflow.so.0

../_lib/libworkflow.so: ../_lib/libworkflow.so.0.10.4
	@$(CMAKE_COMMAND) -E touch_nocreate ../_lib/libworkflow.so

# Rule to build all files generated by this target.
src/CMakeFiles/workflow-shared.dir/build: ../_lib/libworkflow.so

.PHONY : src/CMakeFiles/workflow-shared.dir/build

src/CMakeFiles/workflow-shared.dir/requires:

.PHONY : src/CMakeFiles/workflow-shared.dir/requires

src/CMakeFiles/workflow-shared.dir/clean:
	cd /home/liutao/workflow/build.cmake/src && $(CMAKE_COMMAND) -P CMakeFiles/workflow-shared.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/workflow-shared.dir/clean

src/CMakeFiles/workflow-shared.dir/depend:
	cd /home/liutao/workflow/build.cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liutao/workflow /home/liutao/workflow/src /home/liutao/workflow/build.cmake /home/liutao/workflow/build.cmake/src /home/liutao/workflow/build.cmake/src/CMakeFiles/workflow-shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/workflow-shared.dir/depend

