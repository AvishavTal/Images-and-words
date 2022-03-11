//
// Created by avishav on 10.3.2022.
//

#ifndef EX14_ERRORS_H
#define EX14_ERRORS_H
typedef enum {NOT_ERROR,UNDEFINED_OPERATOR,DOUBLE_DEFINITION_OF_LABEL,ILLEGAL_SYMBOL_NAME}error;
void print_error(error to_print);
#endif //EX14_ERRORS_H
