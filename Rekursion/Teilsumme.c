
#include <stdio.h>
#include <stdbool.h>

// Nach Beendigung in lut für jede Position markiert, ob Wert zur Menge gehört
bool groupSum(int arr[], bool lut[], int n, int target, int index) {
	if (index == n)
		return target == 0;
	
	lut[index] = true;
	bool found = groupSum(arr, lut, n, target-arr[index], index+1);
	
	if (!found) {
		lut[index] = false;
		found = groupSum(arr, lut, n, target, index+1);
	}
	
	return found;
}
bool teile(int arr[], int length, int pos, int p1, int p2)
{
    if (pos == length)
        return p1 == p2;
    return teile(arr, length, pos+1, p1 + arr[pos], p2) || 
           teile(arr, length, pos+1, p1, p2 + arr[pos]); 
}

int main(void) {
    //int array[] = {1};
    //int array[] = {2, 4, 8};
	int array[] = {17, -2, 13, 18, 9, 8, 0};
	//int array[] = {-4, -2, 1, 3, 5, 9, 12};
	int i, val, n = sizeof(array) / sizeof(int);
	bool ret, table[n];
	
	for (i=0; i<n; i++)
		table[i] = false;
	//val = 1;
	val = 20;
	//val = 18;
	//val = 10;  //9
	
	ret = groupSum(array, table, n, val, 0);
	
	if (ret) {
		printf("%d ist Summe aus ", val);
    	for (i=0; i<n; i++)
            if (table[i])
            	printf("%d ", array[i]);
        printf("\n");
    }
    else {
    	printf("Nicht loesbar fuer %d\n", val);
    }
    getchar();
}