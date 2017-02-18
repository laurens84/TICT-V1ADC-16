/* --------------------------- */
//  Laurens van der Sluis
//  1703647
//  Huib Aldewereld
//  Week 2 opdracht 1
/* --------------------------- */

#include <stdio.h>

int main(int argc, char **argv){
    int x = 0;
    int a[10] = {};
    int count0 = 0;
    int count1 = 0;
    int incount = 0;
    
    while (((x = getchar()) !='\n') || (incount < 10)){
        if (x == 48 || x == 49){
            a[incount] = (x - 48);
            incount++;
        }
    }
    for (int i = 0; i < (sizeof(a) / sizeof(int)); i++){
        if (a[i] == 0) count0++;
        else if (a[i] == 1) count1++;
    }
    if (count0 < count1) printf("There are %d zeros and %d ones. So there are more ones.", count0, count1);
    else if (count0 > count1) printf("There are %d zeros and %d ones. So there are more zeros.", count0, count1);
    else if (count0 == count1) printf("There are %d zeros and %d ones. So they are even.", count0, count1);
    return 0;
}
