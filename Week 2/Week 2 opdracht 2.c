/* --------------------------- */
//  Laurens van der Sluis
//  1703647
//  Huib Aldewereld
//  Week 2 opdracht 2
/* --------------------------- */

#include <stdio.h>

#define size 82

int main(int argc, char **argv)
{
    int index = 0;
    char string1[size] = {};
    char string2[size] = {};
    
    printf("Enter the first string: ");
    fgets(string1, size, stdin);
    printf("appels %d", string1[81]);
    if ((string1[80] != 10) && (string1[80] != 0)){
        printf("Warning! The string you gave is longer than 80 characters. Cutting off string!");
        string1[80] = 10;
        while (getchar() != '\n');
    }
    printf("Enter the second string: ");
    fgets(string2, size, stdin);
    if ((string2[80] != 10) && (string2[80] != 0)){
        printf("Warning! The string you gave is longer than 80 characters! Cutting off string!");
        string2[80] = 10;
        while (getchar() != 10);
    }
    while ((string1[index] == string2[index]) && (index < size)){
        index++;
        if (index >= size) printf("Those strings are exactly the same.");
    }
    if (index < size){
        printf("Those two strings start to differ at character number %d.\n", (index + 1));
        printf("String 1: %s", string1);
        printf("String 2: %s%*c\n", string2, (index + 11), '^');
    }
    return 0;
}
