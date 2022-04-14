/*
#include <stdlib.h>
#include <stdio.h>


int main(){
    printf("hallo");
}
*/


#include <stdlib.h>
#include <stdio.h>


struct Kreiszwei{
    char name;
    float radius;
};

typedef struct  {
    char name;
    float radius;

}Kreisdrei;


typedef struct {
    char name;
    float radius;

} Kreis;



// Kreis* newKreisRet(char name, float _r) {
//     Kreis* ret = malloc(sizeof(Kreis));
//     //Kreis ret;
//     ret->name = name;
//     ret->radius = _r;
//     float test = ret->radius;
//     //float* testp = ret->radius;
//     return ret;
// }

int funkAddieren(int a, int b) {
    return a + b;
}

int ergAdd;
int scan;

int main(){

    int test;
    Kreis kreis1;
    //Kreiszwei kreis2;
    Kreisdrei kreis3;
    kreis1.name = 'H';

    Kreis k1 = newKreisRet('K', 5.5);
    printf("%c\n", k1.name);
    printf("%f\n",k1.radius);
    printf("Test hat funktioniert\n");
    printf("Test2 hat funktioniert\n");

    scanf("%d", &scan);
    ergAdd = funkAddieren(7,6);
    printf("Erg: %d\n", ergAdd);
}
