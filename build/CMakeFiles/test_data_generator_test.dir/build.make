# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/anish/miniconda/lib/python3.12/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/anish/miniconda/lib/python3.12/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anish/Anish/Projects/Distributed-Serialization-Formats

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anish/Anish/Projects/Distributed-Serialization-Formats/build

# Include any dependencies generated for this target.
include CMakeFiles/test_data_generator_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_data_generator_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_data_generator_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_data_generator_test.dir/flags.make

CMakeFiles/test_data_generator_test.dir/codegen:
.PHONY : CMakeFiles/test_data_generator_test.dir/codegen

CMakeFiles/test_data_generator_test.dir/src/tests/test_data_generator_test.cpp.o: CMakeFiles/test_data_generator_test.dir/flags.make
CMakeFiles/test_data_generator_test.dir/src/tests/test_data_generator_test.cpp.o: /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/tests/test_data_generator_test.cpp
CMakeFiles/test_data_generator_test.dir/src/tests/test_data_generator_test.cpp.o: CMakeFiles/test_data_generator_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_data_generator_test.dir/src/tests/test_data_generator_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_data_generator_test.dir/src/tests/test_data_generator_test.cpp.o -MF CMakeFiles/test_data_generator_test.dir/src/tests/test_data_generator_test.cpp.o.d -o CMakeFiles/test_data_generator_test.dir/src/tests/test_data_generator_test.cpp.o -c /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/tests/test_data_generator_test.cpp

CMakeFiles/test_data_generator_test.dir/src/tests/test_data_generator_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_data_generator_test.dir/src/tests/test_data_generator_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/tests/test_data_generator_test.cpp > CMakeFiles/test_data_generator_test.dir/src/tests/test_data_generator_test.cpp.i

CMakeFiles/test_data_generator_test.dir/src/tests/test_data_generator_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_data_generator_test.dir/src/tests/test_data_generator_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/tests/test_data_generator_test.cpp -o CMakeFiles/test_data_generator_test.dir/src/tests/test_data_generator_test.cpp.s

CMakeFiles/test_data_generator_test.dir/src/common/test_data_generator.cpp.o: CMakeFiles/test_data_generator_test.dir/flags.make
CMakeFiles/test_data_generator_test.dir/src/common/test_data_generator.cpp.o: /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/test_data_generator.cpp
CMakeFiles/test_data_generator_test.dir/src/common/test_data_generator.cpp.o: CMakeFiles/test_data_generator_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_data_generator_test.dir/src/common/test_data_generator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_data_generator_test.dir/src/common/test_data_generator.cpp.o -MF CMakeFiles/test_data_generator_test.dir/src/common/test_data_generator.cpp.o.d -o CMakeFiles/test_data_generator_test.dir/src/common/test_data_generator.cpp.o -c /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/test_data_generator.cpp

CMakeFiles/test_data_generator_test.dir/src/common/test_data_generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_data_generator_test.dir/src/common/test_data_generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/test_data_generator.cpp > CMakeFiles/test_data_generator_test.dir/src/common/test_data_generator.cpp.i

CMakeFiles/test_data_generator_test.dir/src/common/test_data_generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_data_generator_test.dir/src/common/test_data_generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/test_data_generator.cpp -o CMakeFiles/test_data_generator_test.dir/src/common/test_data_generator.cpp.s

CMakeFiles/test_data_generator_test.dir/src/common/benchmark_runner.cpp.o: CMakeFiles/test_data_generator_test.dir/flags.make
CMakeFiles/test_data_generator_test.dir/src/common/benchmark_runner.cpp.o: /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/benchmark_runner.cpp
CMakeFiles/test_data_generator_test.dir/src/common/benchmark_runner.cpp.o: CMakeFiles/test_data_generator_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_data_generator_test.dir/src/common/benchmark_runner.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_data_generator_test.dir/src/common/benchmark_runner.cpp.o -MF CMakeFiles/test_data_generator_test.dir/src/common/benchmark_runner.cpp.o.d -o CMakeFiles/test_data_generator_test.dir/src/common/benchmark_runner.cpp.o -c /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/benchmark_runner.cpp

