/*
* Created by Avishav & Sapir on March 2, 2022
*/

#include <stdio.h>
#include "system_errors.h"
#include "string_manipulations.h"
#include "macro_table.h"
#include "file.h"
#include "parser.h"
#include "general_constants.h"
#include "boolean.h"

/* private function declaration */
void read_lines(file source, FILE *src, FILE *dest);
/* end of private function declaration */



/* public functions implementation */
void pre_assembler(file source) {
    FILE *src, *dest;
    src = fopen(get_name_as(source),"r");
    if (!is_open_file_succeeded(src,false, get_name_as(source))) {
        mark_pre_assembler_failed(source);
    } else {
        dest = fopen(get_name_am(source),"w");
        if (is_open_file_succeeded(dest,true, get_name_am(source))) {
            read_lines(source, src, dest);
            fclose(dest);
        }
        fclose(src);
    }
}
/* end of public functions implementation */



/* private functions implementation */
/*
 * this function is all the logic of pre assembler
 */
void read_lines(file source, FILE *src, FILE *dest) {
    boolean is_macro_definition = false;
    char line[LINE_LENGTH], *first_word_in_line;
    macro temp_macro;
    macro_table table = get_macro_table(source);
    while ((fgets(line,LINE_LENGTH,src) != NULL)) {
        first_word_in_line = str_tok(line," \t");
        first_word_in_line = trim_whitespace(first_word_in_line);
        if (!is_macro_definition) {
            if ((temp_macro = get_macro_by_name(table, first_word_in_line)) != NULL) {/*macro call*/
                macro_call(dest,temp_macro);
            } else if (start_of_macro_definition(first_word_in_line)) {
                char *name;
                temp_macro = init_macro();
                is_macro_definition = true;
                name = str_tok(NULL," \t");
                set_macro_name(temp_macro, name);
            } else {
                fprintf(dest,"%s",line);
            }
        } else {
            if (end_of_macro_definition(first_word_in_line)) {
                push_macro(table, temp_macro);
                is_macro_definition = false;
            } else {
                append_line(temp_macro,line);
            }
        }
    }
}
/* end of private functions implementation */