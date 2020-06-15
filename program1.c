#include "funkcje_pom.h"

/***************
****program1****
***************/

void odbierz1(unsigned int * liczba);
void modyfikuj1(unsigned int liczba, unsigned int * wynik, char * string );

int main(void) {
    //deklaracje
	unsigned int liczba;
	unsigned int wynik;
	char string_wynik[10];

	powitanie(1,20);

	while(1) {
		printf("\n******\nTu program 1: Podaj liczbę całkowitą: ");

		//wczytujemy liczbę
        odbierz1(&liczba);

        //modyfikacja liczby
        modyfikuj1(liczba, &wynik, string_wynik);

        komunikat(1, liczba, wynik);

		//wywołanie programu 2
		printf("Uruchamiam program 2 z argumentem %d\n", wynik);
		sleep(SLEEP_TIME);
		run_prog_with_opt("executables/prog2.out","o",string_wynik);
	}

}
void odbierz1(unsigned int * liczba) {
    scanf("%u", liczba);
    fflush(stdout);
}

void modyfikuj1(unsigned int liczba, unsigned int * wynik, char * string ) {
     *wynik = liczba % 10;
     memset(string, 0, 10);
     sprintf(string, "%u", *wynik);
}
