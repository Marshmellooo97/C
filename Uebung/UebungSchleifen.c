#include <stdlib.h>
#include <stdio.h>


int main(){
    int a = 0, b = 0;
    printf("Zahlen eingeben\n");
    scanf("%d %d",&a, &b);
    printf("A:%d  B:%d\n",a,b);

    if (a % 10 == b % 10){
        printf("Gleich\n");
    }
    for (int count = 0; count < 1000000; count++){
        int erg = count*count*count - 73*count*count + 1655 * count - 11951; 
        if ( erg == 0){
            printf("x ist %d", count);
            break;
        }
    }

    getchar();
    getchar();
}
