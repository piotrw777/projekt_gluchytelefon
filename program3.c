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

int main(int argc, char* argv[]) {
	powitanie(3,20);
	
	
	//char *out_path = "./prog3out.txt";
    //FILE *plik_out;
    //plik_out = fopen(out_path,"w");
    //fprintf(plik_out,"hej, tu program 3");

	//odczytujemy liczbę z FIFO
	char *fifo_path = "/tmp/myfifo";
	char buf[10];
	int fd;
	fd = open(fifo_path, O_RDONLY);
	if (read(fd, buf,sizeof(buf)) < 0) {
		perror("Błąd czytania z FIFO - program 3");
		exit(0);
	}
	close(fd);
	unlink(fifo_path);

	int liczba = atoi(buf);
	printf("Otrzymana liczba: %d\n", liczba);
	int wynik = (1 << liczba);
	printf("Liczba po modyfikacji: %d (odwrócenie bitów)\n",wynik);
	
	//fclose(plik_out);
}
