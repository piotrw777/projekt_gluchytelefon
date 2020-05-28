#include <stdio.h>
#include <stdlib.h>

/***************
****program3****
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

int main(int argc, char *argv[]) {
	int liczba = atoi(argv[1]);
	powitanie(3,20);
	printf("Argument, wywołania to: %s\n",argv[1]);
	printf("Ustawiam bit na miejscu %d: \n",1 << liczba);
}
