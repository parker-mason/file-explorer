terminal: main.o file_explorer.o
	gcc main.o file_explorer.o -o terminal

main.o: main.c file_explorer.h
	gcc -c main.c

file_explorer.o: file_explorer.c file_explorer.h
	gcc -c file_explorer.c

clean: 
	rm -f *o
	rm -f terminal