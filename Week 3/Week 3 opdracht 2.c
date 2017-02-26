/// @file
/// \mainpage Author Information
/// \section Information
/// 
///     Name:          Week 3 Opdracht 2
///     Author:        Laurens van der Sluis
///     Studentnumber: 1703647
///     Docent:        Huib Aldewereld
///     Date:          26-2-2017
///
/// \section doxygen How it works?
///
/// De code laat zien of twee rijen gelijk of ongelijk zijn aan elkaar.


#include <stdio.h>
#include <stdbool.h>

#define length 10

/*! \brief equal_rows
 *         
 * Een lijst wordt opgegeven, de lengte ervan, en het te scannen nummer.
 * 
 * Deze functie zal lijst a1 doorlopen en zijn waardes vergelijken met lijst a2.
 * Als ze niet gelijk zijn dan geeft hij false terug. Komt hij hier zonder fouten doorheen, dan geeft hij true terug.
 */

bool equal_rows(int a1[], int a2[], int size){
    for (int i = 0; i < size; i++)
        if (a1[i] != a2[i]) return false;
        return true;
}

/*! \brief main
 *         
 * Hier worden twee rijen aangemaakt en de functie equal_rows wordt met deze rijen aangeroepen.
 */

int main(void){
    int a1[length] = {0, 2, 2, 2, 5, 5, 8, 8, 8, 8};
    int a2[length] = {0, 2, 2, 2, 5, 5, 8, 8, 8, 8};
    
    printf("%s\n", equal_rows(a1, a2, length)?"De rijen zijn gelijk aan elkaar.":"De rijen zijn ongelijk aan elkaar.");
    return 0;
}