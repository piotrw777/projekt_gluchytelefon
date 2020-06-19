#include "funkcje_pom.h"

/***************
****program3****
***************/

void odbierz3(unsigned int * liczba);
void modyfikuj3(unsigned int liczba, unsigned int * wynik, char * string );

int main(int argc, char* argv[]) {
    //deklaracje
	unsigned int liczba;
	unsigned int wynik;
	char string_wynik[10];
	int fd;

	powitanie(3,20);

    //wczytujemy liczbę
	odbierz3(&liczba);

	//modyfikacja liczby
    modyfikuj3(liczba, &wynik, string_wynik);

	komunikat(3, liczba, wynik);

	//wywołanie programu 4

	printf("Uruchamiam program 4 z argumentem %d\n", wynik);

    fd = open(chardev_path, O_WRONLY);
    if(fd < 0) {
        perror("Failed to open the device CHRDEV");
        exit(0);
    }
    if( write(fd, string_wynik, sizeof(string_wynik)) < 0 ) {
        perror("Couldn't write to CHRDEV");
        exit(0);
    }
    close(fd);
	sleep(SLEEP_TIME);
	//run_prog_with_args("executables/prog4.out","");
	execl("./executables/prog4.out", "software", NULL);
}
void odbierz3(unsigned int * liczba) {
    char buf[10];
	int fd;
	fd = open(fifo_path, O_RDONLY);
	if (read(fd, buf,sizeof(buf)) < 0) {
		perror("Błąd czytania z FIFO - program 3");
		exit(0);
	}
	close(fd);
	unlink(fifo_path);
	*liczba = atoi(buf);
}

void modyfikuj3(unsigned int liczba, unsigned int * wynik, char * string ) {
     *wynik = 1 << liczba;
     memset(string, 0, 10);
     sprintf(string, "%u", *wynik);
}
