#include <stdio.h>
#include "funkcje_pom.h"

int main(void) {
	printf("Witam w programie1!\n");
	int k,p=1;
	for(k = 0; k < 10; k++) {
		p *= 2;
		printf("p wynosi %d\n",p);
	}
}
