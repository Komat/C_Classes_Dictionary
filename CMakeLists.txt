cmake_minimum_required(VERSION 3.5)
project(Dictionary)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c classes/Dictionary/Hash.c classes/Dictionary/Hash.h classes/Dictionary/Dictionary.c classes/Dictionary/Dictionary.h)
add_executable(Dictionary ${SOURCE_FILES})