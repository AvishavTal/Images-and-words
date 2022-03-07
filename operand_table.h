//
// Created by avishav on 1.3.2022.
//

#ifndef EX14_OPERAND_TABLE_H
#define EX14_OPERAND_TABLE_H
/**
 * check  opname is name of legal operand, if true then funct and opcode get the value of the opname
 * @param opname
 * @param funct
 * @param opcode
 * @return 1 if the marco_table is_legal_operand the opname, 0 otherwise
 */
int is_legal_operand(const char *opname, int *funct, int *opcode);
#endif //EX14_OPERAND_TABLE_H
