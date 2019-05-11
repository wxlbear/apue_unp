cmake_minimum_required(VERSION 3.13)
project(apue_unp C)

set(CMAKE_C_STANDARD 99)

add_executable(apue_unp main.c apue/main.c)