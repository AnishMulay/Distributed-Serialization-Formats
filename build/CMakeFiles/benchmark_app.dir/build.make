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
include CMakeFiles/benchmark_app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/benchmark_app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/benchmark_app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/benchmark_app.dir/flags.make

CMakeFiles/benchmark_app.dir/codegen:
.PHONY : CMakeFiles/benchmark_app.dir/codegen

CMakeFiles/benchmark_app.dir/src/main.cpp.o: CMakeFiles/benchmark_app.dir/flags.make
CMakeFiles/benchmark_app.dir/src/main.cpp.o: /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/main.cpp
CMakeFiles/benchmark_app.dir/src/main.cpp.o: CMakeFiles/benchmark_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/benchmark_app.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/benchmark_app.dir/src/main.cpp.o -MF CMakeFiles/benchmark_app.dir/src/main.cpp.o.d -o CMakeFiles/benchmark_app.dir/src/main.cpp.o -c /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/main.cpp

CMakeFiles/benchmark_app.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmark_app.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/main.cpp > CMakeFiles/benchmark_app.dir/src/main.cpp.i

CMakeFiles/benchmark_app.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmark_app.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/main.cpp -o CMakeFiles/benchmark_app.dir/src/main.cpp.s

CMakeFiles/benchmark_app.dir/src/common/test_data_generator.cpp.o: CMakeFiles/benchmark_app.dir/flags.make
CMakeFiles/benchmark_app.dir/src/common/test_data_generator.cpp.o: /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/test_data_generator.cpp
CMakeFiles/benchmark_app.dir/src/common/test_data_generator.cpp.o: CMakeFiles/benchmark_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/benchmark_app.dir/src/common/test_data_generator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/benchmark_app.dir/src/common/test_data_generator.cpp.o -MF CMakeFiles/benchmark_app.dir/src/common/test_data_generator.cpp.o.d -o CMakeFiles/benchmark_app.dir/src/common/test_data_generator.cpp.o -c /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/test_data_generator.cpp

CMakeFiles/benchmark_app.dir/src/common/test_data_generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmark_app.dir/src/common/test_data_generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/test_data_generator.cpp > CMakeFiles/benchmark_app.dir/src/common/test_data_generator.cpp.i

CMakeFiles/benchmark_app.dir/src/common/test_data_generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmark_app.dir/src/common/test_data_generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/test_data_generator.cpp -o CMakeFiles/benchmark_app.dir/src/common/test_data_generator.cpp.s

CMakeFiles/benchmark_app.dir/src/common/benchmark_runner.cpp.o: CMakeFiles/benchmark_app.dir/flags.make
CMakeFiles/benchmark_app.dir/src/common/benchmark_runner.cpp.o: /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/benchmark_runner.cpp
CMakeFiles/benchmark_app.dir/src/common/benchmark_runner.cpp.o: CMakeFiles/benchmark_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/benchmark_app.dir/src/common/benchmark_runner.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/benchmark_app.dir/src/common/benchmark_runner.cpp.o -MF CMakeFiles/benchmark_app.dir/src/common/benchmark_runner.cpp.o.d -o CMakeFiles/benchmark_app.dir/src/common/benchmark_runner.cpp.o -c /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/benchmark_runner.cpp

CMakeFiles/benchmark_app.dir/src/common/benchmark_runner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmark_app.dir/src/common/benchmark_runner.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/benchmark_runner.cpp > CMakeFiles/benchmark_app.dir/src/common/benchmark_runner.cpp.i

CMakeFiles/benchmark_app.dir/src/common/benchmark_runner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmark_app.dir/src/common/benchmark_runner.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/benchmark_runner.cpp -o CMakeFiles/benchmark_app.dir/src/common/benchmark_runner.cpp.s

CMakeFiles/benchmark_app.dir/src/common/utilities.cpp.o: CMakeFiles/benchmark_app.dir/flags.make
CMakeFiles/benchmark_app.dir/src/common/utilities.cpp.o: /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/utilities.cpp
CMakeFiles/benchmark_app.dir/src/common/utilities.cpp.o: CMakeFiles/benchmark_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/benchmark_app.dir/src/common/utilities.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/benchmark_app.dir/src/common/utilities.cpp.o -MF CMakeFiles/benchmark_app.dir/src/common/utilities.cpp.o.d -o CMakeFiles/benchmark_app.dir/src/common/utilities.cpp.o -c /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/utilities.cpp

CMakeFiles/benchmark_app.dir/src/common/utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmark_app.dir/src/common/utilities.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/utilities.cpp > CMakeFiles/benchmark_app.dir/src/common/utilities.cpp.i

CMakeFiles/benchmark_app.dir/src/common/utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmark_app.dir/src/common/utilities.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/common/utilities.cpp -o CMakeFiles/benchmark_app.dir/src/common/utilities.cpp.s

