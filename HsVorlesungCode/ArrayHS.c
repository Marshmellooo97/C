#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define COLS 4

int sumOfArray(int values[], int numValues)
{
    printf("&values   : %p\n values   : %p\n", &values, values);
    
    int sum = 0;
    for (int i=0; i<numValues; i++) {
        sum += values[i];
    }
    
    return sum;
}

void showMat(int m[][COLS], int rows)
{
    for (int i=0; i<rows; i++) {
        for (int j=0; j<COLS; j++) {
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
    
    const int N = 10;
    // Deklaration eines Feldes der Länge N
    int feld[N];
    // Initialisierung aller Feldwerte mit 0
    for (int i=0; i<N; i++) {
        feld[i] = i + 1;
    }
    // some code ...
    // Zugriff auf 5. Element (Startindex 0)
    for (int i=0; i<N; i++) {
        printf("feld[%d] ist %d\n", i, feld[i]);
    }
    
    // Deklaration eines 5-elementigen Feldes
    // mit gleichzeitiger Initialisierung
    //int arr[] = {1, 2, 3, 4, 5};
    // Gleichbedeutend mit
    int arr[N];
    
    for (int i=0; i<N; i++) {
        arr[i] = rand() % 10 + 1;
        //arr[i] = feld[i];
        //printf(" arr[%d] ist %d\n", i, arr[i]);
    }
    
    printf("&arr   : %p\n arr   : %p\n", &feld, feld);
    
    //int ret = sumOfArray(arr, N);
    printf("Summe der Elems: %d\n", sumOfArray(feld, N));
    
#if 0
    bool gleich = true;
    for (int j=0; j<N /*&& gleich*/; j++) {
        if (arr[j] != feld[j]) {
            gleich = false;
            break;
        }
    }
    
    printf("Felder sind %s.\n\n", gleich ? "gleich" : "ungleich");
    
    // Adresse von Feld und erstem Element
    printf("&arr   : %p\n arr   : %p\n", &arr, arr);
    //printf("%u\n", sizeof(int));
    
    // Adresse von i-tem Element
    for (int i=0; i<N; i++)
        printf("&arr[%d]: %p\n", i, &arr[i]);
#endif
    
    
    const int NUM_ROWS = 4, NUM_COLS = 4;
    int matrix[NUM_ROWS][NUM_COLS], k = 0;
    
    for (int i=0; i<NUM_ROWS; i++) {
        for (int j=0; j<NUM_COLS; j++) {
            matrix[i][j] = k++;
        }
    }
    
    showMat(matrix, NUM_ROWS);
    
    return 0;
}