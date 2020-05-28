CFLAGS=-pthread -g -Wpedantic -Wall -Werror -pedantic-errors -std=c11 

all:	prog1.o prog2.o prog3.o 

prog1.o:	program1.c 
	@echo Kompilacja programu 1
	gcc $(CFLAGS)  program1.c -o prog1.o
	 

prog2.o:	program2.c 
	@echo Kompilacja programu 2
	gcc $(CFLAGS)  program2.c -o prog2.o -lm
	

prog3.o:	program3.c 
	@echo Kompilacja programu 3
	gcc $(CFLAGS)  program3.c -o prog3.o 
	
run:
	@echo Uruchomienie programu 1
	./prog1.o

clean:
	@echo Usuwam pliki wykonywalne
	rm -v *.o 
	
