#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct {
    float x, y, z;
} Vector;


unsigned schafsOhren(unsigned anzSchafe)
{
    if (anzSchafe == 1)
        return 2;
    return 2 + schafsOhren(anzSchafe - 1);
}
void insertAfterChar(char str[], char c, char newChar){
    char one = ' ';
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == c){
            one = str[i + 1];
            str[i +1] == c;
            str[i + 2] = one;
        }
        
    }
}


float skalarprodukt(const Vector *a, const Vector *b)
{
    float erg = 0;

}

int main(){
    printf("%d\n", schafsOhren(40));
    char str[] = "Always happy coding!";
    printf("%c\n", str[5]);
    char s[20] = "Osten";
    insertAfterChar(s, 'e', 'r');
    printf("%s\n", s);

    getchar();
}