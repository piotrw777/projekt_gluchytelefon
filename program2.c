#include "funkcje_pom.h"

/***************
****program2****
***************/

bool is_prime(int n);
int next_prime(int n);
void modyfikuj2(unsigned int liczba, unsigned int * wynik, char * string );

int main(int argc, char* argv[]) {
    //deklaracje
	unsigned int liczba;
	unsigned int wynik;
	char string_wynik[10];

    powitanie(2,20);

    //wczytujemy liczbę
    liczba = parseCmdOption(argc, argv);

    //modyfikacja liczby
    modyfikuj2(liczba, &wynik, string_wynik);

    komunikat(2, liczba, wynik);

  	//zapis do FIFO
	int fd;
    unlink(fifo_path);
	mkfifo(fifo_path, 0777);

    pid_t pid = fork();
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
            execl("./executables/prog3.out", "software", NULL);
        }
}

void modyfikuj2(unsigned int liczba, unsigned int * wynik, char * string ) {
     *wynik = next_prime(liczba);
     memset(string, 0, 10);
     sprintf(string, "%u", *wynik);
}

bool is_prime(int n) {
	if(n < 2) return 0;
	if(n == 2) return 1;
	//jeśli parzysta zwróć fałsz
	if(n % 2 == 0) return 0;

	int k_max = (int) sqrt(n) + 1;
	int k = 3;
	while(k < k_max) {
		if((n % k) == 0) {
			return 0;
		}
		k += 2;
	}
	return 1;
}

int next_prime(int n) {
	if(n < 2) return 2;
	if(n == 2) return 3;

	int k = n + 1 + n%2;

	while(is_prime(k) == 0) {
		k += 2;
	}
	return k;
}
