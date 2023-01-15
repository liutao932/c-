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

# Utility rule file for LINK_HEADERS.

# Include the progress variables for this target.
include CMakeFiles/LINK_HEADERS.dir/progress.make

LINK_HEADERS: CMakeFiles/LINK_HEADERS.dir/build.make
	/usr/local/bin/cmake -E make_directory /home/liutao/workflow/_include/workflow
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/algorithm/DnsRoutine.h /home/liutao/workflow/_include/workflow/DnsRoutine.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/algorithm/MapReduce.h /home/liutao/workflow/_include/workflow/MapReduce.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/algorithm/MapReduce.inl /home/liutao/workflow/_include/workflow/MapReduce.inl
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/ProtocolMessage.h /home/liutao/workflow/_include/workflow/ProtocolMessage.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/http_parser.h /home/liutao/workflow/_include/workflow/http_parser.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/HttpMessage.h /home/liutao/workflow/_include/workflow/HttpMessage.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/HttpUtil.h /home/liutao/workflow/_include/workflow/HttpUtil.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/redis_parser.h /home/liutao/workflow/_include/workflow/redis_parser.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/RedisMessage.h /home/liutao/workflow/_include/workflow/RedisMessage.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/mysql_stream.h /home/liutao/workflow/_include/workflow/mysql_stream.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/MySQLMessage.h /home/liutao/workflow/_include/workflow/MySQLMessage.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/MySQLMessage.inl /home/liutao/workflow/_include/workflow/MySQLMessage.inl
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/MySQLResult.h /home/liutao/workflow/_include/workflow/MySQLResult.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/MySQLResult.inl /home/liutao/workflow/_include/workflow/MySQLResult.inl
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/MySQLUtil.h /home/liutao/workflow/_include/workflow/MySQLUtil.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/mysql_parser.h /home/liutao/workflow/_include/workflow/mysql_parser.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/mysql_types.h /home/liutao/workflow/_include/workflow/mysql_types.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/mysql_byteorder.h /home/liutao/workflow/_include/workflow/mysql_byteorder.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/PackageWrapper.h /home/liutao/workflow/_include/workflow/PackageWrapper.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/SSLWrapper.h /home/liutao/workflow/_include/workflow/SSLWrapper.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/dns_parser.h /home/liutao/workflow/_include/workflow/dns_parser.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/DnsMessage.h /home/liutao/workflow/_include/workflow/DnsMessage.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/DnsUtil.h /home/liutao/workflow/_include/workflow/DnsUtil.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/protocol/ConsulDataTypes.h /home/liutao/workflow/_include/workflow/ConsulDataTypes.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/server/WFServer.h /home/liutao/workflow/_include/workflow/WFServer.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/server/WFDnsServer.h /home/liutao/workflow/_include/workflow/WFDnsServer.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/server/WFHttpServer.h /home/liutao/workflow/_include/workflow/WFHttpServer.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/server/WFRedisServer.h /home/liutao/workflow/_include/workflow/WFRedisServer.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/server/WFMySQLServer.h /home/liutao/workflow/_include/workflow/WFMySQLServer.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/client/WFMySQLConnection.h /home/liutao/workflow/_include/workflow/WFMySQLConnection.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/client/WFConsulClient.h /home/liutao/workflow/_include/workflow/WFConsulClient.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/client/WFDnsClient.h /home/liutao/workflow/_include/workflow/WFDnsClient.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/manager/DnsCache.h /home/liutao/workflow/_include/workflow/DnsCache.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/manager/WFGlobal.h /home/liutao/workflow/_include/workflow/WFGlobal.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/manager/UpstreamManager.h /home/liutao/workflow/_include/workflow/UpstreamManager.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/manager/RouteManager.h /home/liutao/workflow/_include/workflow/RouteManager.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/manager/EndpointParams.h /home/liutao/workflow/_include/workflow/EndpointParams.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/manager/WFFuture.h /home/liutao/workflow/_include/workflow/WFFuture.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/manager/WFFacilities.h /home/liutao/workflow/_include/workflow/WFFacilities.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/manager/WFFacilities.inl /home/liutao/workflow/_include/workflow/WFFacilities.inl
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/util/json_parser.h /home/liutao/workflow/_include/workflow/json_parser.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/util/EncodeStream.h /home/liutao/workflow/_include/workflow/EncodeStream.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/util/LRUCache.h /home/liutao/workflow/_include/workflow/LRUCache.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/util/StringUtil.h /home/liutao/workflow/_include/workflow/StringUtil.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/util/URIParser.h /home/liutao/workflow/_include/workflow/URIParser.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/factory/WFConnection.h /home/liutao/workflow/_include/workflow/WFConnection.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/factory/WFTask.h /home/liutao/workflow/_include/workflow/WFTask.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/factory/WFTask.inl /home/liutao/workflow/_include/workflow/WFTask.inl
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/factory/WFGraphTask.h /home/liutao/workflow/_include/workflow/WFGraphTask.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/factory/WFTaskError.h /home/liutao/workflow/_include/workflow/WFTaskError.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/factory/WFTaskFactory.h /home/liutao/workflow/_include/workflow/WFTaskFactory.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/factory/WFTaskFactory.inl /home/liutao/workflow/_include/workflow/WFTaskFactory.inl
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/factory/WFAlgoTaskFactory.h /home/liutao/workflow/_include/workflow/WFAlgoTaskFactory.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/factory/WFAlgoTaskFactory.inl /home/liutao/workflow/_include/workflow/WFAlgoTaskFactory.inl
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/factory/Workflow.h /home/liutao/workflow/_include/workflow/Workflow.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/factory/WFOperator.h /home/liutao/workflow/_include/workflow/WFOperator.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/factory/WFResourcePool.h /home/liutao/workflow/_include/workflow/WFResourcePool.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/factory/WFMessageQueue.h /home/liutao/workflow/_include/workflow/WFMessageQueue.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/nameservice/WFNameService.h /home/liutao/workflow/_include/workflow/WFNameService.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/nameservice/WFDnsResolver.h /home/liutao/workflow/_include/workflow/WFDnsResolver.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/nameservice/WFServiceGovernance.h /home/liutao/workflow/_include/workflow/WFServiceGovernance.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/nameservice/UpstreamPolicies.h /home/liutao/workflow/_include/workflow/UpstreamPolicies.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/kernel/CommRequest.h /home/liutao/workflow/_include/workflow/CommRequest.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/kernel/CommScheduler.h /home/liutao/workflow/_include/workflow/CommScheduler.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/kernel/Communicator.h /home/liutao/workflow/_include/workflow/Communicator.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/kernel/SleepRequest.h /home/liutao/workflow/_include/workflow/SleepRequest.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/kernel/ExecRequest.h /home/liutao/workflow/_include/workflow/ExecRequest.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/kernel/IORequest.h /home/liutao/workflow/_include/workflow/IORequest.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/kernel/Executor.h /home/liutao/workflow/_include/workflow/Executor.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/kernel/list.h /home/liutao/workflow/_include/workflow/list.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/kernel/mpoller.h /home/liutao/workflow/_include/workflow/mpoller.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/kernel/poller.h /home/liutao/workflow/_include/workflow/poller.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/kernel/msgqueue.h /home/liutao/workflow/_include/workflow/msgqueue.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/kernel/rbtree.h /home/liutao/workflow/_include/workflow/rbtree.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/kernel/SubTask.h /home/liutao/workflow/_include/workflow/SubTask.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/kernel/thrdpool.h /home/liutao/workflow/_include/workflow/thrdpool.h
	/usr/local/bin/cmake -E copy_if_different /home/liutao/workflow/src/kernel/IOService_linux.h /home/liutao/workflow/_include/workflow/IOService_linux.h
.PHONY : LINK_HEADERS

# Rule to build all files generated by this target.
CMakeFiles/LINK_HEADERS.dir/build: LINK_HEADERS

.PHONY : CMakeFiles/LINK_HEADERS.dir/build

CMakeFiles/LINK_HEADERS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LINK_HEADERS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LINK_HEADERS.dir/clean

CMakeFiles/LINK_HEADERS.dir/depend:
	cd /home/liutao/workflow/build.cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liutao/workflow /home/liutao/workflow /home/liutao/workflow/build.cmake /home/liutao/workflow/build.cmake /home/liutao/workflow/build.cmake/CMakeFiles/LINK_HEADERS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LINK_HEADERS.dir/depend
