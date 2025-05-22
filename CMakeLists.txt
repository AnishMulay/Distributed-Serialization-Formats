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

# Common source files
set(COMMON_SOURCES
    src/common/test_data_generator.cpp
    src/common/benchmark_runner.cpp
)

# Main application executable
add_executable(benchmark_app src/main.cpp ${COMMON_SOURCES})

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