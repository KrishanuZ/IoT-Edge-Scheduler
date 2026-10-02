cmake_minimum_required(VERSION 3.10)
project(OS_Simulator C)

add_executable(run.exe src/test-ll.c src/list.c src/task.c)

target_include_directories(run.exe PRIVATE include)