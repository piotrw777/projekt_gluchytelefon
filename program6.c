#include "funkcje_pom.h"

/***************
****program6****
***************/

int main() {

    powitanie(6,20);

    unsigned int liczba = receive_by_localhost(PORT_A);
    unsigned int wynik = 2 * liczba ;

    komunikat(6, liczba, wynik);

    send_by_localhost(wynik, 6, PORT_B);
}


