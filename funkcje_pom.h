#ifndef __FUNKCJE_POM
#define __FUNKCJE_POM

#define PORT_A "6000"
#define PORT_B "7000"
#define MAXDATASIZE 100
#define SLEEP_TIME 2
#define fifo_path "/tmp/myfifo"

#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <math.h>
#include <memory.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

typedef int bool;

char * opis[7];
void powitanie(int numer_prog, int stars);
void komunikat(int numer, unsigned int liczba, unsigned int wynik);
void run_prog_with_args(char program[], char  argument[]);
void run_prog_with_opt(char program[], char opcja[], char  argument[]);
bool is_prime(int n);
int next_prime(int n);
bool read_bit(unsigned int * n, int position);
void reverse_bits(unsigned int * n);
void print_bits(unsigned int * n);
int parseCmdOption(int argc, char *argv[]);
int suma_cyfr(unsigned int n);
void *get_in_addr(struct sockaddr *sa);
int receive_by_localhost(char * NR_PORTU);
void send_by_localhost(const int number, int program, char * NR_PORTU);

#endif// __FUNKCJE_POM
