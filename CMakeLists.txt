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

# Create executable
add_executable(benchmark_app ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# Link libraries
target_link_libraries(benchmark_app
    PRIVATE
    nlohmann_json::nlohmann_json
    pugixml
    ${PROTOBUF_LIBRARIES}
    msgpackc
)