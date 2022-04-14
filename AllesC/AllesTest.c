#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

//summeArray();

int main (){
    printf("Test\n");
    
    // Variablen 
    int ia = 6;
    int ib = 10;
    char ca = 'a';
    char sa[40] = "Hallo";
    float pi = 3.1415926f, eps = 1E-6f;
    /*
    printf("Float: %f Float mit zwei nachkomma:%.2f  Float anders: %g\n", pi, pi, eps);
    float fa = ia / ib; // Es wird erst ia / ib gerechnet dann in ein Floatwert umgewandelt... Ist schlecht
    float fa = (float)ia / ib;  // Ist besser kommt eine kommazahl raus
    */
    // Ausgabe
    printf("Int: %d Char: %c String: %s\n", ia, ca, sa);
    // IF 
    if (ia == 6 && ca == 'a'){
        ia = 6;
    }else if (sa == "Hallo"){
        ia = 6;}
    // Kurz If 
    int iIfa = 7, iIfb = 8;
    int ix = (ia > ib)? iIfa : iIfb ;
    printf("IF Kurz:%d\n",ix);
    // Switch 
    switch (ia){
        case 6: ia = 6; ia = 7; printf("Case 6:%d\n",ia); break;
        case 7: ia = 6; break;    
        default: ia = 6; break;}
    // For 
    for (int count = 1; count <= 8; count++){
        printf("For: %d\n", count); 
        if (count == 3){
            break;}}
    // While 
    int count = 0;
    while (count < 8){
        printf("While: %d\n", count);
        if (count == 3){
            break;}
        count++;}
    printf("Test");
    // Do While
    count = 0;
    do{
        printf("Do While: %d\n", count);
        //count++; geht auch
    } while (++count < 2);
    printf("Test\n");
#if 0
    // Datei Öffnen
    char c = ' ';
    FILE *fp = NULL;
    fp = fopen("werte.txt", "r");
    if (fp != NULL){
        fscanf(fp, "%c", &c);
        printf("%c", c);
    }else{
        printf("Datei nicht gefunden\n");
    }
    fclose(fp);
#endif

    const int N = 10;
    // Array
    int arr[N];
    int feld [N];
    for (int i = 0; i< N;i++){
        arr[i] = rand() % 10 +1;
        feld[i] = arr[i];
        printf("Feld %d mit dem Inhalt: %d\n",i, feld[i]);
    }
    bool gleich = true;
    for (int j = 0; j < N && gleich; j++){
        if (feld[j] != arr[j]){
            gleich = false;
            //break;
        }
    }
    printf("Felder sind %s\n", gleich ? "Gleich":"Ungleich");
    /*
    int summeArray(int values[], int numValues){
        for (int i = 0;i < numValues; i++){
            int erg = values[i] + erg;
        }
        return erg;}
    */
    // Aufruf Funktion Array
    int summe = summeArray(feld, N);
    printf("Summe = %d\n", summe);

printf("Test\n");
getchar();
}

int summeArray(int values[], int numValues){
    int erg = 0;
    for (int i = 0;i < numValues; i++){
        erg = values[i] + erg;
    }
    return erg;}
