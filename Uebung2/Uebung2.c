#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int ia = 0;

int main (){
    char c = 'a';
    int d = 0;
    FILE *fp = NULL;
    fp = fopen("C:\\HSFuldaGitHub\\Prog1\\Uebung2\\werte.txt", "r");
    int erg = 0;
    if (fp != NULL){
        while (!feof(fp)){
            fscanf(fp, "%c", &c);
            printf("Zeichen:%c\n", c);
            d = (int)c;
            if (d< 57 && d > 48){
                printf("Zahl: %d\n", d -48 );
                erg = d -48 + erg;
            }
            
            
        }
    printf("Das ist das Erg: %d\n", erg);
    }else{
        printf("Datei nicht gefunden\n");
    }
    fclose(fp);


    getchar();
    getchar();

    return 0;
}