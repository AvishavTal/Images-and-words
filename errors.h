/*
* Created by Avishav & Sapir on March 14,2022
*/

#ifndef EX14_ERRORS_H
#define EX14_ERRORS_H
#include<stdio.h>
typedef enum {NOT_ERROR,UNDEFINED_OPERATOR,DOUBLE_DEFINITION_OF_LABEL,ILLEGAL_SYMBOL_NAME,
              TOO_MANY_ARGS,TOO_FEW_ARGS,ILLEGAL_ADDRESSING,INVALID_REGISTER_NAME,NOT_INT,NOT_IN_RANGE_IMMEDIATE,UNDEFINED_SYMBOL,
              TOO_MANY_CHARS,ILLEGAL_DATA,ILLEGAL_STRING,SYNTAX_ERROR,INVALID_REGISTER_FOR_INDEX,ILLEGAL_OPERAND}error;
 /**
  * This function gets line's number and error code and print which error happened in which line
  * @param line_number the line's number where the error occurred
  * @param err_code the code of the error that occurred
  */
 void print_error(unsigned long line_number,error err_code);

#endif //EX14_ERRORS_H