CMakeFiles/benchmark_app.dir/src/formats/json/json_serializer.cpp.o: CMakeFiles/benchmark_app.dir/flags.make
CMakeFiles/benchmark_app.dir/src/formats/json/json_serializer.cpp.o: /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/json/json_serializer.cpp
CMakeFiles/benchmark_app.dir/src/formats/json/json_serializer.cpp.o: CMakeFiles/benchmark_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/benchmark_app.dir/src/formats/json/json_serializer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/benchmark_app.dir/src/formats/json/json_serializer.cpp.o -MF CMakeFiles/benchmark_app.dir/src/formats/json/json_serializer.cpp.o.d -o CMakeFiles/benchmark_app.dir/src/formats/json/json_serializer.cpp.o -c /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/json/json_serializer.cpp

CMakeFiles/benchmark_app.dir/src/formats/json/json_serializer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmark_app.dir/src/formats/json/json_serializer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/json/json_serializer.cpp > CMakeFiles/benchmark_app.dir/src/formats/json/json_serializer.cpp.i

CMakeFiles/benchmark_app.dir/src/formats/json/json_serializer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmark_app.dir/src/formats/json/json_serializer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/json/json_serializer.cpp -o CMakeFiles/benchmark_app.dir/src/formats/json/json_serializer.cpp.s

CMakeFiles/benchmark_app.dir/src/formats/xml/xml_serializer.cpp.o: CMakeFiles/benchmark_app.dir/flags.make
CMakeFiles/benchmark_app.dir/src/formats/xml/xml_serializer.cpp.o: /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/xml/xml_serializer.cpp
CMakeFiles/benchmark_app.dir/src/formats/xml/xml_serializer.cpp.o: CMakeFiles/benchmark_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/benchmark_app.dir/src/formats/xml/xml_serializer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/benchmark_app.dir/src/formats/xml/xml_serializer.cpp.o -MF CMakeFiles/benchmark_app.dir/src/formats/xml/xml_serializer.cpp.o.d -o CMakeFiles/benchmark_app.dir/src/formats/xml/xml_serializer.cpp.o -c /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/xml/xml_serializer.cpp

CMakeFiles/benchmark_app.dir/src/formats/xml/xml_serializer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmark_app.dir/src/formats/xml/xml_serializer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/xml/xml_serializer.cpp > CMakeFiles/benchmark_app.dir/src/formats/xml/xml_serializer.cpp.i

CMakeFiles/benchmark_app.dir/src/formats/xml/xml_serializer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmark_app.dir/src/formats/xml/xml_serializer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/xml/xml_serializer.cpp -o CMakeFiles/benchmark_app.dir/src/formats/xml/xml_serializer.cpp.s

CMakeFiles/benchmark_app.dir/src/formats/protobuf/protobuf_serializer.cpp.o: CMakeFiles/benchmark_app.dir/flags.make
CMakeFiles/benchmark_app.dir/src/formats/protobuf/protobuf_serializer.cpp.o: /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/protobuf/protobuf_serializer.cpp
CMakeFiles/benchmark_app.dir/src/formats/protobuf/protobuf_serializer.cpp.o: CMakeFiles/benchmark_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/benchmark_app.dir/src/formats/protobuf/protobuf_serializer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/benchmark_app.dir/src/formats/protobuf/protobuf_serializer.cpp.o -MF CMakeFiles/benchmark_app.dir/src/formats/protobuf/protobuf_serializer.cpp.o.d -o CMakeFiles/benchmark_app.dir/src/formats/protobuf/protobuf_serializer.cpp.o -c /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/protobuf/protobuf_serializer.cpp

CMakeFiles/benchmark_app.dir/src/formats/protobuf/protobuf_serializer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmark_app.dir/src/formats/protobuf/protobuf_serializer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/protobuf/protobuf_serializer.cpp > CMakeFiles/benchmark_app.dir/src/formats/protobuf/protobuf_serializer.cpp.i

CMakeFiles/benchmark_app.dir/src/formats/protobuf/protobuf_serializer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmark_app.dir/src/formats/protobuf/protobuf_serializer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/protobuf/protobuf_serializer.cpp -o CMakeFiles/benchmark_app.dir/src/formats/protobuf/protobuf_serializer.cpp.s

CMakeFiles/benchmark_app.dir/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc.o: CMakeFiles/benchmark_app.dir/flags.make
CMakeFiles/benchmark_app.dir/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc.o: /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc
CMakeFiles/benchmark_app.dir/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc.o: CMakeFiles/benchmark_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/benchmark_app.dir/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/benchmark_app.dir/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc.o -MF CMakeFiles/benchmark_app.dir/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc.o.d -o CMakeFiles/benchmark_app.dir/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc.o -c /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc

CMakeFiles/benchmark_app.dir/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmark_app.dir/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc > CMakeFiles/benchmark_app.dir/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc.i

CMakeFiles/benchmark_app.dir/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmark_app.dir/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc -o CMakeFiles/benchmark_app.dir/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc.s

