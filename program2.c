#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>  //dla getopt
#include <sys/types.h> // dla mkfifo
#include <sys/stat.h>  // dla mkfifo
#include "funkcje_pom.h"

/***************
****program2****
***************/

int main(int argc, char* argv[]) {
	int opt;
	char string_wynik[10] = "";
	int wynik;
	int stop;

	//tworzenie FIFO
	int fd;
    char *fifo_path = "/tmp/myfifo";
	printf("Jestem przed mkfifo\n");
	mkfifo(fifo_path,0777);
	printf("Jestem po mkfifo\n");
	fflush(stdout);
	powitanie(2,20);

	while( (opt = getopt(argc, argv, ":abco:")) != -1 ) {
		switch(opt) {
            case 'a':
            case 'b':
            case 'c':
                printf("Wybrano opcję: %c\nNic nie robię", opt);
                break;
            case 'o':
				fflush(stdout);
                printf("Argument z opcji to: %s\n", optarg);
				wynik = next_prime(atoi(optarg));
				sprintf(string_wynik,"%d",wynik);
                fflush(stdout);
				fflush(NULL);
				//zapis do FIFO
				fd = open(fifo_path,O_WRONLY);
				write(fd, string_wynik,sizeof(string_wynik));
				close(fd);

				fflush(stdout);
				fflush(NULL);
				printf("Następna liczba pierwsza to: %d\nUruchamiam program 3", wynik);
				//scanf("%d", &stop);
				system("./prog3.out");
				fflush(stdout);
				fflush(NULL);
                break;
        }
    }

}
