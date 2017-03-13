/// \mainpage Author Information
/// \section Information
/// 
///     Name:          Week 4 Opdracht 2
///     Author:        Laurens van der Sluis
///     Studentnumber: 1703647
///     Docent:        Huib Aldewereld
///     Date:          13-3-2017
///
/// \section doxygen How it works?
///
/// De code zal een bestand openen en de inhoud in een matrix plaatsen.

#include <stdio.h>

/*! \brief read_matrix
 *         
 * Een bestand wordt geopend en de inhoud wordt in een twee-dimensionale array geplaatst.
 * 
 */

int read_matrix(const char *filename, int size, int matrix[][size]){
    FILE *fp1;
    
    fp1 = fopen(filename, "r");
    if (fp1 == NULL) {
        printf("Cannot open %s for reading\n", filename);
        return(1);
    }
    else {
        for (int x = 0; x < size; x++){
            for (int y = 0; y < size; y++){
                matrix[x][y] = getc(fp1);
            }
        }
    }
    fclose(fp1);
    return (0);
}

/*! \brief Main
 *         
 * Eerst wordt het bestand geopend om te kijken hoe groot de array moet worden.
 * Zodra dit bepaald is zal de functie "read_matrix" aangeroepen worden.
 * 
 */

int main(int argc, char **argv){
    FILE *fp1;
    int ch1, size = 0;
    
    fp1 = fopen("binary_sudoku_puzzle.txt", "r");
    
    if (fp1 == NULL) {
        printf("Cannot open binary_sudoku_puzzle.txt for reading\n");
        return(1);
    }
    else {
        ch1 = getc(fp1);
        while ((ch1 != EOF) && (ch1 != '\n')){
            ch1 = getc(fp1);
            size++;
        }
        fclose(fp1);
        int matrix[size][size];
        read_matrix("binary_sudoku_puzzle.txt", size, matrix);
    }
    return 0;
}