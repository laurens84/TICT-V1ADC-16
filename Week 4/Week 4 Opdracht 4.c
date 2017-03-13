/// \mainpage Author Information
/// \section Information
/// 
///     Name:          Week 4 Opdracht 4
///     Author:        Laurens van der Sluis
///     Studentnumber: 1703647
///     Docent:        Huib Aldewereld
///     Date:          13-3-2017
///
/// \section doxygen How it works?
///
/// De functie plaatst alle gevonden gehele getallen uit de ASCII-file in array a. 
/// Het aantal ingelezen elementen wordt teruggeven.
/// Het bestand kan naast getallen ook tekst bevatten. Het bevat maximaal 100 gehele getallen.

#include <stdio.h>

/*! \brief getIntegers
 *         
 * Er wordt een bestand geopend. Dit bestand wordt doorlopen en decimale waarden worden gedetecteerd en toegevoegd aan de integer "value".
 * Zodra het volgende ingelezen character geen decimale waarde bevat zal de inhoud van "value" worden weggeschreven in de array.
 * Zodra er een '-' gedetecteerd wordt zal de "value" met -1 vermenigvuldicht worden.
 * 
 */

int getIntegers(char* filename, int *a, int size){
    FILE *srcf;
    int ch1, factor = 1, value = 0, index = 0;
    srcf = fopen(filename, "r");
    if (srcf == NULL) printf("Cannot open %s for reading\n", filename);
    else{
        ch1 = getc(srcf);
        while (ch1 != EOF){
            if ((ch1 >= '0') && (ch1 <= '9')){
                value = (value * 10) + (ch1 - '0');
            }
            else if (ch1 == '-'){
                factor = -1;
            }
            else if (value > 0){
                a[index] = value * factor;
                value = 0;
                factor = 1;
                index++;
            }
            ch1 = getc(srcf);
        }
        if (value > 0){
            a[index] = value * factor;
            index++;
        }
        fclose(srcf);
    }
    return (index);
}

/*! \brief Main
 *         
 * Functie "getIntegers" wordt aangeroepen en daarna zal array a geprint worden.
 * 
 */

int main(void){
    int a[100];
    int n = getIntegers("getallen.txt", a, 100);

    if (n > 0) {
        puts("gevonden getallen:");
        for (int i = 0;i < n; i++){
            printf("%d ",a[i]);
        }
    }
    putchar('\n');
 return (0);
}