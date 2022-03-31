/*
* Created by Avishav & Sapir on March 14, 2022
*/

#ifndef EX14_ERRORS_H
#define EX14_ERRORS_H

#include<stdio.h>

/**
 * the possible values of errors
 */
typedef enum {NOT_ERROR,ILLEGAL_COMMA,MISSING_COMMA,ILLEGAL_STRING_SYNTAX,TOO_LONG_LINE,MEMORY_OVERFLOW,
    ILLEGAL_SYMBOL_NAME,UNDEFINED_SYMBOL,DOUBLE_DEFINITION_OF_SYMBOL,BOTH_ENTRY_AND_EXTERN_FOR_SAME_SYMBOL,
    DATA_NOT_EXIST,NOT_INT,STRING_NOT_EXIST,ILLEGAL_STRING,
    UNDEFINED_OPERATOR,ILLEGAL_OPERAND,INVALID_REGISTER_FOR_INDEX,ILLEGAL_ADDRESSING,
    TOO_MANY_ARGS,TOO_FEW_ARGS,INVALID_REGISTER_NAME}error;

 /**
  * This function gets line's number and error code and print which error happened in which line
  * @param line_number the line's number where the error occurred
  * @param err_code the code of the error that occurred
  */
 void print_error(unsigned long line_number,error err_code);

#endif