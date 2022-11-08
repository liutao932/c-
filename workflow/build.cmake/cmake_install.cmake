# Install script for directory: /home/liutao/workflow

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/workflow" TYPE FILE RENAME "workflow-config.cmake" FILES "/home/liutao/workflow/build.cmake/config.toinstall.cmake")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/cmake/workflow" TYPE FILE FILES "/home/liutao/workflow/build.cmake/workflow-config-version.cmake")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/workflow" TYPE FILE FILES
    "/home/liutao/workflow/src/algorithm/DnsRoutine.h"
    "/home/liutao/workflow/src/algorithm/MapReduce.h"
    "/home/liutao/workflow/src/algorithm/MapReduce.inl"
    "/home/liutao/workflow/src/protocol/ProtocolMessage.h"
    "/home/liutao/workflow/src/protocol/http_parser.h"
    "/home/liutao/workflow/src/protocol/HttpMessage.h"
    "/home/liutao/workflow/src/protocol/HttpUtil.h"
    "/home/liutao/workflow/src/protocol/redis_parser.h"
    "/home/liutao/workflow/src/protocol/RedisMessage.h"
    "/home/liutao/workflow/src/protocol/mysql_stream.h"
    "/home/liutao/workflow/src/protocol/MySQLMessage.h"
    "/home/liutao/workflow/src/protocol/MySQLMessage.inl"
    "/home/liutao/workflow/src/protocol/MySQLResult.h"
    "/home/liutao/workflow/src/protocol/MySQLResult.inl"
    "/home/liutao/workflow/src/protocol/MySQLUtil.h"
    "/home/liutao/workflow/src/protocol/mysql_parser.h"
    "/home/liutao/workflow/src/protocol/mysql_types.h"
    "/home/liutao/workflow/src/protocol/mysql_byteorder.h"
    "/home/liutao/workflow/src/protocol/PackageWrapper.h"
    "/home/liutao/workflow/src/protocol/SSLWrapper.h"
    "/home/liutao/workflow/src/protocol/dns_parser.h"
    "/home/liutao/workflow/src/protocol/DnsMessage.h"
    "/home/liutao/workflow/src/protocol/DnsUtil.h"
    "/home/liutao/workflow/src/protocol/ConsulDataTypes.h"
    "/home/liutao/workflow/src/server/WFServer.h"
    "/home/liutao/workflow/src/server/WFDnsServer.h"
    "/home/liutao/workflow/src/server/WFHttpServer.h"
    "/home/liutao/workflow/src/server/WFRedisServer.h"
    "/home/liutao/workflow/src/server/WFMySQLServer.h"
    "/home/liutao/workflow/src/client/WFMySQLConnection.h"
    "/home/liutao/workflow/src/client/WFConsulClient.h"
    "/home/liutao/workflow/src/client/WFDnsClient.h"
    "/home/liutao/workflow/src/manager/DnsCache.h"
    "/home/liutao/workflow/src/manager/WFGlobal.h"
    "/home/liutao/workflow/src/manager/UpstreamManager.h"
    "/home/liutao/workflow/src/manager/RouteManager.h"
    "/home/liutao/workflow/src/manager/EndpointParams.h"
    "/home/liutao/workflow/src/manager/WFFuture.h"
    "/home/liutao/workflow/src/manager/WFFacilities.h"
    "/home/liutao/workflow/src/manager/WFFacilities.inl"
    "/home/liutao/workflow/src/util/json_parser.h"
    "/home/liutao/workflow/src/util/EncodeStream.h"
    "/home/liutao/workflow/src/util/LRUCache.h"
    "/home/liutao/workflow/src/util/StringUtil.h"
    "/home/liutao/workflow/src/util/URIParser.h"
    "/home/liutao/workflow/src/factory/WFConnection.h"
    "/home/liutao/workflow/src/factory/WFTask.h"
    "/home/liutao/workflow/src/factory/WFTask.inl"
    "/home/liutao/workflow/src/factory/WFGraphTask.h"
    "/home/liutao/workflow/src/factory/WFTaskError.h"
    "/home/liutao/workflow/src/factory/WFTaskFactory.h"
    "/home/liutao/workflow/src/factory/WFTaskFactory.inl"
    "/home/liutao/workflow/src/factory/WFAlgoTaskFactory.h"
    "/home/liutao/workflow/src/factory/WFAlgoTaskFactory.inl"
    "/home/liutao/workflow/src/factory/Workflow.h"
    "/home/liutao/workflow/src/factory/WFOperator.h"
    "/home/liutao/workflow/src/factory/WFResourcePool.h"
    "/home/liutao/workflow/src/factory/WFMessageQueue.h"
    "/home/liutao/workflow/src/nameservice/WFNameService.h"
    "/home/liutao/workflow/src/nameservice/WFDnsResolver.h"
    "/home/liutao/workflow/src/nameservice/WFServiceGovernance.h"
    "/home/liutao/workflow/src/nameservice/UpstreamPolicies.h"
    "/home/liutao/workflow/src/kernel/CommRequest.h"
    "/home/liutao/workflow/src/kernel/CommScheduler.h"
    "/home/liutao/workflow/src/kernel/Communicator.h"
    "/home/liutao/workflow/src/kernel/SleepRequest.h"
    "/home/liutao/workflow/src/kernel/ExecRequest.h"
    "/home/liutao/workflow/src/kernel/IORequest.h"
    "/home/liutao/workflow/src/kernel/Executor.h"
    "/home/liutao/workflow/src/kernel/list.h"
    "/home/liutao/workflow/src/kernel/mpoller.h"
    "/home/liutao/workflow/src/kernel/poller.h"
    "/home/liutao/workflow/src/kernel/msgqueue.h"
    "/home/liutao/workflow/src/kernel/rbtree.h"
    "/home/liutao/workflow/src/kernel/SubTask.h"
    "/home/liutao/workflow/src/kernel/thrdpool.h"
    "/home/liutao/workflow/src/kernel/IOService_linux.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/workflow-0.10.4" TYPE FILE FILES "/home/liutao/workflow/README.md")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/liutao/workflow/build.cmake/src/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/liutao/workflow/build.cmake/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
