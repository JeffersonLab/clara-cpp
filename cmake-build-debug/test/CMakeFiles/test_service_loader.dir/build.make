# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/patrickhennis/Desktop/JLab/c++/clara-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/test_service_loader.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_service_loader.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_service_loader.dir/flags.make

test/CMakeFiles/test_service_loader.dir/service_loader_test.cpp.o: test/CMakeFiles/test_service_loader.dir/flags.make
test/CMakeFiles/test_service_loader.dir/service_loader_test.cpp.o: ../test/service_loader_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_service_loader.dir/service_loader_test.cpp.o"
	cd /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/test && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_service_loader.dir/service_loader_test.cpp.o -c /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/test/service_loader_test.cpp

test/CMakeFiles/test_service_loader.dir/service_loader_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_service_loader.dir/service_loader_test.cpp.i"
	cd /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/test/service_loader_test.cpp > CMakeFiles/test_service_loader.dir/service_loader_test.cpp.i

test/CMakeFiles/test_service_loader.dir/service_loader_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_service_loader.dir/service_loader_test.cpp.s"
	cd /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/test/service_loader_test.cpp -o CMakeFiles/test_service_loader.dir/service_loader_test.cpp.s

test/CMakeFiles/test_service_loader.dir/service_loader_test.cpp.o.requires:

.PHONY : test/CMakeFiles/test_service_loader.dir/service_loader_test.cpp.o.requires

test/CMakeFiles/test_service_loader.dir/service_loader_test.cpp.o.provides: test/CMakeFiles/test_service_loader.dir/service_loader_test.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/test_service_loader.dir/build.make test/CMakeFiles/test_service_loader.dir/service_loader_test.cpp.o.provides.build
.PHONY : test/CMakeFiles/test_service_loader.dir/service_loader_test.cpp.o.provides

test/CMakeFiles/test_service_loader.dir/service_loader_test.cpp.o.provides.build: test/CMakeFiles/test_service_loader.dir/service_loader_test.cpp.o


# Object files for target test_service_loader
test_service_loader_OBJECTS = \
"CMakeFiles/test_service_loader.dir/service_loader_test.cpp.o"

# External object files for target test_service_loader
test_service_loader_EXTERNAL_OBJECTS =

test/test_service_loader: test/CMakeFiles/test_service_loader.dir/service_loader_test.cpp.o
test/test_service_loader: test/CMakeFiles/test_service_loader.dir/build.make
test/test_service_loader: src/libclara.dylib
test/test_service_loader: ThirdParty/src/googlemock-build/googlemock/libgmock.a
test/test_service_loader: /usr/local/lib/libxmsg.dylib
test/test_service_loader: /usr/local/lib/libprotobuf.dylib
test/test_service_loader: /usr/local/lib/libzmq.dylib
test/test_service_loader: ThirdParty/src/googlemock-build/googlemock/gtest/libgtest.a
test/test_service_loader: test/CMakeFiles/test_service_loader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_service_loader"
	cd /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_service_loader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_service_loader.dir/build: test/test_service_loader

.PHONY : test/CMakeFiles/test_service_loader.dir/build

test/CMakeFiles/test_service_loader.dir/requires: test/CMakeFiles/test_service_loader.dir/service_loader_test.cpp.o.requires

.PHONY : test/CMakeFiles/test_service_loader.dir/requires

test/CMakeFiles/test_service_loader.dir/clean:
	cd /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/test_service_loader.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_service_loader.dir/clean

test/CMakeFiles/test_service_loader.dir/depend:
	cd /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/patrickhennis/Desktop/JLab/c++/clara-cpp /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/test /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/test /Users/patrickhennis/Desktop/JLab/c++/clara-cpp/cmake-build-debug/test/CMakeFiles/test_service_loader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_service_loader.dir/depend

