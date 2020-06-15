#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "funkcje_pom.h"
#define PORT_A  6000

/***************
****program6****
***************/

int main(int argc, char *argv[])
{
	int liczba = atoi(argv[1]);
	int wynik = 2 * liczba ;
	char string_wynik[10];
	char komunikat[1024] = "\nWiadomość od serwera programu nr 6: ";
	memset(string_wynik,0,10);
	sprintf(string_wynik, "%d", wynik);
	strcat(komunikat, string_wynik);
	strcat(komunikat, "\n***********\n");

	int gniazdo, gniazdo2;
	struct sockaddr_in adres;
	struct sockaddr_in adres_zew;
	int nbytes;
	socklen_t addrlen;
	int yes = 1;

	powitanie(6,20);
	printf("Otrzymana liczba: %d\n", liczba);

	if((gniazdo = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Blad gniazda");
		exit(1);
	}

	adres.sin_family = AF_INET;
	adres.sin_port = htons(PORT_A);
	adres.sin_addr.s_addr=INADDR_ANY;
	memset(&(adres.sin_zero),0,8);

	setsockopt(gniazdo, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

	if(bind(gniazdo,(struct sockaddr*)&adres, sizeof(adres)) == -1) {
		perror("Błąd bind");
		close(gniazdo);
		exit(1);
	}

	if( listen(gniazdo, 10) == -1){
		perror("Błąd listen");
		close(gniazdo);
		exit(1);
	}

	printf("Serwer dziala. Aby odebrać komunikat uruchom drugą konsolę i wykonaj polecenie:\n");
	printf("telnet localhost %d\n", PORT_A);

	addrlen = sizeof(struct sockaddr_in);
	gniazdo2 = accept(gniazdo, (struct sockaddr *)&adres_zew, &addrlen);

	printf("Polaczenie klienta z adresu %s\n", inet_ntoa(adres_zew.sin_addr));

	if(gniazdo2 == -1) {
		perror("Blad accept");
		close(gniazdo);
		exit(1);
	}

    pid_t pid;
    pid = fork();
	if(pid == 0) {
        close(gniazdo);
        if (send(gniazdo2, komunikat, sizeof(komunikat), 0) == -1) {
            perror("Błąd send");
       		close(gniazdo);
            close(gniazdo2);
            exit(1);
        }
	}
	close(gniazdo2);

	return 0;
}
