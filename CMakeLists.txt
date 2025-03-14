cmake_minimum_required(VERSION 3.10)
project(sniff C)

set(CMAKE_C_STANDARD 11)

# Include directories
include_directories(src/include)

# Collect all source files from sniffiles
file(GLOB SOURCES src/sniffiles/*.c)

# Add executable
add_executable(sniff ${SOURCES})

# Link pthread if needed
target_link_libraries(sniff pthread)

install(TARGETS sniff DESTINATION /usr/local/bin)
