#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define size 4

int length();
int palindrom();

int main(){
    char name[100] = "Just\n";
    //scanf("%s",name);
    //printf("Hallo %s",name);
    //scanf("%s",name);
    printf("Name ist: %s\n", name);
    printf("%d\n", palindrom(name));
    printf("-------------------\n");
    //printf("%c\n", name[2]);
    printf("Name Laenge:%d\n", length(name));
    printf("-------------------\n");
    char arrchar[size];
    int j = 1, iIdx = 0;
    

    printf("Dreieck:\n%s",arrchar);
    printf("_______________\n");
    char test[] = {'x','\n', 'X','x','\n','x','x','x'};
    printf("Zweites Dreick\n%s\n",test);
    getchar();
}
int length(char hallo[]){
    int i = 0;
    while(hallo[i] != '\0'){
        i++;}
   return i -1;
}
void dreieck(int zeilen){
    char arr[size];
    int j = 1;
    for(int i = 1; i<zeilen; i++){
        for(j = 1; j<i;j++){
            arr[j] = 'X';
        }arr[j] = '\n';
    }
}
int palindrom(char str[]){
    int i = 0, j = 0, b = 0;
    while (str[i] != '\0'){
        i++;
    }
    i -= 2;
    for(j = 0; j < i;j++){
        if(str[j] == str[i-j]){
            b = 1;
        }else{return 0;}
    }return b;
}
