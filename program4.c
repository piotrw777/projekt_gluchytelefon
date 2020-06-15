#include "funkcje_pom.h"

/***************
****program4****
***************/

void modyfikuj4(unsigned int liczba, unsigned int * wynik, char * string );

int main(int argc, char *argv[]) {
    //deklaracje
    unsigned int liczba;
	unsigned int wynik;
	char string_wynik[10];

    powitanie(4,20);

    //wczytujemy liczbę
	liczba = atoi(argv[1]);

	//modyfikacja liczby
    modyfikuj4(liczba, &wynik, string_wynik);

	komunikat(4, liczba, wynik);

    printf("Uruchamiam program 5 z argumentem %d\n", wynik);
    sleep(SLEEP_TIME);
	run_prog_with_args("prog5.out",string_wynik);
	return 0;
}

void modyfikuj4(unsigned int liczba, unsigned int * wynik, char * string ) {
    *wynik = liczba;
    reverse_bits(wynik);
    memset(string, 0, 10);
    sprintf(string, "%u", *wynik);
}
