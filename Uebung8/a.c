#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
/*
   +
  +++
 +++++
+++++++
  +
 +++
+++++
 +
+++

*/



void musterPlus();

int main(){

    musterPlus(3);
    getchar();
}

void musterPlus(int anz){
    int plus = 1;
    int leer = 0;
    int i = 0, k = 0;
    int j = 0;
    for(j = 1; j < anz +1; j++){
        leer = anz - j;
        for(i = 0; i< leer; i++){
            printf(" ");
        }
        plus = (j + 1) * 2-1;
        for(k = 0; k< plus; k++){
            printf("+");
        }
    printf("\n");
    }   
}
    