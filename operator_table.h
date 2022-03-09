//
// Created by avishav on 1.3.2022.
//

#ifndef EX14_OPERATOR_TABLE_H
#define EX14_OPERATOR_TABLE_H
typedef struct operator *operator;
operator get_operator_by_mame(char *name);
int get_opcode(operator op);
int get_funct(operator op);
int get_n_operands(operator op);
/**
 * check  opname is name of legal operand, if true then funct and opcode get the value of the opname
 * @param opname
 * @param funct
 * @param opcode
 * @return 1 if the marco_table is_legal_operator the opname, 0 otherwise
 */

int is_legal_operator(const char *opname, int *funct, int *opcode);
#endif //EX14_OPERATOR_TABLE_H
