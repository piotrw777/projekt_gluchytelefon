#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>  //dla getopt
#include <sys/types.h> // dla mkfifo
#include <sys/stat.h>  // dla mkfifo
#include "funkcje_pom.h"

/***************
****program3****
***************/

int main() {
	powitanie(3,20);
	int fd;
	char *fifo_path = "/tmp/myfifo";
	char buf[10];
	mkfifo(fifo_path, 0777);

	fd = open(fifo_path, O_RDONLY);
	read(fd, buf,sizeof(buf));
	close(fd);
	int liczba = atoi(buf);
	int wyjscie = (1 << liczba);
	wyjscie = wyjscie + 1 - 1;


	fflush(NULL);

	printf("Liczba z fifo to: %s (string), %d( liczba)\n",buf,atoi(buf));
	printf("Ustawiam bit na miejscu %d. Wynik: %d\n",liczba,1 << liczba);
}
