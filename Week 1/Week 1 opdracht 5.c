/* --------------------------- */
//  Laurens van der Sluis
//  1703647
//  Huib Aldewereld
//  Week 1 opdracht 5
/* --------------------------- */

#include <stdio.h>

int main(){
    int i;
    int value = 0;
    int charcount = 0;
    int factor = 1;
    printf("Give a number ");
    while((i = getchar()) != '\n'){
        charcount++;
        if (i == 43 && charcount == 1) continue;
        else if (i == 45 && charcount == 1) {
            factor = -1;
            continue;
        }
        else if (i>=48 && i<=57) {
            value = 10 * value + (i - 48);
            continue;
        }
        else if (((i == 43) || (i == 45)) && (charcount > 1)) printf("'%c' only allowed as first character!\n", i);
        else printf("Invalid input!\n");
        factor = 1;
        while (getchar() != '\n');
        charcount = 0;
        value = 0;
        printf("Give a number ");
    }
    printf("%d\n", value * factor);
    return 0;
}