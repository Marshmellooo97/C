#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define N 20

void suchen();

int maxArray(int arr[], int n, int maxAb)
{
    if (n == 0)
        return INT_MIN;
    if (maxAb == n - 1)
        return arr[maxAb];
    
    int tmp = maxArray(arr, n, maxAb + 1);
    if (tmp < arr[maxAb])
        return arr[maxAb];
    return tmp;
}

unsigned fakultaetIter(unsigned n)
{
    unsigned res = 1;
    for (unsigned i=2; i<=n; i++) 
        res *= i;
    return res;
}

unsigned fakultaetRek(unsigned n)
{
    if (n <= 1)
        return 1;
    return n * fakultaetRek(n-1);
}

unsigned fibonacciIter(unsigned n) 
{
    unsigned f0 = 0, f1 = 1, res = n;
    for (int i=2; i<=n; i++) {
        res = f0 + f1;
        f0 = f1;
        f1 = res;
    }
    return res;
}

unsigned fibonacciRek(unsigned n) 
{
    if (n <= 1)
        return n;
    return fibonacciRek(n-1) + fibonacciRek(n-2);
}

unsigned sum(unsigned n) {
    if (n == 0)
        return 0;
    return n + sum(n-1);
}

int main()
{
    unsigned n, m = 12;

#if 0
    printf("Summe rekursiv:\n");
    for (n=0; n<=m; n++)
        printf("%d->%d%s", n, sum(n), n==m?"":", ");
    
    printf("\nFakultät iterativ:\n");
    for (n=0; n<=m; n++)
        printf("%d!=%d%s", n, fakultaetIter(n), n==m?"":", ");

    printf("\nFakultät rekursiv:\n");
    for (n=0; n<=m; n++)
        printf("%d!=%d%s", n, fakultaetRek(n), n==m?"":", ");

    printf("\nFibonacci iterativ:\n");
    for (n=0; n<=m; n++)
        printf("f_%d=%d%s", n, fibonacciIter(n), n==m?"":", ");

    printf("\nFibonacci rekursiv:\n");
    for (n=0; n<=m; n++)
        printf("f_%d=%d%s", n, fibonacciRek(n), n==m?"\n":", ");
#endif

    //suchen();
    int arr[] = {17, -2, 13, 18, 9, 8, 0, 3, 5, 12};
    printf("Max Array: %d\n", maxArray(arr, 10, 0));
}


// helper func for number comparison
int compare(const void *p, const void *q) 
{
   int arg1 = *(const int*)p, arg2 = *(const int*)q;
   return (arg1 < arg2) ? -1 : ((arg1 > arg2) ? 1 : 0);
}


int binarySearchIter(int arr[], int n, int elem)
{
    int links = 0, rechts = n - 1;

    while (links <= rechts)
    {
        int mitte = (links + rechts) / 2;

        if (arr[mitte] == elem)
            return mitte;
        
        if (elem < arr[mitte])
            rechts = mitte - 1;
        else
            links = mitte + 1;
    }

    return -1;
}

int binarySearchRek(int arr[], int left, int right, int elem)
{
    if (left > right)
        return -1;
    
    int mid = (left + right) / 2;
    
    if (arr[mid] == elem)
        return mid;
    
    if (elem < arr[mid])
        return binarySearchRek(arr, left, mid - 1, elem);
    else
        return binarySearchRek(arr, mid + 1, right, elem);
}

void suchen()
{
    // fill array with random values
    srand(time(NULL));

    int feld[N], wert, index;

    for (int i=0; i<N; i++) {
        feld[i] = rand() % 200 - 100;
    }

    qsort(feld, N, sizeof(int), compare);

    printf("\n");
    for (int i=0; i<N; i++) {
        printf("%3d%c%c", feld[i], i<N-1?',':' ', i&&!((i+1)%10)?'\n':' ');
    }

    printf("\nWelche Zahl suchst du? ");
    scanf("%d", &wert);

    //index = binarySearchIter(feld, N, wert);
    index = binarySearchRek(feld, 0, N-1, wert);

    if (index < 0)
        printf("Zahl nicht gefunden\n");
    else
        printf("Zahl steht an Position %d\n", index);
}