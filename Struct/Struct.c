#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>



#if 0
#define anz 1000

struct kunde{
    unsigned long nummer;
    char name[100];
    short geb_jahr;
    unsigned short geschlecht;
};

int	einfuegen(struct kunde kdb[], int index){
    printf("Eingeben\nNummer:\nname:\nGebi:\ngeschlecht:\n");
    scanf("%d %s %d %d",&kdb[index].nummer, &kdb[index].name, &kdb[index].geb_jahr, &kdb[index].geschlecht );
    return index + 1;
}
void anzeigen(struct kunde kdb[], int index){
    int wahl = 0;
    printf("Ihre Wahl: %d\n", wahl);
    printf("Anzuzeigender Index: %d\n", index);
    printf("Nummer: %d \nName: %s \n",kdb[index].nummer, kdb[index].name );
    printf("Gebi: %d \nGeschlecht: %d\n", kdb[index].geb_jahr, kdb[index].geschlecht);
}

int main(){
    int a = 1, index = 0, indexAnzeigen = 0;
    struct kunde data[anz];
    while (a){
        printf("<1>	Neuen Datensatz anlegen\n<2> Vorhandenen Datensatz abrufen\n<0>	Ende\n");
        scanf("%d", &a);
        if(a == 1){
            index = einfuegen(data,index);
        }else if (a == 2){
            printf("Welchen Index anzeigen\n");
            scanf("%d", &indexAnzeigen);
            anzeigen(data,indexAnzeigen);
        }
    }
    getchar();
}
#endif
#if 1
#define anz 1000

typedef struct {
    unsigned long nummer;
    char name[100];
    short geb_jahr;
    unsigned short geschlecht;
}kunde;

int	einfuegen(kunde kdb[], int index){
    printf("Eingeben\nNummer:\nname:\nGebi:\ngeschlecht:\n");
    scanf("%d %s %d %d",&kdb[index].nummer, &kdb[index].name, &kdb[index].geb_jahr, &kdb[index].geschlecht );
    return index + 1;
}
void anzeigen(kunde kdb[], int index){
    int wahl = 0;
    printf("Ihre Wahl: %d\n", wahl);
    printf("Anzuzeigender Index: %d\n", index);
    printf("Nummer: %d \nName: %s \n",kdb[index].nummer, kdb[index].name );
    printf("Gebi: %d \nGeschlecht: %d\n", kdb[index].geb_jahr, kdb[index].geschlecht);
}

int main(){
    int a = 1, index = 0, indexAnzeigen = 0;
    kunde data[anz];
    while (a){
        printf("<1>	Neuen Datensatz anlegen\n<2> Vorhandenen Datensatz abrufen\n<0>	Ende\n");
        scanf("%d", &a);
        if(a == 1){
            index = einfuegen(data,index);
        }else if (a == 2){
            printf("Welchen Index anzeigen\n");
            scanf("%d", &indexAnzeigen);
            anzeigen(data,indexAnzeigen);
        }
    }
    getchar();
}
#endif