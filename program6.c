#include "funkcje_pom.h"

/***************
****program6****
***************/

int main() {

    powitanie(6,20);

    int liczba = receive_by_localhost(PORT_A);
    int wynik = 2 * liczba ;

    printf("Otrzymana liczba: %d\n", liczba);
    printf("Liczba po modyfikacji: %d (pomnożenie przez 2)\n", wynik);
    send_by_localhost(wynik, 6, PORT_B);
}


