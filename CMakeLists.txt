cmake_minimum_required(VERSION 3.20)
project(ex14 C)

set(CMAKE_C_STANDARD 90)

add_executable(ex14 main.c first_scan.c first_scan.h pre_assembler.c pre_assembler.h second_scan.c second_scan.h symbol.c symbol.h instruction.c instruction.h data.c data.h macro.c macro.h attribute.c attribute.h linked_list.c linked_list.h operator_table.c operator_table.h pre_assembler.c string_manipulations.c string_manipulations.h macro_table.c macro_table.h file.c file.h symbol_table.c symbol_table.h word.c word.h word_test.c ARE.c ARE.h addressing_mode.h parser.c parser.h macro_body.c macro_body.h data_image.c data_image.h errors.c errors.h)
