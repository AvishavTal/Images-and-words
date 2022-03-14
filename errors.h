//
// Created by Sapir on 14.3.2022.
//

#ifndef EX14_ERRORS_H
#define EX14_ERRORS_H
#include<stdio.h>
typedef enum {NOT_ERROR,UNDEFINED_OPERATOR,DOUBLE_DEFINITION_OF_LABEL,ILLEGAL_SYMBOL_NAME,
              TOO_MANY_ARGS,TOO_FEW_ARGS,ILLEGAL_ADDRESSING,INVALID_REGISTER_NAME,NOT_INT,NOT_IN_RANGE_IMMEDIATE,UNDEFINED_SYMBOL,
              TOO_MANY_CHARS,ILLEGAL_DATA,ILLEGAL_STRING,SYNTAX_ERROR,INVALID_REGISTER_FOR_INDEX,ILLEGAL_OPERAND}error;
/**
 * This function print the number of the line in which there is an error and the error by error code
 * @param line_number - The number of the line in which there is an error
 * @param to_print - the error code
 */
void print_error(int line_number,error to_print);

#endif //EX14_ERRORS_H