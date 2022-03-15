/*
* Created by Avishav & Sapir on March 14,2022
*/

#include<stdio.h>
#include "errors.h"

void print_error(unsigned long line_number,error err_code){
    switch (err_code) {
        case UNDEFINED_OPERATOR:
            printf("%d\t This operator not exist.\n", line_number);
            break;
        case DOUBLE_DEFINITION_OF_LABEL:
            printf("%d\t This label is already exist.\n", line_number);
            break;
        case ILLEGAL_SYMBOL_NAME:
            printf("%d\t Illegal symbol name.\n", line_number);
            break;
        case TOO_MANY_ARGS:
            printf("%d\t Too many operands.\n", line_number);
            break;
        case TOO_FEW_ARGS:
            printf("%d\t Too few operands.\n", line_number);
            break;
        case ILLEGAL_ADDRESSING:
            printf("%d\t Illegal addressing.\n", line_number);
            break;
        case INVALID_REGISTER_NAME:
            printf("%d\t Invalid register name.\n", line_number);
            break;
        case NOT_INT:
            printf("%d\t The number must be integer.\n", line_number);
            break;
        case NOT_IN_RANGE_IMMEDIATE:
            printf("%d\t Not in range for immediate addressing.\n", line_number);
            break;
        case UNDEFINED_SYMBOL:
            printf("%d\t Undefined symbol.\n", line_number);
            break;
        case TOO_MANY_CHARS:
            printf("%d\t Too many chars in line.\n", line_number);
            break;
        case ILLEGAL_DATA:
            printf("%d\t Illegal data.\n", line_number);
            break;
        case ILLEGAL_STRING:
            printf("%d\t Illegal string.\n", line_number);
            break;
        case SYNTAX_ERROR:
            printf("%d\t Illegal data.\n", line_number);
            break;
        case INVALID_REGISTER_FOR_INDEX:
            printf("%d\t Invalid register for index.\n", line_number);
            break;
        case ILLEGAL_OPERAND:
            printf("%d\t Illegal operand.\n", line_number);
            break;
        default:
            printf("%d\t Im in the default case - we have a problem.\n", line_number);
            break;
    }
}