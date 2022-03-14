//
// Created by avishav on 10.3.2022.
//

#ifndef EX14_REGISTER_TABLE_H
#define EX14_REGISTER_TABLE_H
typedef struct reg *regyster;
regyster get_register_by_name(char *name);
int get_regcode(regyster register1);
int is_valid_index(regyster index);
#endif //EX14_REGISTER_TABLE_H
