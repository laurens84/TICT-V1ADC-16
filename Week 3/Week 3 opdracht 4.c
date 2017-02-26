/// @file
/// \mainpage Author Information
/// \section Information
/// 
///     Name:          Week 3 Opdracht 4
///     Author:        Laurens van der Sluis
///     Studentnumber: 1703647
///     Docent:        Huib Aldewereld
///     Date:          26-2-2017
///
/// \section doxygen How it works?
///
/// De code maakt een matrix aan dat er als volgt uit ziet:
/// {1, 1, 1}
/// {2, 2, 2}
/// {3, 3, 3}
///
/// Deze matrix zal vervolgens uitgeprint worden als:
/// {1, 2, 3}
/// {1, 2, 3}
/// {1, 2, 3}

#include <stdio.h>

#define length 3

/*! \brief transpose_matrix
 *         
 * Een matrix wordt opgegeven en de lengte ervan.
 * 
 * Daarna zal de matrix doorlopen worden en een waarde tijdelijk opslaan in 'temp'.
 * Daarna worden de waardes op x en y met elkaar verwisseld en de y en x met temp.
 */

void transpose_matrix(int size, int matrix[size][size]){
    int temp;
    for (int x = 0; x < size; x++){
        for (int y = 0; y < size; y++){
            if (x > y){
                temp = matrix[x][y];
                matrix[x][y] = matrix[y][x];
                matrix[y][x] = temp;
            }
        }
    }
}

/*! \brief Main
 *         
 * We maken een matrix aan en sturen het naar de transpose_matrix functie.
 * Daarna wordt de matrix weergegeven.
 */

int main(void){
    int matrix[length][length] =   {{1, 1, 1},
                                    {2, 2, 2},
                                    {3, 3, 3}};
    
    transpose_matrix(length, matrix);
    for (int x = 0; x < length; x++){
        for (int y = 0; y < length; y++){
            printf("%d", matrix[x][y]);
        }
        putchar('\n');
    }
    return 0;
}
