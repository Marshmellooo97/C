#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

struct NurStruct{
    int zahl;
    int zahl2;
};

struct ObenStruct{
    int zahl;
    int zahl2;
}obenStruct, test;

typedef struct TypStruct{
    int zahl;
    int zahl2;
}typStruct;


int main(){
    struct NurStruct testNur;
    testNur.zahl = 1;

    struct ObenStruct testOben;
    testOben.zahl = 1;
    
    obenStruct.zahl = 1;
    test.zahl = 1;
    // Typedef

    typStruct testTyp;
    testTyp.zahl = 1;
    getchar();
}