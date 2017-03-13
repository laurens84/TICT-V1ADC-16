/// \mainpage Author Information
/// \section Information
/// 
///     Name:          Week 4 Opdracht 3
///     Author:        Laurens van der Sluis
///     Studentnumber: 1703647
///     Docent:        Huib Aldewereld
///     Date:          13-3-2017
///
/// \section doxygen How it works?
///
/// Deze code opent een bestand en verwijderd de spaties, tabs en eventuele lege regels.

#include <stdio.h>

/*! \brief compress
 *         
 * Een bron bestand wordt geopend en de inhoud wordt gescand.
 * Tijdens het scannen wordt een ander bestand (dat aangemaakt wordt als deze niet bestaat) gelijk gevuld.
 * Zodra er een tab (ascii 9) of een spatie (ascii 32) gedetecteerd wordt tijdens het scannen, zal deze niet overgenomen worden.
 * Als er twee keer achter elkaar een nieuwe regel gedetecteerd wordt, dan betekend het dat er een lege regel staat. Deze zal ook niet over genomen worden.
 * 
 */

void compress(char* src_filename, char* dest_filename){
    FILE *srcf, *destf;
    int prevchar = 0, ch1;
    int count = 0;
    srcf = fopen(src_filename, "r");
    destf = fopen(dest_filename, "w");
    if (srcf == NULL) {
        printf("Cannot open %s for reading\n", src_filename);
    }
    else {
        ch1 = getc(srcf);
        while (ch1 != EOF) {
            if ((ch1 == 9) || (ch1 == 32)) ch1 = getc(srcf);
            else if ((ch1 == '\n') && (prevchar == '\n')) ch1 = getc(srcf);
            else{
                putc(ch1, destf);
                count++;
                printf("%d\n", count);
            }
            prevchar = ch1;
            ch1 = getc(srcf);
        }
        fclose(srcf);
        fclose(destf);
    }
}

/*! \brief Main
 *         
 * Functie "compress" wordt aangeroepen.
 * 
 */

int main(int argc, char **argv){
    compress("Opdracht3.c","Opdracht3_compressed.c");
    return (0);
}