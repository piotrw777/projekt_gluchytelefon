#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************
****program1****
***************/

void powitanie(int numer_prog, int stars) {
	int k;
	for(k = 0; k < stars; k++) {
		printf("*");
	}
	printf("\nWitam w programie %d!\n", numer_prog);
	for(k = 0; k < stars; k++) {
		printf("*");
	}
	printf("\n");
}
void run_prog_with_args(char program[], char  argument[]) {
	char string_wywolania[20]="./";
	char * wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, program);
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, " ");
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, argument);
	system(string_wywolania);
}
void run_prog_with_opt(char program[], char opcja[], char  argument[]) {
	char string_wywolania[20]="./";
	char * wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, program);
	wsk_pom = string_wywolania + strlen(string_wywolania);
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, " -");
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, opcja);
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, " ");
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, argument);
	system(string_wywolania);
}
int main(void) {
	unsigned int liczba;
	int wynik;
	char string[10];
	//printf("**************\nWitam w programie1!\n**************\n\n");
	powitanie(1,20);
	while(1) {
		printf("Podaj liczbę całkowitą: ");

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
		run_prog_with_opt("prog2.o","o",string);
	}
	//run_prog_with_args("prog2.o",string);


}
