assembler: assembler.o file.o complex.o string_manipulations.o
	gcc -g -Wall -ansi -pedantic file.o main.o pre_assembler.o first_scan.o second_scan.o -o images_and_words
mycomp.o: mycomp.c
	gcc -g -Wall -ansi -pedantic mycomp.c -c
command.o: command.c
	gcc -g -Wall -ansi -pedantic command.c -c
complex.o: complex.c
	gcc -g -Wall -ansi -pedantic complex.c -c -lm
string_manipulations.o: string_manipulations.c
	gcc -g -Wall -ansi -pedantic string_manipulations.c -c
clean:
	rm *.o