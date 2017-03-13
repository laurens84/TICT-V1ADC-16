/// \mainpage Author Information
/// \section Information
/// 
///     Name:          Week 4 Opdracht 5
///     Author:        Laurens van der Sluis
///     Studentnumber: 1703647
///     Docent:        Huib Aldewereld
///     Date:          13-3-2017
///
/// \section doxygen How it works?
///
/// De functie plaatst alle gevonden woorden uit de ASCII-file in een array.
/// Een woord is opgebouwd uit alphanumerieke karakters. Het is niet bekend hoe lang de woorden kunnen zijn. 
/// Het bestand bevat maximaal 1000 woorden.

#include <stdio.h>
#include <ctype.h>

/*! \brief getWords
 *         
 * Er wordt een bestand geopend. Dit bestand wordt doorlopen en alphanumerieke waarden worden gedetecteerd en toegevoegd aan de char array "a".
 * Zodra het volgende ingelezen character geen alphanumerieke waarde bevat zal er een nieuw woord begonnen worden.
 * 
 */

int getWords(char* filename, int word_size, char a[][word_size]){
    FILE *srcf;
    int ch1, new_word = 1, word_count = 0, char_count = 0;
    srcf = fopen(filename, "r");
    if (srcf == NULL) printf("Cannot open %s for reading\n", filename);
    else{
        ch1 = getc(srcf);
        while (ch1 != EOF){
            if (isalnum(ch1)){
                new_word = 0;
                a[word_count][char_count] = ch1;
                char_count++;
            }
            else if (!new_word) {
                new_word = 1;
                char_count = 0;
                word_count++;
            }
            ch1 = getc(srcf);
        }
        fclose(srcf);
    }
    return(word_count);
}

/*! \brief Main
 *         
 * Eerst wordt het bestand geopend om te kijken hoelang het langste woord is.
 * Als er een alphanumerieke waarde gedetecteerd wordt dan zal de counter verhoogt worden.
 * Zodra de waarde in counter grooter is dan de waarde in word_size, zal de waarde in word_size ook verhoogt worden.
 * Als het hele bestand gelezen is en de EOF is bereikt, zal de char array aangemaakt worden.
 * Dan zal de functie getWords aangeroepen worden. Als deze functie doorlopen is zal de array geprint worden.
 * 
 */

int main(void) {
    FILE *srcf;
    int ch1, counter = 0, word_size = 0;
    srcf = fopen("main.c", "r");
    if (srcf == NULL) printf("Cannot open main.c for reading\n");
    else{
        ch1 = getc(srcf);
        while (ch1 != EOF){
            if (isalnum(ch1)){
                counter++;
                if (counter > word_size) word_size = counter;
            }
            else counter = 0;
            ch1 = getc(srcf);
        }
        fclose(srcf);
    }
    char a[1000][word_size];
    int n = getWords("main.c", word_size, a);
    if (n > 0){
        puts("gevonden woorden:");
        for (int i = 0;i < n; i++){
            printf("%3d %s\n",i,a[i]);
        }
    }
    return 0;
}