/* --------------------------- */
//  Laurens van der Sluis
//  1703647
//  Huib Aldewereld
//  Week 1 opdracht 3
/* --------------------------- */

#include <stdio.h>

int main(){
    int n;
    printf("Voer een getal in tussen 1 en 80: ");
        while(!scanf("%d", &n) || !(0<n && n<81)){
        printf("Ongeldige invoer\n");
        while(getchar() != '\n');
        printf("Voer een getal in.\n");
        }
    for (int i=0; i<n; i++){
        for (int a=0; a<=i; a++){
            printf("*");
        }
        printf("\n");
    }
    int i = n-1;
    while (i!=0) {
        int a = i;
        while (a!=0) {
            printf("*");
            a--;
        }
            printf("\n");
            i--;
    }
    return 0;
}