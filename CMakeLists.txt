cmake_minimum_required(VERSION 3.5)
project(Dictionary)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c classes/core/Dictionary/Hash.c classes/core/Dictionary/Hash.h classes/core/Dictionary/Dictionary.c classes/core/Dictionary/Dictionary.h)
add_executable(Dictionary ${SOURCE_FILES})