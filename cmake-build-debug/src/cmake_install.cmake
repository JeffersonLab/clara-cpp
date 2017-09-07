# Install script for directory: /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/src

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
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/src/libclara.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libclara.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libclara.dylib")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -add_rpath "/usr/local/lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libclara.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libclara.dylib")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clara/third_party/dropbox" TYPE FILE FILES "/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/src/third_party/dropbox/json11.hpp")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/include/clara")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/src/c_dpe")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/c_dpe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/c_dpe")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -delete_rpath "/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/src"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/c_dpe")
    execute_process(COMMAND /opt/local/bin/install_name_tool
      -add_rpath "/usr/local/lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/c_dpe")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/c_dpe")
    endif()
  endif()
endif()

