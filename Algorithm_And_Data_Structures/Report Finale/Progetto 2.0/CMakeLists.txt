cmake_minimum_required(VERSION 3.17)
project(Progetto_2_0 C)

set(CMAKE_C_STANDARD 90)

MATH(EXPR stack_size "16 * 1024 * 1024") # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(Progetto_2_0 main.c vectorFunctions.c vectorFunctions.h supportFunctions.c supportFunctions.h sortingAlgorithms.c sortingAlgorithms.h)