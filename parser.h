//
// Created by avishav on 10.3.2022.
//

#ifndef EX14_PARSER_H
#define EX14_PARSER_H

/**
 * get line and check if start with a label definition - not check errors here
 * @param str line to check
 * @param chars_num number to update - How many characters are there from the beginning of the line to the colon(:) including
 * @return true if exist, -1 otherwise
 */
int is_symbol_def(char *line) ;

int is_extern_def(char *str);

int is_string_def(char *str);

int is_string(char *line);

int is_data_def(char *str);

int is_entry_def(char *str);

int is_comment(char *line);

int is_empty(char *line);

int is_reserved_word(char *word);

#endif //EX14_PARSER_H
