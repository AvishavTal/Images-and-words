cmake_minimum_required(VERSION 3.20)
project(ex14 C)

set(CMAKE_C_STANDARD 90)

add_executable(ex14 main.c first_scan.c first_scan.h pre_assembler.c pre_assembler.h seconde_scan.c seconde_scan.h symbool.c symbool.h instruction.c instruction.h data.c data.h macro.c macro.h)
