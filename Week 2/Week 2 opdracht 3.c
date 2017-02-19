/* --------------------------- */
//  Laurens van der Sluis
//  1703647
//  Huib Aldewereld
//  Week 2 opdracht 3
/* --------------------------- */

#include <stdio.h>
#include <string.h>

#define size 82

int main(int argc, char **argv){
    char input[size] = {};
    
    printf("Enter text to display backwards.\n");
    fgets(input, size, stdin);
    if ((input[size - 2] != 10) && (input[size - 2] != 0)){
        printf("Warning! The string you entered is more than 80 characters long! Cutting off string!\n");
        input[size - 2] = 10;
        while (getchar() != '\n');
    }
    for (int i = (strlen(input) - 1); i >= 0; i--){
        
        putchar(input[i]);
    }

    char *pinput = input + (strlen(input) - 1);
    for (int i = (strlen(input) - 1); i >= 0; i--) {
        putchar(*pinput);
        pinput--;
    }
    putchar('\n');
    return 0;
}
