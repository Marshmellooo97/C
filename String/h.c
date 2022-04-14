#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

void testChar();
void teststr();
void testint();

//void testint();


int main() {
    int i = 0;
    char chtest = 'C';
    char name[100] = "Justin\n";
    testint(5);
    teststr(name);
    testChar('s');

    getchar();

}

void testChar(char *c) {
    printf("_____%c\n", c);
}

void testint(int i) {
    printf("_____%d\n", i);
}
void teststr(char str[]) {
    printf("_____%s\n", str);
}
#if 1


#endif
#if 0

void test(char str[], char c) {
    int i = 0;
    while (str[i] != c) {
        i++;
    }
    i -= 2;
    printf("%d\n", i);
    printf("%s\n", str);
}
#endif