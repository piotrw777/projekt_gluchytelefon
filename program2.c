#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  //dla getopt
#include "funkcje_pom.h"

/***************
****program2****
***************/

int main(int argc, char* argv[]) {
    int opt;
	char string_wynik[10];
	int wynik;
	
    fflush(stdout);
	powitanie(2,20);

    while((opt = getopt(argc, argv, ":abco:")) != -1) {
		switch(opt) {
            case 'a':
            case 'b':
            case 'c':
                printf("Wybrano opcję: %c\nNic nie robię", opt);
                break;
            case 'o':
				fflush(stdout);
                printf("Argument z opcji to: %s\n", optarg);
				wynik = next_prime(atoi(optarg));
				sprintf(string_wynik,"%d",wynik);
				printf("Następna liczba pierwsza to: %d\n", wynik);
				printf("Uruchamiam program 3 z argumentem %s\n", string_wynik);
				
				run_prog_with_args("prog3.out", string_wynik);
                break;
        }
    }


	//printf("Argument, wywołania to: %s\n",argv[1]);
	//printf("Zwiększam argument o dwa: %d\n", liczba + 2);


	
	
	
	
}

