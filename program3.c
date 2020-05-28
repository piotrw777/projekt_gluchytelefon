#include <stdio.h>
#include <stdlib.h>
#include "funkcje_pom.h"




/***************
****program3****
***************/

int main(int argc, char *argv[]) {
	int liczba = atoi(argv[1]);
	powitanie(3,20);
	printf("Argument, wywołania to: %s\n",argv[1]);
	printf("Ustawiam bit na miejscu %d: \n",1 << liczba);
}
