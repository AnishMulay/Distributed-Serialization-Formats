cmake_minimum_required(VERSION 3.10)
project(serialization_benchmark VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -O3")

# Include directories for header files
include_directories(${PROJECT_SOURCE_DIR}/src)

# Find required packages
find_package(nlohmann_json REQUIRED)
find_package(PugiXML REQUIRED)
find_package(Protobuf REQUIRED)
find_package(MsgPack REQUIRED)

# Generate Protocol Buffers code
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/formats/protobuf/generated)

execute_process(
    COMMAND protoc 
        --proto_path=${CMAKE_CURRENT_SOURCE_DIR}/schemas/protobuf
        --cpp_out=${CMAKE_CURRENT_SOURCE_DIR}/src/formats/protobuf/generated 
        ${CMAKE_CURRENT_SOURCE_DIR}/schemas/protobuf/file_storage.proto
    RESULT_VARIABLE PROTOC_RESULT
)
if(NOT "${PROTOC_RESULT}" STREQUAL "0")
    message(FATAL_ERROR "Failed to generate Protocol Buffers code")
endif()

# Include generated protobuf headers
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/formats/protobuf/generated
)


# Common source files
set(COMMON_SOURCES
    src/common/test_data_generator.cpp
    src/common/benchmark_runner.cpp
    src/common/utilities.cpp
)

# Format-specific source files
set(JSON_SOURCES
    src/formats/json/json_serializer.cpp
)

set(XML_SOURCES
    src/formats/xml/xml_serializer.cpp
)

set(PROTOBUF_SOURCES
    src/formats/protobuf/protobuf_serializer.cpp
    src/formats/protobuf/generated/schemas/protobuf/file_storage.pb.cc
)

set(MSGPACK_SOURCES
    src/formats/msgpack/msgpack_serializer.cpp
)

# Main application executable
add_executable(benchmark_app src/main.cpp ${COMMON_SOURCES} ${JSON_SOURCES} ${XML_SOURCES} ${PROTOBUF_SOURCES} ${MSGPACK_SOURCES})

# Link libraries
target_link_libraries(benchmark_app
    PRIVATE
    nlohmann_json::nlohmann_json
    pugixml
    ${PROTOBUF_LIBRARIES}
    msgpackc
)

# Test data generator test
add_executable(test_data_generator_test
    src/tests/test_data_generator_test.cpp
    ${COMMON_SOURCES}
)

# Benchmark runner test
add_executable(benchmark_runner_test
    src/tests/benchmark_runner_test.cpp
    ${COMMON_SOURCES}
)

# JSON serializer test
add_executable(json_serializer_test
    src/tests/json_serializer_test.cpp
    ${JSON_SOURCES}
    ${COMMON_SOURCES}
)

target_link_libraries(json_serializer_test
    PRIVATE
    nlohmann_json::nlohmann_json
)

# XML serializer test
add_executable(xml_serializer_test
    src/tests/xml_serializer_test.cpp
    ${XML_SOURCES}
    ${COMMON_SOURCES}
)

target_link_libraries(xml_serializer_test
    PRIVATE
    pugixml
)

# Protocol Buffers serializer test
add_executable(protobuf_serializer_test
    src/tests/protobuf_serializer_test.cpp
    ${PROTOBUF_SOURCES}
    ${COMMON_SOURCES}
)

target_link_libraries(protobuf_serializer_test
    PRIVATE
    ${PROTOBUF_LIBRARIES}
)

# MessagePack serializer test
add_executable(msgpack_serializer_test
    src/tests/msgpack_serializer_test.cpp
    ${MSGPACK_SOURCES}
    ${COMMON_SOURCES}
)

target_link_libraries(msgpack_serializer_test
    PRIVATE
    msgpackc
)