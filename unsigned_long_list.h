/*
* Created by Avishav & Sapir on March 29, 2022
*/

#ifndef EX14_UNSIGNED_LONG_LIST_H
#define EX14_UNSIGNED_LONG_LIST_H

/**
 * Representation of ul list
 */
typedef struct unsigned_long_list *ul_list;

/**
 * Returns new ul list with default values
 * @return new ul list with default values
 */
ul_list init_ul_list();

/**
 * add new value to ul list
 * @param to_update ul list to update
 * @param new_val new value
 */
void append(ul_list to_update,unsigned long new_val);

/**
 * Returns ul list size
 * @param list ul list
 * @return ul list size
 */
unsigned long get_size(ul_list list);

/**
 * Delete the received ul list and free all its allocations
 * @param to_delete ul list to delete
 */
void delete_ul_list(ul_list to_delete);

/**
 * Returns next value in ul list
 * @param list ul list
 * @param dest value
 */
void get_next_val(ul_list list,unsigned long *dest);

#endif