#include "funkcje_pom.h"
#include <limits.h>

/***************
****program1****
***************/

bool is_number(const char *string);
void odbierz1(unsigned int * liczba);
void modyfikuj1(unsigned int liczba, unsigned int * wynik, char * string );


int main(void) {
    //deklaracje
	unsigned int liczba;
	unsigned int wynik;
	char string_wynik[10];

	powitanie(1,20);


   /* //test leq
    char a[20];
    char b[20];
    while(1) {
        printf("Podaj str1: ");
        scanf("%s", a);
        printf("Podaj str2: ");
        scanf("%s", b);
        printf("%s", (leq(a,b)) ? "a <= b\n" : "a > b\n");
    }
*/
	while(1) {
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
bool is_number(const char * string) {
    int str_size = strlen(string);
    int k = 0;
    if( (string[0] == '+') || (string[0] == '-') )  k = 1;
    for(; k < str_size; k++) {

        if( (string[k] < '0') || (string[k] > '9' ) ) return 0;

    }
    return 1;
}

void odbierz1(unsigned int * liczba) {
    char string_wej[1024] = {0};
    bool status_str;
    bool status_nr = 1;
    do{
        do{

            printf(BLUE"\nTu program 1. Podaj liczbę całkowitą w zakresie 0 - %u: "RESET, UINT_MAX);
            fflush(stdin);
            scanf("%s", string_wej);
            status_str = is_number(string_wej);
            printf("Podałeś: %s\n", string_wej);
            if(status_str == 0) {
                printf("Wpisany string nie jest liczbą");
            }
            fflush(stdout);
        } while(status_str == 0);

        if(leq(string_wej,"-1")){
            printf("Podałeś liczbę ujemną");
            status_nr = 0;
        }
        else if(leq(string_wej, UINT_MAX_STR) == 1) {
            *liczba = atoll(string_wej);
            status_nr = 1;
        }
        else {
            printf("Podałeś zbyt dużą liczbę");
            status_nr = 0;
        }
    }while(status_nr == 0);
}

void modyfikuj1(unsigned int liczba, unsigned int * wynik, char * string ) {
     *wynik = liczba % 10;
     memset(string, 0, 10);
     sprintf(string, "%u", *wynik);
}
