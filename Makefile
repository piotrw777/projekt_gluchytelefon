CFLAGS=-pthread -g -Wpedantic -Wall -pedantic-errors 

all:	prog1.out prog2.out prog3.out prog4.out prog5.out prog6.out

prog1.out:	prog1.o funkcje_pom.o
	@echo Linkowanie programu 1
	gcc $(CFLAGS)   prog1.o funkcje_pom.o -o prog1.out -lm
	 

prog2.out:	prog2.o funkcje_pom.o
	@echo Linkowanie programu 2
	gcc $(CFLAGS)   prog2.o funkcje_pom.o -lm -o prog2.out -lm
	

prog3.out:	prog3.o funkcje_pom.o
	@echo Linkowanie programu 3
	gcc $(CFLAGS)   prog3.o funkcje_pom.o -o prog3.out -lm

prog4.out:	prog4.o funkcje_pom.o
	@echo Linkowanie programu 4
	gcc $(CFLAGS)   prog4.o funkcje_pom.o -o prog4.out -lm

prog5.out:	prog5.o funkcje_pom.o
	@echo Linkowanie programu 5
	gcc $(CFLAGS)   prog5.o funkcje_pom.o -o prog5.out -lm

prog6.out:	prog6.o funkcje_pom.o
	@echo Linkowanie programu 6
	gcc   $(CFLAGS) prog6.o funkcje_pom.o -o prog6.out -lm
	
prog1.o:	program1.c funkcje_pom.h
	@echo Kompilacja programu 1
	gcc $(CFLAGS)  -c program1.c -o prog1.o
	 

prog2.o:	program2.c funkcje_pom.h
	@echo Kompilacja programu 2
	gcc $(CFLAGS)  -c program2.c -o prog2.o -lm

prog3.o:	program3.c funkcje_pom.h
	@echo Kompilacja programu 3
	gcc $(CFLAGS)  -c program3.c -o prog3.o 
	
prog4.o:	program4.c funkcje_pom.h
	@echo Kompilacja programu 4
	gcc $(CFLAGS)  -c program4.c -o prog4.o

prog5.o:	program5.c funkcje_pom.h
	@echo Kompilacja programu 5
	gcc $(CFLAGS)  -c program5.c -o prog5.o

prog6.o:	program6.c funkcje_pom.h
	@echo Kompilacja programu 6
	gcc  -c program6.c -o prog6.o 
	
funkcje_pom.o:	funkcje_pom.c funkcje_pom.h
	@echo Kompilacja pliu z funkcjami
	gcc $(CFLAGS) -c funkcje_pom.c -o funkcje_pom.o -lm
run:
	@echo Uruchomienie programu 1
	./prog1.out

clean:
	@echo Usuwam pliki binarne
	rm -v *.o 
	rm -v *.out
	
