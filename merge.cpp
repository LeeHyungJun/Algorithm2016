/*
* @author Hyungjun Lee
*/

// Merge Sorting
// Divide and Conquer.

#include "stdio.h"
#define MAX 1000000

int arr[MAX];
int result[MAX];

// The same way with Polynomial Addition 
void merge(int arr[], int first, int mid, int last) {

	int i	= first;
	int j	= mid;
	int k	= mid + 1;
	int l	= last;
	int idx	= first;

	while (i <= mid && k <= last) {
		if (arr[i] <= arr[k])
			result[idx++] = arr[i++];
		else
			result[idx++] = arr[k++];
	}
	// Add the remaining number of sorted array
	while (i <= mid) {
		result[idx++] = arr[i++];
	}
	while (k <= last) {
		result[idx++] = arr[k++];
	}
	// Adjust
	for (; first < last + 1; first++)
		arr[first] = result[first];
}
// Recursive
int mergeSort(int arr[], int first, int last) {
	if (first == last)
		return 0;
	else {
		int mid = (first + last) / 2;
		// Divide and Conquer
		mergeSort(arr, first, mid);
		mergeSort(arr, mid + 1, last);
		// Combine(Merge)
		merge(arr, first, mid, last);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	mergeSort(arr, 0, n - 1);
	
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}



//   <내가 틀렸던 것 정리>.
//   1. for문사용하면, 한 루프가 끝나고나서 idx가 증감이 되기때문에, 한 루프가 끝나기 전에
//      break걸리면 idx가 증가가 안된다.
//
//   2. 반복문의 조건, 증감이 중요한 요인이라면 for 보다 while을 쓰는게 편하겠다 ..
