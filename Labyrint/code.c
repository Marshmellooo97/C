#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DBG_VIS 1
#ifdef WIN32
  const char clear_str[] = "cls";
#else
  const char clear_str[] = "clear";
#endif

#define MAXROWS  20
#define MAXCOLS  20
#define WEG      '0'
#define MAUER    '1'
#define MARKIERT 'x'

// ADT Labyrinth
typedef char Labyrinth[MAXROWS][MAXCOLS];

// Funktionsprototypen
bool readMaze(Labyrinth l, char filename[], int *rows, int *cols);
void search  (Labyrinth l, bool *done, int x, int y, int zx, int zy);
void showMaze(Labyrinth l, int rows, int cols);

//-------------------------------------------------------------------
int main(int argc, char* argv[])
{
    Labyrinth laby;
    int currRows, currCols;        // Tatsaechliche Groesse
    bool geschafft = false;
    char file[80] = "C:/HsFuldaAi/HSFulda1/Prog1/Labyrint/lab5.txt";    // Testlabyrinth
    
    if (argc > 1)
        strcpy(file, argv[1]);
    
    if ( !readMaze(laby, file, &currRows, &currCols) ) {
        printf("Error reading %s\n", file);
        return -1;
    }
    
#ifndef DBG_VIS
    printf("Dim: %d x %d\n\n", currRows, currCols);
    
    showMaze(laby, currRows, currCols);
#else
    system(clear_str);
#endif
    
    search(laby, &geschafft, 0, 0, currCols-1, currRows-1);
    
    showMaze(laby, currRows, currCols);
    
    printf("Ziel %sgefunden\n", geschafft ? "" : "nicht ");
    
    return 0;
}

//-------------------------------------------------------------------
bool readMaze(Labyrinth l, char filename[], int *rows, int *cols)
{
    int i = 0, j = 0, k, cnt = 0, c;
    FILE *fp = fopen(filename, "r");
    
    if (!fp || fscanf(fp, "%d %d", rows, cols) < 2) {
        fclose(fp);
        return false;
    }
    
    if (*rows > MAXROWS)
        *rows = MAXROWS;
    if (*cols > MAXCOLS)
        *cols = MAXCOLS;
    
    k = *rows * *cols;
    
    while (!feof(fp)) {
        if (fscanf(fp, "%d", &c) && ++cnt <= k) {
            l[i][j] = c ? MAUER : WEG;
            
            if ( !(j = (j+1) % *cols) )
                i++;
        }
    }
    
    fclose(fp);
    
    return cnt >= k;
}

//-------------------------------------------------------------------
void showMaze(Labyrinth l, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%c ", l[i][j]);
        printf("\n");
    }
    printf("\n");
}

//-------------------------------------------------------------------
void search(Labyrinth l, bool *done, int x, int y, int zx, int zy)
{
#ifdef DBG_VIS
    showMaze(l, zy + 1, zx + 1);
    getchar();
    system(clear_str);
#endif
    
    l[y][x] = MARKIERT;
    
    if (x == zx && y == zy) {
        *done = true;
    }
    else {  // Weg suchen
        if (!*done && y + 1 <= zy && l[y + 1][x] == WEG)
            search(l, done, x, y + 1, zx, zy);
        if (!*done && x + 1 <= zx && l[y][x + 1] == WEG)
            search(l, done, x + 1, y, zx, zy);
        if (!*done && y - 1 >=  0 && l[y - 1][x] == WEG)
            search(l, done, x, y - 1, zx, zy);
        if (!*done && x - 1 >=  0 && l[y][x - 1] == WEG)
            search(l, done, x - 1, y, zx, zy);
        if (!*done)
            l[y][x] = WEG;
    }
}