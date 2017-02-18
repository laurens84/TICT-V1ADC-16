/* --------------------------- */
//  Laurens van der Sluis
//  1703647
//  Huib Aldewereld
//  Week 1 opdracht 4
/* --------------------------- */

#include <stdio.h>

int main(){
    int n;
    printf("Voer een getal in tussen 0 en 100: ");
    while(!scanf("%d", &n) || !(0<n && n<100)){
        printf("Ongeldige invoer\n");
        while(getchar() != '\n');
        printf("Voer een getal in: ");
        }
        for (int i=1; i!=11; i++){
            printf("%*d * %*d = %*d\n", 2, i, 2, n, 3, i*n);
        }
    return 0;
}
