/// @file
/// \mainpage Author Information
/// \section Information
/// 
///     Name:          Week 3 Opdracht 5
///     Author:        Laurens van der Sluis
///     Studentnumber: 1703647
///     Docent:        Huib Aldewereld
///     Date:          26-2-2017
///
/// \section doxygen How it works?
///
/// De code schuift de bits in een byte.

#include <stdio.h>

/*! \brief get_bit
 *
 * De functie bepaalt de bitwaarde van bit 'n' van byte 'ch'.
 */

int get_bit(char ch, int n){
    ch <<= n;
    return ((ch & 0x80) / 128);
}

/*! \brief get_bit
 *
 * Als n > 0 dan wordt n posities naar links geschoven. De weggevallen bits worden rechts teruggeplaatst.
 * Als n < 0 dan wordt n posities naar rechts geschoven. De weggevallen bits worden links teruggeplaatst.
 */

char verschuif_cyclisch(char ch, int n){
    for (n = n; n > 0; n--){
        int bit = get_bit(ch, 0);
        ch <<= 1;
        ch = ch | bit;
    }
    for (n = n; n < 0; n++){
        int bit = get_bit(ch, 7);
        ch >>= 1;
        if (bit) ch |= (1 << 7);
        else ch &= ~(1 << 7);
    }
    return ch;
}

/*! \brief Main
 *         
 * We doorlopen alle bits van de byte met waarde 42 en schuiven de bits -7 tot 7 plaatsen en printen het resultaat.
 * 
 */

int main(void){
    for (int j = -7; j <= 7; j++){
        printf("%2d ", j);
        int ch = 42;
        ch = verschuif_cyclisch(ch, j);
        for (int i = 0; i < 8; i++){
            printf("%d", get_bit(ch, i));
        }
        putchar('\n');
    }
    return 0;
}