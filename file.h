//
// Created by Avishav & Sapir on March 4,2022
//

#ifndef EX14_FILE_H
#define EX14_FILE_H

#include "macro_table.h"
#include "symbol_table.h"
#include "data_image.h"
#include "boolean.h"

typedef struct file *file;

/**
 * Get the name of the file and create new file
 * @param name the name of the file
 * @return new file
 */
file init_file(char *name);

/**
 * Return the file's name
 * @param file the needed file
 * @return the name of the file
 */
char *get_name(file file);

/**
 * Returns the name of the file with the .as extension
 * @param file the needed file
 * @return the name of the file  with the .as extension
 */
char *get_name_as(file file);

/**
 * Set the name of the file to be the accepted name with the .as extension
 * @param file the needed file
 */
void set_name_as(file file);

/**
 * Returns the name of the file with the .am extension
 * @param file the needed file
 * @return the name of the file  with the .am extension
 */
char *get_name_am(file file);

/**
 * Set the name of the file to be the accepted name with the .am extension
 * @param file the needed file
 */
void set_name_am(file file);

/**
 * Returns the name of the file with the .ob extension
 * @param file the needed file
 * @return the name of the file  with the .ob extension
 */
char *get_name_ob(file file);

/**
 * Set the name of the file to be the accepted name with the .ob extension
 * @param file the needed file
 */
void set_name_ob(file file);

/**
 * Returns the name of the file with the .ent extension
 * @param file the needed file
 * @return the name of the file  with the .ent extension
 */
char *get_name_ent(file file);

/**
 * Set the name of the file to be the accepted name with the .ent extension
 * @param file the needed file
 */
void set_name_ent(file file);

/**
 * Returns the name of the file with the .ext extension
 * @param file the needed file
 * @return the name of the file  with the .ext extension
 */
char *get_name_ext(file file);

/**
 * Set the name of the file to be the accepted name with the .ext extension
 * @param file the needed file
 */
void set_name_ext(file file);

/**
 * Returns the macro table of the file
 * @param file the needed file
 * @return the macro table of the file
 */
macro_table get_macro_table(file file);

/**
 * Returns the symbol table of the file
 * @param file the needed file
 * @return the symbol table of the file
 */
symbol_table get_symbol_table(file file);

/**
 * Returns the data image of the file
 * @param file the needed file
 * @return the data image of the file
 */
data_image get_data_image(file file1);

/**
 * Returns if ob file exist
 * @param file the needed file
 * @return true if the ob file exist false if not
 */
boolean is_ob_file_exist(file file);

/**
 * Set ob file flag to true - exist file
 * @param file the needed file
 */
void mark_ob_file_exist(file file);

/**
 * Set ob file flag to false - not exist file
 * @param file the needed file
 */
void mark_ob_file_not_exist(file file);

/**
 * Returns if the pre assembler has passed successfully
 * @param file the needed file
 * @return true if the pre assembler has passed successfully and false if not
 */
boolean has_passed_pre_assembler(file file);

/**
 * Set the pre assembler flag to false - it means that something went wrong in the pre assembler
 * @param file the needed file
 */
void mark_pre_assembler_failed(file file);

/**
 * Returns if the first scan has passed successfully
 * @param file the needed file
 * @return true if the first scan has passed successfully and false if not
 */
boolean has_passed_first_scan(file file);

/**
 * Set the first scan flag to false - it means that something went wrong in the first scan
 * @param file the needed file
 */
void mark_first_scan_failed(file file);

/**
 * Returns if the second scan has passed successfully
 * @param file the needed file
 * @return true if the second scan has passed successfully and false if not
 */
boolean has_passed_second_scan(file file);

/**
 * Set the second scan flag to false - it means that something went wrong in the second scan
 * @param file the needed file
 */
void mark_second_scan_failed(file file);

/**
 * Returns the final IC(instruction counter) that accepted after the first scan
 * @param file the needed file
 * @return the final IC(instruction counter) that accepted after the first scan
 */
long get_final_ic(file file);

/**
 * Set the final IC(instruction counter) to the number that gets after first scan
 * @param file the needed file
 * @param final_ic the final IC(instruction counter) that gets after first scan
 */
void set_final_ic(file file, long final_ic);

/**
 * Returns the final DC(data counter) that accepted after the first scan
 * @param file the needed file
 * @return the final DC(data counter) that accepted after the first scan
 */
long get_final_dc(file file);

/**
 * Set the final DC(data counter) to the number that gets after first scan
 * @param file the needed file
 * @param final_ic the final DC(data counter) that gets after first scan
 */
void set_final_dc(file file, long final_dc);

#endif //EX14_FILE_H