# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thomas/humax/rg/dp_eroos2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thomas/humax/rg/dp_eroos2/build

# Include any dependencies generated for this target.
include Structural_Patterns/Proxy/CMakeFiles/proxy.dir/depend.make

# Include the progress variables for this target.
include Structural_Patterns/Proxy/CMakeFiles/proxy.dir/progress.make

# Include the compile flags for this target's objects.
include Structural_Patterns/Proxy/CMakeFiles/proxy.dir/flags.make

Structural_Patterns/Proxy/CMakeFiles/proxy.dir/main.cpp.o: Structural_Patterns/Proxy/CMakeFiles/proxy.dir/flags.make
Structural_Patterns/Proxy/CMakeFiles/proxy.dir/main.cpp.o: ../Structural_Patterns/Proxy/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/thomas/humax/rg/dp_eroos2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Structural_Patterns/Proxy/CMakeFiles/proxy.dir/main.cpp.o"
	cd /home/thomas/humax/rg/dp_eroos2/build/Structural_Patterns/Proxy && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/proxy.dir/main.cpp.o -c /home/thomas/humax/rg/dp_eroos2/Structural_Patterns/Proxy/main.cpp

Structural_Patterns/Proxy/CMakeFiles/proxy.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proxy.dir/main.cpp.i"
	cd /home/thomas/humax/rg/dp_eroos2/build/Structural_Patterns/Proxy && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/thomas/humax/rg/dp_eroos2/Structural_Patterns/Proxy/main.cpp > CMakeFiles/proxy.dir/main.cpp.i

Structural_Patterns/Proxy/CMakeFiles/proxy.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proxy.dir/main.cpp.s"
	cd /home/thomas/humax/rg/dp_eroos2/build/Structural_Patterns/Proxy && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/thomas/humax/rg/dp_eroos2/Structural_Patterns/Proxy/main.cpp -o CMakeFiles/proxy.dir/main.cpp.s

Structural_Patterns/Proxy/CMakeFiles/proxy.dir/main.cpp.o.requires:
.PHONY : Structural_Patterns/Proxy/CMakeFiles/proxy.dir/main.cpp.o.requires

Structural_Patterns/Proxy/CMakeFiles/proxy.dir/main.cpp.o.provides: Structural_Patterns/Proxy/CMakeFiles/proxy.dir/main.cpp.o.requires
	$(MAKE) -f Structural_Patterns/Proxy/CMakeFiles/proxy.dir/build.make Structural_Patterns/Proxy/CMakeFiles/proxy.dir/main.cpp.o.provides.build
.PHONY : Structural_Patterns/Proxy/CMakeFiles/proxy.dir/main.cpp.o.provides

Structural_Patterns/Proxy/CMakeFiles/proxy.dir/main.cpp.o.provides.build: Structural_Patterns/Proxy/CMakeFiles/proxy.dir/main.cpp.o

# Object files for target proxy
proxy_OBJECTS = \
"CMakeFiles/proxy.dir/main.cpp.o"

# External object files for target proxy
proxy_EXTERNAL_OBJECTS =

Structural_Patterns/Proxy/proxy: Structural_Patterns/Proxy/CMakeFiles/proxy.dir/main.cpp.o
Structural_Patterns/Proxy/proxy: Structural_Patterns/Proxy/libproxylib.so
Structural_Patterns/Proxy/proxy: Foundation_Classes/libfoundation_classes.so
Structural_Patterns/Proxy/proxy: Structural_Patterns/Proxy/CMakeFiles/proxy.dir/build.make
Structural_Patterns/Proxy/proxy: Structural_Patterns/Proxy/CMakeFiles/proxy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable proxy"
	cd /home/thomas/humax/rg/dp_eroos2/build/Structural_Patterns/Proxy && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proxy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Structural_Patterns/Proxy/CMakeFiles/proxy.dir/build: Structural_Patterns/Proxy/proxy
.PHONY : Structural_Patterns/Proxy/CMakeFiles/proxy.dir/build

Structural_Patterns/Proxy/CMakeFiles/proxy.dir/requires: Structural_Patterns/Proxy/CMakeFiles/proxy.dir/main.cpp.o.requires
.PHONY : Structural_Patterns/Proxy/CMakeFiles/proxy.dir/requires

Structural_Patterns/Proxy/CMakeFiles/proxy.dir/clean:
	cd /home/thomas/humax/rg/dp_eroos2/build/Structural_Patterns/Proxy && $(CMAKE_COMMAND) -P CMakeFiles/proxy.dir/cmake_clean.cmake
.PHONY : Structural_Patterns/Proxy/CMakeFiles/proxy.dir/clean

Structural_Patterns/Proxy/CMakeFiles/proxy.dir/depend:
	cd /home/thomas/humax/rg/dp_eroos2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thomas/humax/rg/dp_eroos2 /home/thomas/humax/rg/dp_eroos2/Structural_Patterns/Proxy /home/thomas/humax/rg/dp_eroos2/build /home/thomas/humax/rg/dp_eroos2/build/Structural_Patterns/Proxy /home/thomas/humax/rg/dp_eroos2/build/Structural_Patterns/Proxy/CMakeFiles/proxy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Structural_Patterns/Proxy/CMakeFiles/proxy.dir/depend

