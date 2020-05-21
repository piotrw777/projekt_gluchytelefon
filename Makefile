CFLAGS=-pthread -g -Wpedantic -Wall -Werror -pedantic-errors -std=c11

all:	program1.o program2.o program3.o

program1.o:	program1.c funkcje_pom.h
	gcc $(CFLAGS) program1.c -o prog1.o
	@echo Kompilacja programu 1

program2.o:	program2.c funkcje_pom.h
	gcc $(CFLAGS) program2.c -o prog2.o
	@echo Kompilacja programu 2

program3.o:	program3.c funkcje_pom.h
	gcc $(CFLAGS) program3.c -o prog3.o
	@echo Kompilacja programu 3
	
run:
	./prog1.o
	@echo Uruchomienie programu 1

clean:
	rm -v *.o 
	@echo Usuwam pliki wykonywalne
