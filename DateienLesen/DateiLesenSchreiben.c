#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>







int liesNummer(char liste[], char name[])
{
    FILE *fp = NULL;
    fp = fopen("C:/HsFuldaAi/HSFulda1/Prog1/DateienLesen/text.txt", "r");
    if (fp != NULL){



    }
}

int main(){
#if 1
    // Datei Lesen
    char c = ' ';
    int erg = 0, x;
    FILE *fp = NULL;
    fp = fopen("C:/HsFuldaAi/HSFulda1/Prog1/DateienLesen/text.txt", "r");
    if (fp != NULL){
        while(!feof(fp)){
            fscanf(fp, "%c", &c);
            if (c == 'Name')
            //erg = x + erg;
                printf("%c", c);
        }
        //printf("Alle Zahlen ergeben: %d", erg);
        fclose(fp);
    }else{
        printf("Datei nicht gefunden\n");
    }
    
#endif






#if 0
    // Datei schreriben 
    char c = 'z';
    FILE *fp = NULL;
    fp = fopen("C:/HsFuldaAi/HSFulda1/Prog1/DateienLesen/text.txt", "w");
    if (fp != NULL){
        fprintf(fp, "%s", "Hallo was geht");
    }else{
        printf("Datei nicht gefunden\n");
    }
    fclose(fp);
#endif

#if 0
    // Datei anhängen 
    char c = 'z';
    FILE *fp = NULL;
    fp = fopen("C:/HsFuldaAi/HSFulda1/Prog1/DateienLesen/text.txt", "a");
    if (fp != NULL){
        fprintf(fp, "%s", "Hallo was geht\n");
    }else{
        printf("Datei nicht gefunden\n");
    }
    fclose(fp);
#endif
    getchar();
}