CMakeFiles/benchmark_app.dir/src/formats/msgpack/msgpack_serializer.cpp.o: CMakeFiles/benchmark_app.dir/flags.make
CMakeFiles/benchmark_app.dir/src/formats/msgpack/msgpack_serializer.cpp.o: /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/msgpack/msgpack_serializer.cpp
CMakeFiles/benchmark_app.dir/src/formats/msgpack/msgpack_serializer.cpp.o: CMakeFiles/benchmark_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/benchmark_app.dir/src/formats/msgpack/msgpack_serializer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/benchmark_app.dir/src/formats/msgpack/msgpack_serializer.cpp.o -MF CMakeFiles/benchmark_app.dir/src/formats/msgpack/msgpack_serializer.cpp.o.d -o CMakeFiles/benchmark_app.dir/src/formats/msgpack/msgpack_serializer.cpp.o -c /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/msgpack/msgpack_serializer.cpp

CMakeFiles/benchmark_app.dir/src/formats/msgpack/msgpack_serializer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmark_app.dir/src/formats/msgpack/msgpack_serializer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/msgpack/msgpack_serializer.cpp > CMakeFiles/benchmark_app.dir/src/formats/msgpack/msgpack_serializer.cpp.i

CMakeFiles/benchmark_app.dir/src/formats/msgpack/msgpack_serializer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmark_app.dir/src/formats/msgpack/msgpack_serializer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anish/Anish/Projects/Distributed-Serialization-Formats/src/formats/msgpack/msgpack_serializer.cpp -o CMakeFiles/benchmark_app.dir/src/formats/msgpack/msgpack_serializer.cpp.s

# Object files for target benchmark_app
benchmark_app_OBJECTS = \
"CMakeFiles/benchmark_app.dir/src/main.cpp.o" \
"CMakeFiles/benchmark_app.dir/src/common/test_data_generator.cpp.o" \
"CMakeFiles/benchmark_app.dir/src/common/benchmark_runner.cpp.o" \
"CMakeFiles/benchmark_app.dir/src/common/utilities.cpp.o" \
"CMakeFiles/benchmark_app.dir/src/formats/json/json_serializer.cpp.o" \
"CMakeFiles/benchmark_app.dir/src/formats/xml/xml_serializer.cpp.o" \
"CMakeFiles/benchmark_app.dir/src/formats/protobuf/protobuf_serializer.cpp.o" \
"CMakeFiles/benchmark_app.dir/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc.o" \
"CMakeFiles/benchmark_app.dir/src/formats/msgpack/msgpack_serializer.cpp.o"

# External object files for target benchmark_app
benchmark_app_EXTERNAL_OBJECTS =

benchmark_app: CMakeFiles/benchmark_app.dir/src/main.cpp.o
benchmark_app: CMakeFiles/benchmark_app.dir/src/common/test_data_generator.cpp.o
benchmark_app: CMakeFiles/benchmark_app.dir/src/common/benchmark_runner.cpp.o
benchmark_app: CMakeFiles/benchmark_app.dir/src/common/utilities.cpp.o
benchmark_app: CMakeFiles/benchmark_app.dir/src/formats/json/json_serializer.cpp.o
benchmark_app: CMakeFiles/benchmark_app.dir/src/formats/xml/xml_serializer.cpp.o
benchmark_app: CMakeFiles/benchmark_app.dir/src/formats/protobuf/protobuf_serializer.cpp.o
benchmark_app: CMakeFiles/benchmark_app.dir/src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc.o
benchmark_app: CMakeFiles/benchmark_app.dir/src/formats/msgpack/msgpack_serializer.cpp.o
benchmark_app: CMakeFiles/benchmark_app.dir/build.make
benchmark_app: CMakeFiles/benchmark_app.dir/compiler_depend.ts
benchmark_app: /usr/lib/x86_64-linux-gnu/libprotobuf.so
benchmark_app: /usr/lib/x86_64-linux-gnu/libmsgpackc.so.2.0.0
benchmark_app: /usr/lib/x86_64-linux-gnu/libpugixml.so.1.14
benchmark_app: CMakeFiles/benchmark_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable benchmark_app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/benchmark_app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/benchmark_app.dir/build: benchmark_app
.PHONY : CMakeFiles/benchmark_app.dir/build

CMakeFiles/benchmark_app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/benchmark_app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/benchmark_app.dir/clean

CMakeFiles/benchmark_app.dir/depend:
	cd /home/anish/Anish/Projects/Distributed-Serialization-Formats/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anish/Anish/Projects/Distributed-Serialization-Formats /home/anish/Anish/Projects/Distributed-Serialization-Formats /home/anish/Anish/Projects/Distributed-Serialization-Formats/build /home/anish/Anish/Projects/Distributed-Serialization-Formats/build /home/anish/Anish/Projects/Distributed-Serialization-Formats/build/CMakeFiles/benchmark_app.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/benchmark_app.dir/depend

