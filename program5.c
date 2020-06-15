#include "funkcje_pom.h"

/***************
****program5****
***************/

void modyfikuj5(unsigned int liczba, unsigned int * wynik, char * string );

int main(int argc, char *argv[]) {
    //deklaracje
	unsigned int liczba = atoi(argv[1]);
	unsigned int wynik;
    char string_wynik[10];

    powitanie(5,20);

    //odbieramy liczbę
    liczba = atoi(argv[1]);

    //modyfikacja
    modyfikuj5(liczba, &wynik, string_wynik);

    komunikat(5, liczba, wynik);

    pid_t pid = fork();
    if(pid < 0) {
        perror("Blad fork");
    }
    else if(pid == 0) {
        //printf("Jestem dzieckiem programu 6");
        send_by_localhost(wynik, 5, PORT_A);
    }
    else {
        fprintf(stderr,"Uruchamiam program 6. Wysłano liczbę %d przez TCP STREM", wynik);
        sleep(SLEEP_TIME);
        execl("./prog6.out", "0", NULL);
    }

	return 0;
}

void modyfikuj5(unsigned int liczba, unsigned int * wynik, char * string ) {
    *wynik = suma_cyfr(liczba);
    memset(string, 0, 10);
    sprintf(string, "%u", *wynik);
}
