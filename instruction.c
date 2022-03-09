//
// Created by avishav on 28.2.2022.
//

#include "instruction.h"
#include "word.h"
struct instruction{
    int n_words;/*number of words in the machine code*/
    word *words;
};

void print_instruction(FILE *dest,instruction to_print){
    int i=0;
    for (; i<to_print->n_words ; ++i) {
        print_word(dest,to_print->words[i]);
    }
}

instruction init_instruction(char *line, symbol_table symbols, unsigned long *ic){
    return NULL;
}
