# Install script for directory: C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/external/glew

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX ".")
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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/Framework/include/GL/glew.h;C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/Framework/include/GL/glxew.h;C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/Framework/include/GL/wglew.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/Framework/include/GL" TYPE FILE FILES
    "C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/external/glew/include/GL/glew.h"
    "C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/external/glew/include/GL/glxew.h"
    "C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/external/glew/include/GL/wglew.h"
    )
endif()

