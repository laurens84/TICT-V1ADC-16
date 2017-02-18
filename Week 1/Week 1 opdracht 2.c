/* --------------------------- */
//  Laurens van der Sluis
//  1703647
//  Huib Aldewereld
//  Week 1 opdracht 2
/* --------------------------- */

#include <stdio.h>
#include <ctype.h>

int main(){
    int ch;
    printf("Voer een karakter in.\n");
    while ((ch = getchar()) != '\n'){
        if isupper(ch)
            printf("Hexadecimale waarde van %c is %#x\n", ch, ch);
        else if islower(ch)
            printf("Decimale waarde van %c is %d\n", ch, ch);
        else
            printf("Het ingevoerde teken is: %c\n", ch);
    }
    return 0;
}