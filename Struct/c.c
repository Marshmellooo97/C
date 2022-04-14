#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


char Passwort[] = "test";


int main(){
    char eingabe[80];
    int i = 0;
    

    do{
        printf("Passwort eingeben\n");
        scanf("%s", &eingabe);
        i++;
        if(i > 2){
            printf("Zu oft Falsch eingeben");
            break;}
    }while((strcmp(eingabe, Passwort) != 0)?printf("Falsches Passwort\n"):printf("Richtiges Passwort\n"));

    getchar();
}