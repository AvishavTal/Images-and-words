CC=gcc
CFLAGS=-Wall -ansi -pedantic

ASSEMBLER_OBJ_FILES=assembler.o data_image.o errors.o file.o first_scan.o instruction.o linked_list.o macro.o macro_body.o macro_table.o operator_table.o parser.o pre_assembler.o register_table.o second_scan.o string_manipulations.o symbol.o symbol_table.o system_errors.o unsigned_long_list.o word.o

%.o: %.c %.h
	$(CC) -c $< -o $@ $(CFLAGS)

assembler: $(ASSEMBLER_OBJ_FILES) *.h
	$(CC) $(CFLAGS) -o assembler $(ASSEMBLER_OBJ_FILES)

.PHONY: clean

clean:
	rm -f *.o