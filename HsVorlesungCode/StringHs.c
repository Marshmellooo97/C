#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Funktionsprototypen
void showMat(int rows, int cols, int m[][cols]);

// Hauptprogramm
int main(void)
{
    #if 0
    int feldNeu[MAX_SIZE] = {0};
    int anz = 0;

    printf("Wieviel Werte du eingeben wollen? ");
    scanf("%d", &anz);

    if (anz > MAX_SIZE)
        anz = MAX_SIZE;
    //int feldGanzNeu[anz];

    for (int k=0; k<anz; k++) {
        printf("Gib feldNeu[%d]: ", k);
        scanf("%d", &feldNeu[k]);
    }
    #endif
#if 1
    const int NUM_ROWS = 3, NUM_COLS = 3;
    int matrix[NUM_ROWS][NUM_COLS];
    
    for (int k=0, i=0; i<NUM_ROWS; i++) {
        for (int j=0; j<NUM_COLS; j++) {
            matrix[i][j] = k++;
        }
    }
    
    showMat(NUM_ROWS, NUM_COLS, matrix);

    /*
    int a = 17, b = 4, tmp;
    tmp = a;
    a = b;
    b = tmp;
    printf("a=%d, b=%d\n", a, b);
    */
    
    for (int i=0; i<NUM_ROWS; i++) {
        for (int j=i+1; j<NUM_COLS; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    
    showMat(NUM_ROWS, NUM_COLS, matrix);
#endif
    

    char str[] = "Hello World";
    //char str[] = {'H','e','l','l','o',' ','W','o','r','l','d','\0'};

    printf("%s\n", str);
    printf("Stringlänge: %lu\n", strlen(str));

    str[0] = 'H';
    str[1] = 'i';
    printf("%s\n", str);
    printf("Stringlänge: %lu\n", strlen(str));

    str[2] = '\0';
    printf("%s\n", str);
    printf("Stringlänge: %lu\n", strlen(str));


    int tag, jahr;
    char monat[20];
    
    // Kein &, Feldname ist schon Adresse
    //scanf("%d %s %d", &tag, monat, &jahr);
    //printf("%d %s %d\n", tag, monat, jahr);

    
    //str = "Hallo!";  // Fehler!    
    char msg[10] = "Bonjour";
    msg[0] = 'H';
    msg[1] = 'i';
    msg[2] = '\0';
    
    for (int i=0; i<10; i++) {
        printf("msg[%d]=%c\n", i, msg[i]?msg[i]:'_');
    }
    printf("%s\n", msg);
    printf("%s\n", &msg[3]);

    /*
    char s[20], t[20] = "foo bar";
    int i = 0;
    while ((s[i] = t[i])) 
        i++;
    printf("\n%s\n", s);
    */

    char str1[80], str2[80];
    fgets(str2, 80, stdin);
    int slen = strlen(str2);
    str2[--slen] = '\0';

    printf("#%s#\n", str2);

    //strcpy(str1, str2);
    //sprintf(str1, "%s", str2);
    //sprintf(str1, "%d%c %s %d", 12, '.', "Januar", 2022);
    int w;
    char string[] = "Januar";
    //sscanf(string, "%d %s", &w, str1);
    //printf("%d*%s*\n", w, str1);

    if (!strcmp(str2, string)) {
        printf("Eingabe richtig\n");
    }
    

    // create substring of string of length len starting at pos
    int len = 3, pos = 1, c = 0;
    char sub[len+1];
    
    while (c < len) {
        sub[c++] = string[pos++];
    }
    sub[c] = '\0';

    printf("\n#%s#\n", sub);
}


void showMat(int rows, int cols, int m[][cols])
{
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
