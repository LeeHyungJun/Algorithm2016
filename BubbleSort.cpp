/*
* @author Hyungjun Lee
*/

//Bubble Sorting

#include "stdio.h"

#define MAX 1000

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int arr[], int len){
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

int main() {
	int n;
	int arr[MAX];
	//input
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", arr+i);
	}
	//sort
	bubbleSort(arr, n);
	
	//output
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}