#ifndef __FUNKCJE_POM
#define __FUNKCJE_POM

typedef int bool;

void powitanie(int numer_prog, int stars);
void run_prog_with_args(char program[], char  argument[]);
void run_prog_with_opt(char program[], char opcja[], char  argument[]);
bool is_prime(int n);
int next_prime(int n);
bool read_bit(int * n, int position);
void reverse_bits(int * n);
void print_bits(int * n);


#endif// __FUNKCJE_POM
