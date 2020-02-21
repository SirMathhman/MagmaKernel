cmake_minimum_required(VERSION 3.15)
project(MagmaKernel C)

set(CMAKE_C_STANDARD 99)

add_executable(MagmaKernel assertions.c assertions.h core.h main.c primitives.c primitives.h)