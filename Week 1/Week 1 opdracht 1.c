/* --------------------------- */
//  Laurens van der Sluis
//  1703647
//  Huib Aldewereld
//  Week 1 opdracht 1
/* --------------------------- */

#include <stdio.h>

int main(){
    int x;
    int y;

    printf("Voer een getal voor x in ");
    while(!scanf("%d", &x)){
        printf("Ongeldige invoer\n");
        while(getchar() != '\n');
        printf("Voer een getal in ");
    }
    printf("Voer een getal voor y in ");
    while(!scanf("%d", &y)){
        printf("Ongeldige invoer\n");
        while(getchar() != '\n');
        printf("Voer een getal in ");
    }
    printf("%d\n", x+y);
    return 0;
}
