#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>





int main(){

    int u[3] = {1,0,0}, v[3] = {0,1,0}, w[3];
    int *ptr = (int*) malloc(2 * sizeof(int[10]));
    int *ptr1 = (int*) malloc(sizeof(int));
    
    if (ptr != NULL){
        for(int i = 0; i < 20; i++){
            ptr[i] = i;
            printf("%d = %d\n",i,ptr[i]);
        }
        free(ptr);
        free(ptr1);
        
    }

#if 0
    for( int i = 0; i < 6; i ++){
        printf("%d = %f\n",i, arr[i]);
        
    }
#endif
    getchar();
}