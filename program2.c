#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcje_pom.h"

/***************
****program2****
***************/

int main(int argc, char* argv[]) {

	int liczba = atoi(argv[1]);
	printf("**********\nWitam w programie2!\n**********\n");
	printf("Argument, wywołania to: %s\n",argv[1]);
	printf("Zwiększam argument o dwa: %d", liczba + 2);

}
