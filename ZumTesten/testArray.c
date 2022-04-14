#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define sizeArray2 3

void printArray2(int len1,int len2, int arr[][sizeArray2]){
    for (int i = 0; i < len1 ; i++){
        for (int j = 0; j < len2 ; j++){
            printf("%d ", arr[i][j]);
        }printf("\n");
    }
}
void printArray1(int len, int arr[]){
    for (int i = 0; i < len ; i++){
        printf("%d ", arr[i]);
    }
}



int dice(int a, int b, int c)
{
    if (a == b || a == c || b == c)
        return a * b *c;
    else if (a == b && b == c)
        return 500;
    else return a + b + c;
}

int main(){
    int arr[] = {1, 5, 3, 2, 4, 2}, *p = arr;
p += 5;
*p = 8;
arr[0] = *arr * *p;
arr[2] += *(arr + 1);
(*--p)++;

    printArray1(6, arr);




    getchar();
}