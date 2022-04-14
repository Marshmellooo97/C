#include <stdlib.h>
#include <stdio.h>


void printChar(char c){
    printf("%c", c);
}

struct person{
    int alter;
    char name[60];
    int arr[];
};

void ohneArr(struct person p, int n){
    scanf("%s", p.name);
    p.alter = n;
    p.arr[n] = n;
    printf("%d   %s    %d\n", p.alter, p.name, p.arr[n]);
}
void mitArr(struct person p[], int n, int *testOne, int *testTwo){
    scanf("%d",p[n].alter);
    scanf("%s",p[n].name);
    *testOne = * testTwo = 5;
    printf("%d   %s \n", p[n].alter, p[n].name);
}
int main(){
    int a = 0, b = 0;
    printChar('D');
    struct person p;
    struct person pp[10];
    ohneArr(p,1);
    mitArr(pp,2,&a,&b);
    printf("%d\n%d\n",a,b);
    printf("%d   %s \n", pp[2].alter, pp[2].name);
    scanf("%s", p.name);
    getchar();
}


