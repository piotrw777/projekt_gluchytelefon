#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>  //dla getopt
#include <sys/types.h> // dla mkfifo
#include <sys/stat.h>  // dla mkfifo
#include <getopt.h>
#include "funkcje_pom.h"

/***************
****program2****
***************/

int parseCmdOption(int argc, char *argv[]) {
    int param;
    int number = 0;
    while ((param = getopt(argc, argv, "ho:")) != -1) {
        switch (param) {
            case 'o':
                number = atoi(optarg);
                return number;
                break;
            case 'h':
                printf("POMON PROGRAMU 2");
                break;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    //char *out_path = "./prog2out.txt";
    //FILE *plik_out;
    //plik_out = fopen(out_path,"w");
    //fprintf(plik_out,"hej, tu program 2\n");
    
    char *fifo_path = "/tmp/myfifo";
    int liczba = parseCmdOption(argc, argv);
	int wynik = next_prime(liczba);
    char string_wynik[10];
    sprintf(string_wynik,"%d",wynik);
 
 	powitanie(2,20);

    printf("Otrzymana liczba: %d\n", liczba);
    //fprintf(plik_out,"\nOtrzymana liczba: %d\n", liczba);
    printf("Liczba po modyfikacji: %d (następna liczba pierwsza)\n",wynik);
    //fprintf(plik_out, "Liczba po modyfikacji: %d (następna liczba pierwsza)\n",wynik);
    
  	//zapis do FIFO
	int fd;
    
  
    
    unlink(fifo_path);
	mkfifo(fifo_path,0666);
    printf("Tuż przed mkfifoopen (prog2)\n");
    fd = open(fifo_path,O_WRONLY);
    //fprintf(plik_out, "\nCONTROL LINEv4\n");
    //fclose(plik_out);
    if (write(fd, string_wynik,sizeof(string_wynik)) < 0) {
                perror("Error writing to FIFO - program 2");
                exit(0);
     }

    close(fd);
    printf("Uruchamiam program 3, zapisano liczbę %s do FIFO",string_wynik);
    execl("./prog3.out","software", NULL);
}
