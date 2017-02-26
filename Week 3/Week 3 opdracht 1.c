/// @file
/// \mainpage Author Information
/// \section Information
/// 
///     Name:          Week 3 Opdracht 1
///     Author:        Laurens van der Sluis
///     Studentnumber: 1703647
///     Docent:        Huib Aldewereld
///     Date:          26-2-2017
///
/// \section doxygen How it works?
///
/// De code laat zien hoe vaak een geheel getal in een rij voorkomt.

#include <stdio.h>

#define length 10

/*! \brief Count
 *         
 * Een lijst wordt opgegeven de lengte ervan en het te scannen nummer.
 * 
 * Daarna wordt de lijst doorlopen met het ingevoerde nummer en zal het de counter ophogen bij het juiste nummer.
 * De totale counter zal terugegeven worden.
 */

int count(int a[], int size, int n){
    int counter = 0;
    for (int i = 0; i < size; i++){
        if (a[i] == n) counter++;
    }
    return counter;
}

/*! \brief Main
 *         
 * We maken een lijst aan en vragen de gebruiken om een nummer in te voeren.
 * 
 * Het ingevoerde nummer wordt ingelezen. Daarna wordt functie count opgeroepen.
 * 
 */

int main(void){
    int a[length] = {0, 2, 2, 2, 5, 5, 8, 8, 8, 8};
    int number = 0;
    printf("Enter a number");
    scanf("%d", &number);
    printf("%d\n", count(a, length, number));
    return 0;
}
