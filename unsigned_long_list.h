/*
* Created by avishav on 29.3.2022.
*/

#ifndef EX14_UNSIGNED_LONG_LIST_H
#define EX14_UNSIGNED_LONG_LIST_H
typedef struct unsigned_long_list *ul_list;
ul_list init_ul_list();
void append(ul_list to_update,unsigned long new_val);
unsigned long get_size(ul_list list);
void delete_ul_list(ul_list to_delete);
void get_next_val(ul_list list,unsigned long *dest);
#endif
