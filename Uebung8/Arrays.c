#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define sizeArray2 3

const int gvlSize = 3;

void printArray2();
void printArray1();
int summeArray();
void tauschArray();
int arrayKreuz();
int main (){
    int arr11[] = {1,2,3};
    int arr12[] = {1,2,3};
    int arr21[3][3] = { {1,2,3},
                        {4,5,6},
                        {7,8,9}};

    printArray2(3,3,arr21);
    printf("___________________________\n");
    tauschArray(3, arr21);
    printArray2(3,3,arr21);
    printf("___________________________\nKreutprodukt\n");
    printf("%d",arrayKreuz(3,arr11,arr12));
    printf("___________________________\nAnzeigen\n");
    printArray1(3,arr11);
    
getchar();
}
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

void tauschArray(int len, int arr[][sizeArray2]){
    //int temp = 0;
    for (int i = 0; i < len ; i++){
        for (int j = i; j < len ; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    
    //return arr;
}
void MultiplyArrayByTwo(int arr[][sizeArray2], int len)
{
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            arr[i][j] *= 2;
        }
    }
}
int summeArray(int arr[], int len){
    int erg = 0;
    for (int i = 0;i < len; i++){
        erg = arr[i] + erg;
    }
    return erg;}

int arrayKreuz( int len, int arr1[], int arr2[]){
    int erg = 0;
    for(int i = 0; i< len; i++){
        int kreuz = arr1[i] * arr2[i];
        erg = erg + kreuz;
    }return erg;
}   