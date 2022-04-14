#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


void showBit(char bit[]){
    int one = strlen(bit)%4;
    int last = 0;
    printf("one: %d\n",one);
    for(int i = 0; i< one; i++){
        if(i == one){
            printf("%c", bit[i]);
        }else{printf("%c",bit[i]);}
    }
    for(int i = one; i < strlen(bit); i++){
        if(last%4 == 0){
            printf(" ");
            printf("%c",bit[one]);
        }else{printf("%c",bit[i]);}
        last = last +1;
    }
}

int bitPos(int i, int n){
    int x = 0;
    if (n < 0 || n > 31) return -1;
    else return (i >> n) % 2;
}


int gleich(char one[],char two[]){
    char gleichOne;
    int gleichAnzahl = 0, max = 0;
    for(int i = 0; i < strlen(one); i++){
        gleichOne = one[i];
        for(int j = 0; j < strlen(two); j++){
            if(gleichOne == two[j]){
                gleichAnzahl = 1;
                for(int beide = 1; i + beide < strlen(one) || j + beide < strlen(two); beide++){
                    if(two[j + beide] == one[i + beide]){
                        gleichAnzahl = gleichAnzahl +1;
                        if(gleichAnzahl > max)
                            max = gleichAnzahl;
                    }
                }
            }
        }
    }return max;
}

int main(){
    char bit[] = "101101000111000";
    char one[] = "Hundd";
    char two[] = "unda";
    showBit(bit);
    printf("\n");
    printf("gleich %d", gleich(one,two));
    int i = 333, n = 8;
    printf("%d", bitPos(i,n));
    getchar();
}