#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************
****program1****
***************/

int main(void) {
	int liczba;
	char string[10];

	char string_wywolania[20]="./prog2.o ";
	char *arg_wsk = string_wywolania + 10;

	printf("**********\nWitam w programie1!\n***********\n");
	printf("Podaj liczbę całkowitą: ");
	scanf("%d", &liczba);
	fflush(stdout);
	printf("Podałeś liczbę %d\n",liczba);
	sprintf(string,"%d",liczba);
	printf("Liczba w postaci strigu to %s\n",string);
	strcpy(arg_wsk,string);
	system(string_wywolania);


}
