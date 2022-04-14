#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

void suchen();
int ungerade();
int lucky();
void umdrehen();
int test[] = {6,5,2,3,4,1,9};


int main(){

    suchen(test, 7);
    printf("Ungerade Zahlen: %d\n",ungerade(test, 7));
    printf("schaut ob eine 1 und 3 hintereiander steht: %d\n",lucky(test, 7));
    umdrehen(test,7);
    getchar();
}

void suchen(int arr[], int n){
    int k = 0, g = 0;
    k = arr[0];
    g = arr[0];
    for(int i = 0; i< n; i++){
        if(arr[i] < k){
            k = arr[i];
        }
        if(arr[i] > g){
            g = arr[i];
        }
    }
    int last = arr[0];
    for(int i = 0; i< n; i++){
        if(k < arr[i] && arr[i] < last){
            last = arr[i];
        }
    }
    printf("Klein:%d  kleinZwei:%d  Gross:%d\n",k, last, g);
}
int ungerade(int arr[], int n){
    int erg = 0;
    for(int i = 0; i< n; i++){
        if(arr[i] %2){
            erg = erg +1;
        }
    }return erg;
}
int lucky(int arr[], int n){
    int erg = 0;
    for(int i = 0; i< n; i++){
        if(arr[i] == 1){
            if(arr[i+1] == 3){
                erg = 1;
            }
        }
    }return erg;
}
void umdrehen(int arr[], int n){
    int arr2[7];
    for(int i = 0; i< n; i++){
        arr2[(n-1) - i] = arr[i];
    }
    for(int i = 0; i< n; i++){
        printf("%d\n",arr2[i]);
    }
}