//
// Created by avishav on 10.3.2022.
//
void print_error(error to_print){

#include "errors.h"
void print_error(error to_print){
    switch (to_print) {
        case UNDEFINED_OPERATOR:
            printf("This operator not exist.\n");
            break;
        case DOUBLE_DEFINITION_OF_LABEL:
            printf("This label is already exist.\n");
            break;
        case ILLEGAL_SYMBOL_NAME:
            printf("Illegal symbol name.\n");
            break;
        case TOO_MANY_ARGS:
            printf("Too many operands.\n");
            break;
        case TOO_FEW_ARGS:
            printf("Too few operands.\n");
            break;
        case ILLEGAL_ADDRESSING:
            printf("Illegal addressing.\n");
            break;
        case INVALID_REGISTER_NAME:
            printf("Invalid register name.\n");
            break;
        case NOT_INT:
            printf("The number must be integer.\n");
            break;
        case NOT_IN_RANGE_IMMEDIATE:
            printf("Not in range for immediate addressing.\n");
            break;
        case UNDEFINED_SYMBOL:
            printf("Undefined symbol.\n");
            break;
        case TOO_MANY_CHARS:
            printf("Too many chars in line.\n");
            break;
        case ILLEGAL_DATA:
            printf("Illegal data.\n");
            break;
        case ILLEGAL_STRING:
            printf("Illegal string.\n");
            break;
        case SYNTAX_ERROR:
            printf("Illegal data.\n");
            break;
        case INVALID_REGISTER_FOR_INDEX:
            printf("Invalid register for index.\n");
            break;
        case ILLEGAL_OPERAND:
            printf("Illegal operand.\n");
            break;

        default:
            break;
    }
}