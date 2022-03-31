/*
* Created by Avishav & Sapir on March 14, 2022
*/

#ifndef EX14_ERRORS_H
#define EX14_ERRORS_H

#include<stdio.h>

typedef enum {NOT_ERROR,UNDEFINED_OPERATOR,ILLEGAL_SYMBOL_NAME,
              TOO_MANY_ARGS,TOO_FEW_ARGS,ILLEGAL_ADDRESSING,INVALID_REGISTER_NAME,NOT_INT,UNDEFINED_SYMBOL,DATA_NOT_EXIST,
              TOO_MANY_CHARS,ILLEGAL_DATA,ILLEGAL_STRING,SYNTAX_ERROR,INVALID_REGISTER_FOR_INDEX,ILLEGAL_OPERAND,STRING_NOT_EXIST,
              ILLEGAL_STRING_SYNTAX,DOUBLE_DEFINITION_OF_SYMBOL,ILLEGAL_COMMA,MISSING_COMMA,TOO_LONG_LINE,MEMORY_OVERFLOW,BOTH_ENTRY_AND_EXTERN_FOR_SAME_SYMBOL}error;

 /**
  * This function gets line's number and error code and print which error happened in which line
  * @param line_number the line's number where the error occurred
  * @param err_code the code of the error that occurred
  */
 void print_error(unsigned long line_number,error err_code);

#endif