CMakeFiles/test_data_generator_test.dir/src/common/benchmark_runner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_data_generator_test.dir/src/common/benchmark_runner.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/benchmark_runner.cpp > CMakeFiles/test_data_generator_test.dir/src/common/benchmark_runner.cpp.i

CMakeFiles/test_data_generator_test.dir/src/common/benchmark_runner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_data_generator_test.dir/src/common/benchmark_runner.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/benchmark_runner.cpp -o CMakeFiles/test_data_generator_test.dir/src/common/benchmark_runner.cpp.s

CMakeFiles/test_data_generator_test.dir/src/common/utilities.cpp.o: CMakeFiles/test_data_generator_test.dir/flags.make
CMakeFiles/test_data_generator_test.dir/src/common/utilities.cpp.o: /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/utilities.cpp
CMakeFiles/test_data_generator_test.dir/src/common/utilities.cpp.o: CMakeFiles/test_data_generator_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test_data_generator_test.dir/src/common/utilities.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_data_generator_test.dir/src/common/utilities.cpp.o -MF CMakeFiles/test_data_generator_test.dir/src/common/utilities.cpp.o.d -o CMakeFiles/test_data_generator_test.dir/src/common/utilities.cpp.o -c /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/utilities.cpp

CMakeFiles/test_data_generator_test.dir/src/common/utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_data_generator_test.dir/src/common/utilities.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/utilities.cpp > CMakeFiles/test_data_generator_test.dir/src/common/utilities.cpp.i

CMakeFiles/test_data_generator_test.dir/src/common/utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_data_generator_test.dir/src/common/utilities.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/utilities.cpp -o CMakeFiles/test_data_generator_test.dir/src/common/utilities.cpp.s

# Object files for target test_data_generator_test
test_data_generator_test_OBJECTS = \
"CMakeFiles/test_data_generator_test.dir/src/tests/test_data_generator_test.cpp.o" \
"CMakeFiles/test_data_generator_test.dir/src/common/test_data_generator.cpp.o" \
"CMakeFiles/test_data_generator_test.dir/src/common/benchmark_runner.cpp.o" \
"CMakeFiles/test_data_generator_test.dir/src/common/utilities.cpp.o"

# External object files for target test_data_generator_test
test_data_generator_test_EXTERNAL_OBJECTS =

test_data_generator_test: CMakeFiles/test_data_generator_test.dir/src/tests/test_data_generator_test.cpp.o
test_data_generator_test: CMakeFiles/test_data_generator_test.dir/src/common/test_data_generator.cpp.o
test_data_generator_test: CMakeFiles/test_data_generator_test.dir/src/common/benchmark_runner.cpp.o
test_data_generator_test: CMakeFiles/test_data_generator_test.dir/src/common/utilities.cpp.o
test_data_generator_test: CMakeFiles/test_data_generator_test.dir/build.make
test_data_generator_test: CMakeFiles/test_data_generator_test.dir/compiler_depend.ts
test_data_generator_test: CMakeFiles/test_data_generator_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable test_data_generator_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_data_generator_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_data_generator_test.dir/build: test_data_generator_test
.PHONY : CMakeFiles/test_data_generator_test.dir/build

CMakeFiles/test_data_generator_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_data_generator_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_data_generator_test.dir/clean

CMakeFiles/test_data_generator_test.dir/depend:
	cd /home/anish/Anish/Projects/Distributed-Serialization-Formats/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anish/Anish/Projects/Distributed-Serialization-Formats /home/anish/Anish/Projects/Distributed-Serialization-Formats /home/anish/Anish/Projects/Distributed-Serialization-Formats/build /home/anish/Anish/Projects/Distributed-Serialization-Formats/build /home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles/test_data_generator_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test_data_generator_test.dir/depend

