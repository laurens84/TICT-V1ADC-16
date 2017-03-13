/// \mainpage Author Information
/// \section Information
/// 
///     Name:          Week 4 Opdracht 1
///     Author:        Laurens van der Sluis
///     Studentnumber: 1703647
///     Docent:        Huib Aldewereld
///     Date:          13-3-2017
///
/// \section doxygen How it works?
///
/// De code wordt aangeroepen met twee bestanden als argumenten. Deze bestanden zullen met elkaar vergeleken worden en als ze verschillen, dan zal de [positie van het eerste verschil aangegeven worden.

#include <stdio.h>

/*! \brief Main
 *         
 * Er worden twee bestanden geopend en er wordt 1 character van beide bestanden ingelezen. Deze twee characters worden dan vergeleken met elkaar.
 * Als ze gelijk zijn aan elkaar dan zal de chcount verhoogt worden met 1. Anders zal de huidige chcount worden teruggegeven.
 * 
 */

int main(int argc, char **argv){
    FILE *fp1, *fp2;
    int ch1, ch2;
    int chcount = 1;
    
    if (argc != 3) printf("Please enter two filenames as arguments.\n");
    else
    {
       fp1 = fopen(argv[1], "r");
       fp2 = fopen(argv[2], "r");

        if (fp1 == NULL) {
            printf("Cannot open %s for reading\n ", argv[1]);
            return(1);
        }
        else if (fp2 == NULL) {
            printf("Cannot open %s for reading\n ", argv[2]);
            fclose(fp1);
            return(1);
        }
        else {
            ch1 = getc(fp1);
            ch2 = getc(fp2);
            while ((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2)) {
                ch1 = getc(fp1);
                ch2 = getc(fp2);
                chcount++;
            }
            if (ch1 == ch2){
                printf("Files are identical\n");
                fclose(fp1);
                fclose(fp2);
                return (0);
            }
            else if (ch1 != ch2){
                fprintf(stderr, "Files start to differ after byte %d.\n", chcount);
                fclose(fp1);
                fclose(fp2);
                return (1);
            }
        }
    }
}