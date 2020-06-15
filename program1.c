#include "funkcje_pom.h"

/***************
****program1****
***************/

int main(void) {
	unsigned int liczba;
	int wynik;
	char string[10];
	powitanie(1,20);
	while(1) {
		printf("\n******\nTu program 1: Podaj liczbę całkowitą: ");

		//wczytujemy liczbę
		scanf("%u", &liczba);
		fflush(stdout);
        wynik = liczba % 10;
        sprintf(string,"%u",wynik);

        printf("Podałeś liczbę %d\n",liczba);
		printf("Liczba po modyfikacji: %d (mod 10)\n", wynik);

		//wywołanie programu 2
		printf("Uruchamiam program 2 z argumentem %d\n", wynik);
		sleep(SLEEP_TIME);
		run_prog_with_opt("prog2.out","o",string);
	}

}
