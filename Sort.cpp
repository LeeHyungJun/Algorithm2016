#include <iostream>
#include <vector>
#include <algorithm>	//std::swap
using namespace std;

void print(vector<int> v) {
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
}

//Insertion Sort
//Worst = O(n^2) Best = O(n) -> already ordered array.
void insertionSort(vector<int> v) {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (v[j - 1] > v[j])
				swap(v[j - 1], v[j]);
			else
				break;
		}
	}
	print(v);
}

// Bubble Sort
// O(n^2) Worst = Best = Avg time Complexity.
void bubbleSort(vector<int> v) {
	for (int j = 0; j < v.size(); j++) {
		for (int i = 0; i < v.size() - 1 - j; i++) {
			if (v[i] > v[i + 1])
				swap(v[i], v[i + 1]);
		}
	}
	print(v);
}

// Selection Sort
// O(n^2) Worst = Best = Avg time Complexity.
void selectionSort(vector<int> v) {
	for (int j = 0; j < v.size(); j++) {
		int maxIdx = 0;
		for (int i = 0; i < v.size() - j; i++) {
			if (v[maxIdx] < v[i])
				maxIdx = i;
		}
		swap(v[maxIdx], v[v.size() - 1 - j]);
	}
	print(v);
}

int main(void) {

	vector<int> v;
	v.push_back(4);
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(1);

	selectionSort(v);
	bubbleSort(v);
	insertionSort(v);

	return 0;
}
