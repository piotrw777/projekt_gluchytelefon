#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>    //dla sqrt
#include <unistd.h>  //dla getopt

typedef int bool;

/***************
****program2****
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

bool is_prime(int n) {
	if(n < 2) return 0;
	if(n == 2) return 1;
	//jeśli parzysta zwróć fałsz
	if(n % 2 == 0) return 0;

	int k_max = (int) sqrt(n) + 1;
	int k = 3;
	while(k < k_max) {
		if((n % k) == 0) {
			return 0;
		}
		k += 2;
	}
	return 1;
}

int next_prime(int n) {
	if(n == 1) return 2;
	if(n == 2) return 3;

	int k = n + 1 + n%2;

	while(is_prime(k) == 0) k++;

	return k;
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
				
				run_prog_with_args("prog3.o", string_wynik);
                break;
        }
    }


	//printf("Argument, wywołania to: %s\n",argv[1]);
	//printf("Zwiększam argument o dwa: %d\n", liczba + 2);


}

