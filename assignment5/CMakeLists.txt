cmake_minimum_required(VERSION 3.14)
project(assignment5)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(assignment5
        include/collection.h
        include/keyvalue.h
        include/map.h
        include/node.h
        src/arraymap.cpp
        src/linkedmap.cpp
        src/main.cpp)
