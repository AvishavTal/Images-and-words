/*
* Created by Avishav & Sapir on March 14, 2022
*/

#include<stdio.h>
#include "errors.h"

void print_error(unsigned long line_number,error err_code){
    switch (err_code) {
        case UNDEFINED_OPERATOR:
            printf("%lu\t Undefined token.\n", line_number);
            break;
        case DOUBLE_DEFINITION_OF_SYMBOL:
            printf("%lu\t This label is already exist.\n", line_number);
            break;
        case ILLEGAL_SYMBOL_NAME:
            printf("%lu\t Illegal symbol name.\n", line_number);
            break;
        case TOO_MANY_ARGS:
            printf("%lu\t Too many operands.\n", line_number);
            break;
        case TOO_FEW_ARGS:
            printf("%lu\t Too few operands.\n", line_number);
            break;
        case ILLEGAL_ADDRESSING:
            printf("%lu\t Illegal addressing.\n", line_number);
            break;
        case INVALID_REGISTER_NAME:
            printf("%lu\t Invalid register name.\n", line_number);
            break;
        case NOT_INT:
            printf("%lu\t Not int.\n", line_number);
            break;
        case UNDEFINED_SYMBOL:
            printf("%lu\t Undefined symbol.\n", line_number);
            break;
        case ILLEGAL_DATA:
            printf("%lu\t Illegal data.\n", line_number);
            break;
        case ILLEGAL_STRING:
            printf("%lu\t Illegal string.\n", line_number);
            break;
        case ILLEGAL_STRING_SYNTAX:
            printf("%lu\t Illegal string.\n", line_number);
            break;
        case INVALID_REGISTER_FOR_INDEX:
            printf("%lu\t Invalid register for index.\n", line_number);
            break;
        case ILLEGAL_OPERAND:
            printf("%lu\t Illegal operand.\n", line_number);
            break;
        case ILLEGAL_COMMA:
            printf("%lu\t Illegal comma in line.\n", line_number);
            break;
        case MISSING_COMMA:
            printf("%lu\t Missing comma in line\n", line_number);
            break;
        case BOTH_ENTRY_AND_EXTERN_FOR_SAME_SYMBOL:
            printf("%lu\t Both entry and extern for same symbol\n", line_number);
            break;
        case MEMORY_OVERFLOW:
            printf("%lu\t Memory overflow\n", line_number);
            break;
        case STRING_NOT_EXIST:
            printf("%lu\t String not exist\n", line_number);
            break;
        case TOO_LONG_LINE:
            printf("%lu\t This line is too long\n", line_number);
            break;
        default:
            printf("%lu\t Im in the default case - we have a problem.\n", line_number);
            break;
    }
}