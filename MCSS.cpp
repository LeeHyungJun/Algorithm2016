#include<iostream>
#include<cstring>
#include<string>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int mcss(vector<int>& arr,int first, int end) {
	int leftMax;
	int rightMax;
	int centerMax;

	if (first == end) {
		return arr[first];
	}

	int mid = (first + end) / 2;
	leftMax = mcss(arr, first, mid);
	rightMax = mcss(arr, mid+1, end);
							
	 

}

int main(void) {
	int n;
	int tmp;
	int sum=0;
	vector<int> arr;
	cin >> n;
	while (n-- > 0) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	mcss(arr,0,arr.size()-1);
}
