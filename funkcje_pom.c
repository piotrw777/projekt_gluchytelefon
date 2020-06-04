#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funkcje_pom.h"


void powitanie(int numer_prog, int stars) {
	int k;
	printf("\n\n");
	for(k = 0; k < stars; k++) {
		printf("*");
	}
	printf("\nWitam w programie %d!\n", numer_prog);
	for(k = 0; k < stars; k++) {
		printf("*");
	}
	printf("\n\n");
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
void run_prog_with_opt(char program[], char opcja[], char  argument[]) {
	char string_wywolania[20]="./";
	char * wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, program);
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, " -");
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, opcja);
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, " ");
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, argument);
	system(string_wywolania);
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
	if(n < 2) return 2;
	if(n == 2) return 3;

	int k = n + 1 + n%2;

	while(is_prime(k) == 0) {
		k += 2;
	}

	return k;
}

bool read_bit(int * n, int position) {
	return !!(*n & (1 << position));
}

void reverse_bits(int * n) {
	int k;
	for(k = 0; k < 16; k++) {
		if( read_bit(n, k) != read_bit(n, 31- k)  ) {
			*n ^= (1 << k);
			*n ^= (1 << (31 - k));
		}
	}
}

void print_bits(int * n) {
	int k;
	for(k = 31; k >= 0; k--) {
		printf("%d", read_bit(n, k));
		if(k % 4 == 0) {
			printf(" ");
		}
	}
	printf("\n");
}

int suma_cyfr(unsigned int n) {
	int s = n % 10;
	while(n > 9) {
		n /= 10;
		s += n % 10;
	}
	return s;
}


