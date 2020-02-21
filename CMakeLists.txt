cmake_minimum_required(VERSION 3.15)
project(MagmaKernel C)

set(CMAKE_C_STANDARD 99)

add_executable(MagmaKernel core.c core.h)
add_executable(MagmaKernelTest core.c core.h test.c test.h)
