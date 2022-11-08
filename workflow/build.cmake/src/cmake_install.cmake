# Install script for directory: /home/liutao/workflow/src

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE STATIC_LIBRARY FILES "/home/liutao/workflow/_lib/libworkflow.a")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "devel" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libworkflow.so.0.10.4"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libworkflow.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libworkflow.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE SHARED_LIBRARY FILES
    "/home/liutao/workflow/_lib/libworkflow.so.0.10.4"
    "/home/liutao/workflow/_lib/libworkflow.so.0"
    "/home/liutao/workflow/_lib/libworkflow.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libworkflow.so.0.10.4"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libworkflow.so.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/libworkflow.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/opt/rh/devtoolset-9/root/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/liutao/workflow/build.cmake/src/kernel/cmake_install.cmake")
  include("/home/liutao/workflow/build.cmake/src/util/cmake_install.cmake")
  include("/home/liutao/workflow/build.cmake/src/manager/cmake_install.cmake")
  include("/home/liutao/workflow/build.cmake/src/algorithm/cmake_install.cmake")
  include("/home/liutao/workflow/build.cmake/src/protocol/cmake_install.cmake")
  include("/home/liutao/workflow/build.cmake/src/factory/cmake_install.cmake")
  include("/home/liutao/workflow/build.cmake/src/nameservice/cmake_install.cmake")
  include("/home/liutao/workflow/build.cmake/src/server/cmake_install.cmake")
  include("/home/liutao/workflow/build.cmake/src/client/cmake_install.cmake")

endif()

