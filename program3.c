#include "funkcje_pom.h"

/***************
****program3****
***************/

int main(int argc, char* argv[]) {

    powitanie(3,20);
	int liczba;
	int wynik;
	char string_wynik[10];

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

	liczba = atoi(buf);
	wynik = 1 << liczba;
	sprintf(string_wynik, "%d", wynik);

	printf("Otrzymana liczba: %d\n", liczba);
	printf("Liczba po modyfikacji: %d (ustawienie bitu)\n", 1 << liczba);

	//wywołanie programu 4
	printf("Uruchamiam program 4 z argumentem %d\n", wynik);
	sleep(SLEEP_TIME);
	run_prog_with_args("prog4.out",string_wynik);
	//fclose(plik_out);
}
