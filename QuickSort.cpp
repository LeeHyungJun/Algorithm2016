/*
* @author Hyungjun Lee
*/

// Quick Sorting
// Divide and Conquer.

#include "stdio.h"

#define MAX 1000000

int arr[MAX];

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int midIdx(int a, int b, int c) {
	int max, min, mid;
	//Max
	max = (a > b) ? a : b;
	max = (max > c) ? max : c;
	//Min
	min = (a > b) ? b : a;
	min = (min > c) ? c : min;
	//Mid
	mid = a + b + c - min - max;

	if (a == mid)
		return 1;
	else if (b == mid)
		return 2;
	else
		return 3;
}

int getPivotIdx(int *arr, int first, int last) {
	int pIdx;
	int mid = midIdx(arr[first], arr[(first + last) / 2], arr[last]);
	if (mid == 1)
		pIdx = first;
	else if (mid == 2)
		pIdx = (first + last) / 2;
	else
		pIdx = last;
	return pIdx;
}

int partition(int *arr, int first, int last) {
	//get pivotIdx
	int pIdx = getPivotIdx(arr, first, last);
	
	//Put pivot at leftmost.
	swap(&arr[first], &arr[pIdx]);
	pIdx = first;

	int i = first + 1;
	int j = first;

	//Divide groups smaller than pivotValue and bigger than pivotValue in arr
	while (i <= last) {
		if (arr[pIdx] >= arr[i]) {
			swap(&arr[j + 1], &arr[i]);
			i++;
			j++;
		}
		else
			i++;
	}
	//Put pivot at center
	swap(&arr[pIdx], &arr[j]);
	pIdx = j;

	return pIdx;
}

void quickSort(int *arr, int first, int last) {
	
	//다짰는데 리쿼시브가 무한루프 빠짐..
	//원인 : 리쿼시브 함수 안에 브레이크 조건이 이상해서.

	//if (first == last)
	//	return 0;
	if(first < last) {
		int pivotIdx;
		//Divide
		pivotIdx = partition(arr, first, last);
		//Conquer
		quickSort(arr, first, pivotIdx - 1);
		quickSort(arr, pivotIdx + 1, last);
	}

	
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	quickSort(arr, 0, n - 1);
	
	
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

}