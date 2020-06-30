#include "funkcje_pom.h"
#include <sys/wait.h>

/***************
****program4****
***************/

void odbierz4(unsigned int  * liczba);
void wyslij4(const char * text);
void modyfikuj4(unsigned int liczba, unsigned int * wynik, char * string );
bool read_bit(unsigned int * n, int position);
void reverse_bits(unsigned int * n);
void print_bits(unsigned int * n);

static char buffer[128];

int main(void) {
    //deklaracje
    unsigned int liczba;
	unsigned int wynik;
	char string_wynik[10];

    powitanie(4,20);

    //wczytujemy liczbę
    odbierz4(&liczba);
	//modyfikacja liczby
    modyfikuj4(liczba, &wynik, string_wynik);

	komunikat(4, liczba, wynik);
    printf("Liczba wejściowa w postaci binarnej:\n");
    print_bits(&liczba);
    printf("Liczba wyjściowa w postaci binarnej:\n");
    print_bits(&wynik);
    wyslij4(string_wynik);

	return 0;
}

void odbierz4(unsigned int  * liczba) {
    int fd;
    fd = open(chardev_path, O_RDONLY);
    if (fd < 0) {
        perror("Błąd otwarcia urządzenia CHARDEV");
        exit(0);
    }
    if ( read(fd, buffer, sizeof(buffer) < 0) ){
        perror("Błąd czytania z  chardev");
        exit(0);
    }
    close(fd);
    *liczba = atoi(buffer);
}
void wyslij4(const char * text) {
    int fd[2];
    char pipe_fd_str[32];
    char  wiadomosc[32];
    strcpy(wiadomosc, text);
    
    pipe(fd);
    pid_t pid = fork();
    
    if(pid == -1) {
        perror("fork error");
        exit(-1);
    }
    else if (pid == 0) {
        //jestem dzieckiem
        close(fd[0]);
        sleep(SLEEP_TIME);
        printf("Zapisuję wiadomość %s do pipe\n", wiadomosc);
        if( write( fd[1],wiadomosc, sizeof(wiadomosc) ) == -1 ) {
            perror("error in write");
        }
        close(fd[1]);
    }
    else {
        //jestem rodzicem
        close(fd[1]);
        sprintf(pipe_fd_str, "%d", fd[0]);
        //dup2(fd[0], STDIN_FILENO);
        printf("Uruchamiam program 5 z argumentem %s\n", text);
        execl("executables/prog5.out","prog5.out",pipe_fd_str, NULL);
    }
}
bool read_bit(unsigned int * n, int position) {
	return !!(*n & (1 << position));
}

void reverse_bits(unsigned int * n) {
	int k;
	for(k = 0; k < 16; k++) {
		if( read_bit(n, k) != read_bit(n, 31- k)  ) {
			*n ^= (1 << k);
			*n ^= (1 << (31 - k));
		}
	}
}
void print_bits(unsigned int * n) {
	int k;
	for(k = 31; k >= 0; k--) {
		printf("%d", read_bit(n, k));
		if(k % 4 == 0) {
			printf(" ");
		}
	}
	printf("\n");
}
void modyfikuj4(unsigned int liczba, unsigned int * wynik, char * string ) {
    *wynik = liczba;
    reverse_bits(wynik);
    memset(string, 0, 10);
    sprintf(string, "%u", *wynik);
}
