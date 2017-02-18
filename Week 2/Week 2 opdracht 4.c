/* --------------------------- */
//  Laurens van der Sluis
//  1703647
//  Huib Aldewereld
//  Week 2 opdracht 4
/* --------------------------- */

#include <stdio.h>

int main(int argc, char **argv){    
    typedef struct {
        int nummer;
        char naam[20];
        double gewicht, lengte;
    } voorwerp;
    
    voorwerp object;
    
    printf("Nummer: ");
    while(!scanf(" %d", &object.nummer)){
        printf("Ongeldige invoer.\n");
        while(getchar() != '\n');
        printf("Nummer: ");
    }
    printf("Naam: ");
    scanf(" %s", object.naam);
    printf("Gewicht: ");
    while(!scanf(" %lf", &object.gewicht)){
        printf("Ongeldige invoer.\n");
        while(getchar() != '\n');
        printf("Gewicht: ");
    }
    printf("Lengte: ");
    while(!scanf(" %lf", &object.lengte)){
        printf("Ongeldige invoer.\n");
        while(getchar() != '\n');
        printf("Lengte: ");
    }
    printf("%s heeft nummer %d, weegt %f en is %f cm.\n", object.naam, object.nummer, object.gewicht, object.lengte);
    return 0;
}
