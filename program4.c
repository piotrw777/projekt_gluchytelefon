#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "funkcje_pom.h"

/***************
****program4****
***************/

int main(int argc, char *argv[])
{
    powitanie(4,20);

	int liczba = atoi(argv[1]);
	int wynik = liczba;
	char string_wynik[10];
	reverse_bits(&wynik);
	sprintf(string_wynik, "%d", wynik);

	printf("Otrzymana liczba: %d\n", liczba);
    printf("Liczba po modyfikacji: %d (odwrócenie bitów)\n", wynik);

    printf("Uruchamiam program 5 z argumentem %d\n", wynik);
    sleep(SLEEP_TIME);
	run_prog_with_args("prog5.out",string_wynik);
	return 0;
}
