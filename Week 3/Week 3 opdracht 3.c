/// @file
/// \mainpage Author Information
/// \section Information
/// 
///     Name:          Week 3 Opdracht 3
///     Author:        Laurens van der Sluis
///     Studentnumber: 1703647
///     Docent:        Huib Aldewereld
///     Date:          26-2-2017
///
/// \section doxygen How it works?
///
/// De code laat zien of een rij alleen nullen en enen bevat.
/// Of het aantal nullen gelijk is aan het aantal enen.
/// En of een getal niet drie keer achter elkaar voorkomt.
/// Als een rij hier overal aan voldoet, dan zal het een true weergeven.

#include <stdio.h>
#include <stdbool.h>

#define length 10

/*! \brief Count
 *         
 * Een lijst wordt opgegeven de lengte ervan en het te scannen nummer.
 * 
 * Daarna wordt te lijst doorlopen met het ingevoerde nummer en zal het de counter ophogen bij het juiste nummer.
 * De totale counter zal terugegeven worden.
 */

int count(int a[], int size, int n){
    int counter = 0;
    for (int i = 0; i < size; i++){
        if (a[i] == n) counter++;
    }
    return counter;
}

/*! \brief valid_row
 *         
 * Een rij wordt opgegeven de lengte ervan.
 * 
 * Daarna wordt de rij doorlopen en wordt het volgende gecontroleerd:
 * • De rij bevat alleen nullen en enen
 * • Het aantal enen is gelijk aan het aantal nullen
 * • In de rij komt een getal niet drie keer achter elkaar voor
 * Als een rij hier overal aan voldoet, dan zal er een true terugegeven worden.
 * Op het moment dat een rij ergens niet aan voldoet zal het meteen een false terugsturen.
 * De rij zal niet meer verder worden gecontroleerd op eisen.
 */

bool valid_row(int a[], int size){
    for (int i = 0; i < size; i++){
        if ((a[i] != 0) && (a[i] != 1)) return false;
        if (i < (size - 2)){
            if ((a[i] == a[i + 1]) && (a[i] == a[i + 2])) return false;
        }
    }
    if ((count(a, length, 0)) != (count(a, length, 1))) return false;
    return true;
}

/*! \brief Main
 *         
 * We maken een lijst aan en sturen het naar de valid_row functie.
 * Het resultaat wordt weergegeven.
 */

int main(void){
    int a[length] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    printf("%s\n", valid_row(a, length)?"True":"False");
    return 0;
}