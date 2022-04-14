#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <limits.h>



int maxRek(int arr[], int n, int max){
    int x = 0;
    if (max >= n -1) return arr[max];
    x = maxRek(arr, n, max +1);
    if (x > arr[max]){
        return x;
    }return arr[max];
}

int test(int zahl){
    if (zahl == 1) return zahl;
    return zahl * test(zahl -1);
}

int jasZaehlen(char str[])
{
    int anz = 0;
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == 'j' && str[i +1] == 'a'){
            anz = anz +1;
        }
    }return anz;
}


int main(){
    int arr[7] = {7,3,6,78,2,4,5};
    printf("maxRek: %d\n",maxRek(arr,7,0));
    printf("Multy: %d\n",test(6));
    printf("ja %d\n", jasZaehlen("jaja"));
    getchar();
}

