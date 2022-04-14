#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <limits.h>

int summationsfkt(int n){
    if (n == 1){return 1;}
    return n + summationsfkt(n -1);
}
int fakutaet(int n){
    if (n == 0){return 1;}
    return n * fakutaet(n -1);
} 
int fibonacci(int n){
    if (n <= 1){return n;}
    return fibonacci(n -1) + fibonacci(n -2);
}
int fibzws(int n, int arr[]) {
    if (n < 0) return INT_MIN;
    else if (n <= 1) {
        arr[n] = n;
        return n;
    }
    else if (arr[n] == arr[n - 1] + arr[n - 2]) return arr[n];
    else {
        arr[n] = fibzws(n - 1, arr) + fibzws(n - 2, arr);
        return arr[n];
    }
}
int minimumRek(int arr[], int n, int maxAb){
    if(maxAb == n -1){
        return arr[maxAb];  
    }
    int minArr = minimumRek(arr, n, maxAb + 1);
    if (minArr < arr[maxAb]){
            return minArr;
        } 
    return arr[maxAb];
}
int minimumIter( int arr[], int n){
    int arrMin = arr[0];
    for(int i = 0; i < n; i++){
        if(arrMin > arr[i]){
            arrMin = arr[i];}
    }return arrMin;
}

int produktRek(int arr[], int n, int maxAb){
    if(maxAb == n -1){
        return arr[maxAb];
    }
    int erg = 1;
    int pro = produktRek(arr,n,maxAb +1);
    pro = arr[maxAb] * pro;
    return pro;
}
int produktIter(int arr[], int n){
    int erg = 1;
    for(int i=0;i<n;i++){erg = erg*arr[i];}return erg;}
int triangle(int rows){
    if(rows == 1){
        return 1;
    }return triangle(rows - 1) + rows;
}
int power(int b, int a){
    if(a == 1){
        return b;}
    return b * power(b, a -1);}
int	bunnyEars(int numBunnies){
    if(numBunnies == 1){
        return 2;}
    int temp = bunnyEars(numBunnies - 1);
    if (numBunnies%2 == 0){
        return temp += 3;
    }else{return temp += 2;}
}
int main(){
    int arr[5] = {3,4,2,5,2};
    printf("summe: %d\n", summationsfkt(100));
    printf("fakutaet: %d\n", fakutaet(10));
    printf("fibonacci: %d\n", fibonacci(6));
    printf("fibonacciZwischenspeichern: %d\n", fibzws(9, arr));
    printf("minimumRek: %d\n", minimumRek(arr, 5, 0));
    printf("minimumIter: %d\n", minimumIter(arr, 5));
    printf("produktRek: %d\n", produktRek(arr, 5, 0));
    printf("produktIter: %d\n", produktIter(arr, 5));
    printf("triangle: %d\n", triangle( 5));
    printf("power: %d\n", power(5,5));
    printf("bunnyEars: %d\n", bunnyEars(2));
    getchar();
}