#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


int suchRek(int arr[], int elem, int left, int right) {
	if (left > right) {return -1;}
	int mid = (right + left) / 2;
	if (arr[mid] == elem) { return mid; }
	if (arr[mid] < elem) {
		return suchRek(arr, elem, mid + 1, right);
	}else {
		return suchRek(arr, elem, left, mid - 1);
	}
}
int maxArr(int arr[], int len, int maxAb) {
	if (maxAb == len - 1) {
		return arr[maxAb];
	}
	int x = maxArr(arr, len, maxAb + 1);
	if (x < arr[maxAb]) {
		return arr[maxAb];
	}return x;
}
bool nestParenthesis(char str[], int firstChar, int	lastChar) {
	int zu = 0, auf = 0;
	if (firstChar == lastChar) {
		return str[firstChar];
	}
	char elem = nestParenthesis(str, firstChar + 1, lastChar);
	if (elem == ')'|| str[firstChar] == ')') {
		zu = zu + 1;
	}
	else if (elem == '(' || str[firstChar] == '(') {
		auf = auf + 1;
	}
	if (auf == zu) {
		return true;
	}else return false;
}
#if 1
int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	char str[] = "(()";
	int num = suchRek(arr, 4, 0, 8);
	printf("Index: %d\n", num);
	printf("maxArr: %d\n", maxArr(arr,9,0));
	printf("nestParenthesis: %i", nestParenthesis(str, 0, 5));
    getchar();
}
#endif