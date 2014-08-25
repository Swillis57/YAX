# Install script for directory: C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/Libraries/glfw304

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/GLFW")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/Libraries/glfw304/include/GLFW" FILES_MATCHING REGEX "/glfw3\\.h$" REGEX "/glfw3native\\.h$")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/glfw" TYPE FILE FILES
    "C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/Libraries/glfw304/bin/src/glfwConfig.cmake"
    "C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/Libraries/glfw304/bin/src/glfwConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/Libraries/glfw304/bin/src/cmake_install.cmake")
  include("C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/Libraries/glfw304/bin/examples/cmake_install.cmake")
  include("C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/Libraries/glfw304/bin/tests/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

file(WRITE "C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/Libraries/glfw304/bin/${CMAKE_INSTALL_MANIFEST}" "")
foreach(file ${CMAKE_INSTALL_MANIFEST_FILES})
  file(APPEND "C:/Users/Sam/Documents/Visual Studio 2013/Projects/XNA++/Libraries/glfw304/bin/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
endforeach()
