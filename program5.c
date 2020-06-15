#include "funkcje_pom.h"

/***************
****program5****
***************/

int main(int argc, char *argv[]) {

    powitanie(5,20);
	int liczba = atoi(argv[1]);
	int wynik = suma_cyfr(liczba);

    printf("Otrzymana liczba: %d\n", liczba);
    printf("Liczba po modyfikacji: %d (suma cyfr)\n", wynik);

	char string_wynik[10];
	memset(string_wynik,0,10);
	sprintf(string_wynik, "%d", wynik);

    pid_t pid;
    pid = fork();
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

