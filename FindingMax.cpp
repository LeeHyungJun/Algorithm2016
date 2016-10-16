/*
* @author Hyungjun Lee
*/

// Divide and Conquer.
// Finding Max value using "std::vector".

#include "stdio.h"
#include "stdlib.h"
#include <vector>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
//Recursive
int findMax(std::vector<int>& v, int first, int last) {
	
	if (first == last)
		return v.at(first);
	else {
		int mid = (first + last) / 2;
		//Divide and Conquer, combine
		return MAX(findMax(v, first, mid), findMax(v, mid + 1, last));
	}
}

int main() {
	int num;
	int first=0, last=0;
	int d;
	std::vector<int> v;

	scanf("%d", &num);
	
	for (int i = 0; i < num; i++) {
		scanf("%d",&d);
		v.push_back(d);
	}
	printf("%d", findMax(v, 0, num-1));

	return 0;
}