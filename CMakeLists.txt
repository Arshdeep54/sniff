cmake_minimum_required(VERSION 3.0)
project(sniff)

set(CMAKE_C_STANDARD 99)

add_executable(sniff sniff.c)

set_target_properties(sniff PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build"
)
