cmake_minimum_required(VERSION 3.10)
project(OS_Simulator C)
add_executable(run.exe src/test.c src/node.c src/list.c)
target_include_directories(run.exe PRIVATE include)