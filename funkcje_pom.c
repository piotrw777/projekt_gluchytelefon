#include "funkcje_pom.h"

char * opis[] = {NULL, "(mod 10)", "(następna liczba pierwsza)", "(ustawienie bitu)", "(odbicie bitów)", "(suma cyfr)", "(razy 2)"};

void powitanie(int numer_prog, int stars) {
	int k;
	printf("\n\n");
	for(k = 0; k < stars; k++) {
		printf("*");
	}
	printf("\nWitam w programie %d!\n", numer_prog);
	for(k = 0; k < stars; k++) {
		printf("*");
	}
	printf("\n\n");
}
void komunikat(int numer, unsigned int liczba, unsigned int wynik) {
     printf("Podałeś liczbę %u\n",liczba);
     printf("Liczba po modyfikacji: %u %s\n", wynik, opis[numer]);
}
void run_prog_with_args(char program[], char  argument[]) {
	char string_wywolania[50]="./";
	char * wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, program);
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, " ");
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, argument);
	system(string_wywolania);
}
void run_prog_with_opt(char program[], char opcja[], char  argument[]) {
	char string_wywolania[50]="./";
	char * wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, program);
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, " -");
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, opcja);
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, " ");
	wsk_pom = string_wywolania + strlen(string_wywolania);
	strcpy(wsk_pom, argument);
	system(string_wywolania);
}
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
                printf("POMOC PROGRAMU 2");
                break;
        }
    }
    return -1;
}
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
int receive_by_localhost(char * NR_PORTU) {
    int liczba;
    int sockfd, numbytes;
	char buf[128];
	struct addrinfo hints, *servinfo, *p;
	int rv;
	char s[INET6_ADDRSTRLEN];

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((rv = getaddrinfo("localhost", NR_PORTU, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("client: socket");
			continue;
		}

		if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			perror("client: connect");
			close(sockfd);
			continue;
		}
		break;
	}

	if (p == NULL) {
		fprintf(stderr, "client: failed to connect\n");
		return 2;
	}

	inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
			s, sizeof s);
	//printf("client: connecting to %s\n", s);

	freeaddrinfo(servinfo); // all done with this structure

	if ((numbytes = recv(sockfd, buf, 128, 0)) == -1) {
	    perror("recv");
	    exit(1);
	}

    liczba = atoi(buf);
    return liczba;
	close(sockfd);
}
void send_by_localhost(const int number, int program, char * NR_PORTU) {

    char string_wynik[32];
    memset(string_wynik,0,32);
    sprintf(string_wynik, "%d", number);

    int gniazdo, gniazdo2;
	struct sockaddr_in adres;
	struct sockaddr_in adres_zew;
	socklen_t addrlen;
	int yes = 1;

	if((gniazdo = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Blad gniazda");
		exit(1);
	}

	adres.sin_family = AF_INET;
	adres.sin_port = htons(atoi(NR_PORTU));
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
    if( program == 6 ) {
        printf("\nSerwer dziala.\nAby odebrać komunikat, uruchom drugą konsolę i wykonaj polecenie: ");
        printf("telnet localhost %s\n", NR_PORTU);
    }

	addrlen = sizeof(struct sockaddr_in);
    gniazdo2 = accept(gniazdo, (struct sockaddr *)&adres_zew, &addrlen);
	printf("Polaczenie klienta z adresu %s\n", inet_ntoa(adres_zew.sin_addr));

	if(gniazdo2 == -1) {
		perror("Blad accept");
		close(gniazdo);
		exit(1);
	}

	if(program == 6) {
        char komunikat[1024] = "\nWiadomość od serwera programu nr 6: ";
        strcat(komunikat, string_wynik);
        strcat(komunikat, "\n***********\n");
        if (send(gniazdo2, komunikat, sizeof(komunikat), 0) == -1) {
            perror("Błąd send");
            close(gniazdo2);
            return;
       }
	}
    else{
        if (send(gniazdo2, string_wynik, sizeof(string_wynik), 0) == -1) {
            perror("Błąd send");
            close(gniazdo2);
            return;
       }
    }
	close(gniazdo);
}

