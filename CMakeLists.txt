cmake_minimum_required(VERSION 3.10)
project(OS_Simulator C)
add_executable(run.exe src/test-scheduler.c src/node.c src/list.c src/scheduler.c)
target_include_directories(run.exe PRIVATE include)