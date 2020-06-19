#include "funkcje_pom.h"

/***************
****program4****
***************/

void odbierz4(unsigned int  * liczba);
void modyfikuj4(unsigned int liczba, unsigned int * wynik, char * string );
bool read_bit(unsigned int * n, int position);
void reverse_bits(unsigned int * n);
void print_bits(unsigned int * n);

int main(void) {
    //deklaracje
    unsigned int liczba;
	unsigned int wynik;
	char string_wynik[10];

    powitanie(4,20);

    //wczytujemy liczbę
    odbierz4(&liczba);
	//modyfikacja liczby
    modyfikuj4(liczba, &wynik, string_wynik);

	komunikat(4, liczba, wynik);
    printf("Liczba wejściowa w postaci binarnej:\n");
    print_bits(&liczba);
    printf("Liczba wyjściowa w postaci binarnej:\n");
    print_bits(&wynik);

    printf("Uruchamiam program 5 z argumentem %d\n", wynik);
    sleep(SLEEP_TIME);
	run_prog_with_args("executables/prog5.out",string_wynik);
	return 0;
}
void odbierz4(unsigned int  * liczba) {
    int fd;
    char buffer[10];
    fd = open(chardev_path, O_RDONLY);
    if (fd < 0) {
        perror("Błąd otwarcia urządzenia CHARDEV");
        exit(0);
    }
    if ( read(fd, buffer, sizeof(buffer) < 0) ){
        perror("Błąd czytania z  chardev");
        exit(0);
    }
    close(fd);
    *liczba = atoi(buffer);
}
bool read_bit(unsigned int * n, int position) {
	return !!(*n & (1 << position));
}

void reverse_bits(unsigned int * n) {
	int k;
	for(k = 0; k < 16; k++) {
		if( read_bit(n, k) != read_bit(n, 31- k)  ) {
			*n ^= (1 << k);
			*n ^= (1 << (31 - k));
		}
	}
}
void print_bits(unsigned int * n) {
	int k;
	for(k = 31; k >= 0; k--) {
		printf("%d", read_bit(n, k));
		if(k % 4 == 0) {
			printf(" ");
		}
	}
	printf("\n");
}
void modyfikuj4(unsigned int liczba, unsigned int * wynik, char * string ) {
    *wynik = liczba;
    reverse_bits(wynik);
    memset(string, 0, 10);
    sprintf(string, "%u", *wynik);
}
