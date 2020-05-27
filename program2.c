#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcje_pom.h"

/***************
****program2****
***************/

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
	if(n == 1) return 2;
	if(n == 2) return 3;
	
	int k = n + 1 + n%2;
	
	while(is_prime(k) == 0) k++;
	
	return k;
}
int main(int argc, char* argv[]) {

	int liczba = atoi(argv[1]);
	printf("**********\nWitam w programie2!\n************\n");
	printf("Argument, wywołania to: %s\n",argv[1]);
	printf("Zwiększam argument o dwa: %d\n", liczba + 2);
	

}

/*
#include <stdio.h>  
#include <unistd.h>  

int main(int argc, char *argv[])  
{ 
    int opt; 
      

    while((opt = getopt(argc, argv, “:if:lrx”)) != -1)  
    {  
        switch(opt)  
        {  
            case ‘i’:  
            case ‘l’:  
            case ‘r’:  
                printf(“option: %c\n”, opt);  
                break;  
            case ‘f’:  
                printf(“filename: %s\n”, optarg);  
                break;  
            case ‘:’:  
                printf(“option needs a value\n”);  
                break;  
            case ‘?’:  
                printf(“unknown option: %c\n”, optopt); 
                break;  
        }  
    }  
      
    // optind is for the extra arguments 
    // which are not parsed 
    for(; optind < argc; optind++){      
        printf(“extra arguments: %s\n”, argv[optind]);  
    } 
      
    return 0; 
} 
*/
