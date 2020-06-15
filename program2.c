#include "funkcje_pom.h"

/***************
****program2****
***************/

int main(int argc, char* argv[]) {

    powitanie(2,20);

    char *fifo_path = "/tmp/myfifo";

    int liczba = parseCmdOption(argc, argv);
	int wynik = next_prime(liczba);
    char string_wynik[10];
    sprintf(string_wynik,"%d",wynik);

    printf("Otrzymana liczba: %d\n", liczba);
    printf("Liczba po modyfikacji: %d (następna liczba pierwsza)\n",wynik);

  	//zapis do FIFO
	int fd;
    unlink(fifo_path);
	mkfifo(fifo_path,0666);

    pid_t pid;
    pid = fork();

    if (pid == -1) {
        perror("Fork error");
        exit(0);
    }
    else if (pid == 0) {
            //printf("Jestem dzieckiem prog 2\n");
            // close exit
            fd = open(fifo_path,O_WRONLY);
            if (write(fd, string_wynik,sizeof(string_wynik)) < 0) {
                perror("Error writing to FIFO - program 2");
                exit(0);
            }
            close(fd);
            exit(0);
         }
        else {
            fflush(stdout);
            printf("Jestem rodzicem prog2");
            fprintf(stderr,"Uruchamiam program 3, zapisano liczbę %s do FIFO",string_wynik);
            sleep(SLEEP_TIME);
            execl("./prog3.out", "software", NULL);
        }
}
