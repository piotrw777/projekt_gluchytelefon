CFLAGS=-pthread -g -Wpedantic -Wall -pedantic-errors 
JAJKO=modul_jajko

all:	prog1.out prog2.out prog3.out prog4.out prog5.out prog6.out module

apps:   prog1.out prog2.out prog3.out prog4.out prog5.out prog6.out

prog1.out:	prog1.o funkcje_pom.o
	@echo Linkowanie programu 1
	gcc $(CFLAGS)   ./compiled/prog1.o ./compiled/funkcje_pom.o -o ./executables/prog1.out 
	 

prog2.out:	prog2.o funkcje_pom.o
	@echo Linkowanie programu 2
	gcc $(CFLAGS)   ./compiled/prog2.o ./compiled/funkcje_pom.o -o ./executables/prog2.out -lm
	

prog3.out:	prog3.o funkcje_pom.o
	@echo Linkowanie programu 3
	gcc $(CFLAGS)   ./compiled/prog3.o ./compiled/funkcje_pom.o -o ./executables/prog3.out 
 

prog4.out:	prog4.o funkcje_pom.o
	@echo Linkowanie programu 4
	gcc $(CFLAGS)   ./compiled/prog4.o ./compiled/funkcje_pom.o -o ./executables/prog4.out  

prog5.out:	prog5.o funkcje_pom.o
	@echo Linkowanie programu 5
	gcc $(CFLAGS)   ./compiled/prog5.o ./compiled/funkcje_pom.o -o ./executables/prog5.out  

prog6.out:	prog6.o funkcje_pom.o
	@echo Linkowanie programu 6
	gcc $(CFLAGS)   ./compiled/prog6.o ./compiled/funkcje_pom.o -o ./executables/prog6.out  
	
prog1.o:	program1.c funkcje_pom.h
	@echo Kompilacja programu 1
	gcc $(CFLAGS)  -c program1.c -o ./compiled/prog1.o

prog2.o:	program2.c funkcje_pom.h
	@echo Kompilacja programu 2
	gcc $(CFLAGS)  -c program2.c -o ./compiled/prog2.o -lm

prog3.o:	program3.c funkcje_pom.h
	@echo Kompilacja programu 3
	gcc $(CFLAGS)  -c program3.c -o ./compiled/prog3.o 
	
prog4.o:	program4.c funkcje_pom.h
	@echo Kompilacja programu 4
	gcc $(CFLAGS)  -c program4.c -o ./compiled/prog4.o

prog5.o:	program5.c funkcje_pom.h
	@echo Kompilacja programu 5
	gcc $(CFLAGS)  -c program5.c -o ./compiled/prog5.o

prog6.o:	program6.c funkcje_pom.h
	@echo Kompilacja programu 6
	gcc  -c program6.c -o ./compiled/prog6.o 
	
funkcje_pom.o:	funkcje_pom.c funkcje_pom.h
	@echo Kompilacja pliu z funkcjami
	gcc $(CFLAGS) -c funkcje_pom.c -o ./compiled/funkcje_pom.o 

module:
	cd $(JAJKO) && $(MAKE) 

run:
	@echo Uruchomienie programu 1
	sudo ./executables/prog1.out

clean:
	@echo Usuwam pliki binarne
	rm -v ./compiled/*.o 
	rm -v ./executables/*.out
