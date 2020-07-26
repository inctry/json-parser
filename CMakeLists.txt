cmake_minimum_required(VERSION 3.15)
project(json_parser)

set(CMAKE_CXX_STANDARD 14)

add_executable(json_parser leptjson.h leptjson.c test.c)