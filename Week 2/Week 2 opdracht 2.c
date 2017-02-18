/* --------------------------- */
//  Laurens van der Sluis
//  1703647
//  Huib Aldewereld
//  Week 2 opdracht 2
/* --------------------------- */

#include <stdio.h>

#define size 80

int main(int argc, char **argv)
{
    int index = 0;
    char string1[size] = {};
    char string2[size] = {};
    
    printf("Enter the first string: ");
    fgets(string1, size, stdin);
    printf("Enter the second string: ");
    fgets(string2, size, stdin);
    while ((string1[index] == string2[index]) && (index < size)){
        index++;
        if (index >= size) printf("Those strings are exactly the same.");
    }
    if (index < size){
        printf("Those two strings differ after the %dth character.\n", (index + 1));
        printf("String 1: %s", string1);
        printf("String 2: %s%*c\n", string2, (index + 11), '^');
    }
    return 0;
}
