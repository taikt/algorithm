# Install script for directory: /home/tai/work/tmas/systemd/service/daemon

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  
    if(NOT EXISTS "$ENV{DESTDIR}/etc/daemon/daemon.conf")
      #file(INSTALL "/home/tai/work/tmas/systemd/service/daemon/./daemon.conf" DESTINATION "/etc/daemon")
      message(STATUS "Installing: $ENV{DESTDIR}/etc/daemon/daemon.conf")
      execute_process(COMMAND ${CMAKE_COMMAND} -E copy "/home/tai/work/tmas/systemd/service/daemon/./daemon.conf"
                      "$ENV{DESTDIR}/etc/daemon/daemon.conf"
                      RESULT_VARIABLE copy_result
                      ERROR_VARIABLE error_output)
      if(copy_result)
        message(FATAL_ERROR ${error_output})
      endif()
    else()
      message(STATUS "Skipping  : $ENV{DESTDIR}/etc/daemon/daemon.conf")
    endif()
  
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  
    if(NOT EXISTS "$ENV{DESTDIR}/etc/systemd/system//simple-daemon.service")
      #file(INSTALL "/home/tai/work/tmas/systemd/service/daemon/./simple-daemon.service" DESTINATION "/etc/systemd/system/")
      message(STATUS "Installing: $ENV{DESTDIR}/etc/systemd/system//simple-daemon.service")
      execute_process(COMMAND ${CMAKE_COMMAND} -E copy "/home/tai/work/tmas/systemd/service/daemon/./simple-daemon.service"
                      "$ENV{DESTDIR}/etc/systemd/system//simple-daemon.service"
                      RESULT_VARIABLE copy_result
                      ERROR_VARIABLE error_output)
      if(copy_result)
        message(FATAL_ERROR ${error_output})
      endif()
    else()
      message(STATUS "Skipping  : $ENV{DESTDIR}/etc/systemd/system//simple-daemon.service")
    endif()
  
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  
    if(NOT EXISTS "$ENV{DESTDIR}/etc/systemd/system//forking-daemon.service")
      #file(INSTALL "/home/tai/work/tmas/systemd/service/daemon/./forking-daemon.service" DESTINATION "/etc/systemd/system/")
      message(STATUS "Installing: $ENV{DESTDIR}/etc/systemd/system//forking-daemon.service")
      execute_process(COMMAND ${CMAKE_COMMAND} -E copy "/home/tai/work/tmas/systemd/service/daemon/./forking-daemon.service"
                      "$ENV{DESTDIR}/etc/systemd/system//forking-daemon.service"
                      RESULT_VARIABLE copy_result
                      ERROR_VARIABLE error_output)
      if(copy_result)
        message(FATAL_ERROR ${error_output})
      endif()
    else()
      message(STATUS "Skipping  : $ENV{DESTDIR}/etc/systemd/system//forking-daemon.service")
    endif()
  
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/tai/work/tmas/systemd/service/daemon/build/src/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/tai/work/tmas/systemd/service/daemon/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
