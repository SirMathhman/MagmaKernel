cmake_minimum_required(VERSION 3.15)
project(MagmaKernel C)

set(CMAKE_C_STANDARD 99)

add_library(MagmaKernel core.c core.h Collection.c Collection.h Throwable.c Throwable.h)
add_executable(MagmaKernelCompiler main.c)
add_executable(MagmaKernelTest test.c test.h)

target_link_libraries(MagmaKernelCompiler MagmaKernel)
target_link_libraries(MagmaKernelTest MagmaKernel)
