#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int bitPos(int i, int n){
    int x = 0;
    if (n < 0 || n > 31) return -1;
    else return (i >> n) % 2;
}
int alternierendeQuersumme(unsigned n)
{
    
}

int main(){
    int n=5, m=4;
    n += m;
    n /= m;
    printf("erg    %d" ,n);
    getchar();
}


