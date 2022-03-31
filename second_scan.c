/*
* Created by Avishav & Sapir on March 1, 2022
*/

#include <stdio.h>
#include <string.h>
#include "second_scan.h"
#include "symbol_table.h"
#include "string_manipulations.h"
#include "symbol.h"
#include "instruction.h"
#include "parser.h"
#include "first_and_second_scan_constants.h"
#include "errors.h"
#include "system_errors.h"

void clean_up(file to_clean);

void make_ob_file_head(FILE *ob_file, file source);

void entry_definition(symbol_table symbols, error *err);

void instruction_call(char *line, symbol_table symbols, unsigned long *ic, error *err, file source, FILE *dest);

void error_line(long line_number, error err, file source);

void append_data_image(file source, FILE *dest);

void close_files(file source, FILE *src, FILE *dest);

void skip_symbol(char **line, char **first_word);

void second_scan(file source){
    symbol_table symbols;
    long line_number=0;
    char *temp_line,line[LINE_LENGTH],*first_word_in_line;
    unsigned long ic=MIN_IC;
    FILE *src,*dest;
    error error1=NOT_ERROR;
    symbols= get_symbol_table(source);
    src= fopen(get_name_am(source),"r");
    if (!is_open_file_succeeded(src,false, get_name_am(source))){
        mark_second_scan_failed(source);
    } else{
        dest= fopen(get_name_ob(source),"w");
        if (is_open_file_succeeded(dest,true, get_name_ob(source))){
            mark_ob_file_exist(source);
            make_ob_file_head(dest, source);
            while ((fgets(line,LINE_LENGTH,src))!=NULL){
                temp_line= trim_whitespace(line);
                line_number++;
                error1=NOT_ERROR;
                if (!is_comment(temp_line)&&!is_empty(temp_line)){
                    first_word_in_line=str_tok(temp_line," \t");
                    if(is_symbol_def(first_word_in_line)){
                        skip_symbol(&temp_line,&first_word_in_line);
                    }
                    if (first_word_in_line!=NULL && !is_extern_def(first_word_in_line) && !is_string_def(first_word_in_line) && !is_data_def(first_word_in_line)){
                        if (is_entry_def(first_word_in_line)){
                            entry_definition(symbols,&error1);
                        } else{
                            instruction_call(temp_line, symbols, &ic, &error1, source, dest);
                        }
                        if (error1!=NOT_ERROR){
                            error_line(line_number,error1,source);
                        }
                    }
                }
            }
            append_data_image(source,dest);
            close_files(source,src,dest);
        }
    }
}

/*
 * ignore the label at the beginning of a given line
 */
void skip_symbol(char **line, char **first_word) {
    *line=*line+ strlen(*first_word)+1;
    *first_word= str_tok(NULL," \t");
    if (*first_word){
        *first_word=trim_whitespace(*first_word);
    }
}

/*
 * close the input and output files
 */
void close_files(file source, FILE *src, FILE *dest) {
    fclose(src);
    if (is_ob_file_exist(source)){
        fclose(dest);
    }
}

/*
 * append the data image to the output file
 */
void append_data_image(file source, FILE *dest) {
    data_image image= get_data_image(source);
    print_data(dest,image);
}

/*
 * deal with error line
 */
void error_line(long line_number, error err, file source) {
    print_error(line_number,err);
    mark_second_scan_failed(source);
    clean_up(source);
}

/*
 * deal with instruction call line
 */
void instruction_call(char *line, symbol_table symbols, unsigned long *ic, error *err, file source, FILE *dest) {
    instruction temp_instruction;
    temp_instruction= init_instruction(line, symbols, *ic, err);
    *ic += get_n_words(temp_instruction);
    if(is_ob_file_exist(source)){
        print_instruction(dest,temp_instruction);
    }
    delete_instruction(temp_instruction);
}

/*
 * deal with line that define symbol as entry.
 */
void entry_definition(symbol_table symbols, error *err) {
    char *symbol_name;
    symbol to_update;
    symbol_name= str_tok(NULL," \t");
    to_update= get_symbol_by_name(symbols, symbol_name);
    if (to_update!=NULL){
        if (get_is_extern_symbol(to_update)){
            *err=BOTH_ENTRY_AND_EXTERN_FOR_SAME_SYMBOL;
        }
        mark_entry(to_update);
    } else{
        *err=UNDEFINED_SYMBOL;
    }
}

/*
 * print to the object the part before the code image
 */
void make_ob_file_head(FILE *ob_file, file source) {
    unsigned long ic,dc;
    ic= get_final_ic(source);
    dc= get_final_dc(source);
    fprintf(ob_file,"%lu %lu\n",ic,dc);
}

void clean_up(file to_clean) {
    if (is_ob_file_exist(to_clean)){
        remove(get_name_ob(to_clean));
        mark_ob_file_not_exist(to_clean);
    }

}