#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcje_pom.h"

/***************
****program1****
***************/

int main(void) {
	unsigned int liczba;
	int wynik;
	char string[10];
	//printf("**************\nWitam w programie1!\n**************\n\n");
	powitanie(1,20);
	while(1) {
		printf("Tu program 1 \n\nPodaj liczbę całkowitą: ");

		//wczytujemy liczbę
		scanf("%u", &liczba);
		fflush(stdout);
		printf("Podałeś liczbę %d\n",liczba);

		//modyfikacja liczby
		wynik = liczba % 10;

		//zamieniamy liczbę na string
		sprintf(string,"%u",wynik);

		//modyfikacja liczby
		wynik = liczba % 10;

		printf("Liczba po modyfikacji: %d\n", wynik);
		//wywołanie programu 2
		printf("Uruchamiam program 2 z argumentem %d\n", wynik);
		run_prog_with_opt("prog2.out","o",string);
	}
	//run_prog_with_args("prog2.o",string);

}
