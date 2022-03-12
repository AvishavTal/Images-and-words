//
// Created by avishav on 10.3.2022.
//

#ifndef EX14_PARSER_H
#define EX14_PARSER_H

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
