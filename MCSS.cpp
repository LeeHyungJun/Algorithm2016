/**
*	file   : MCSS.cpp		//Max.Conti.Subseq.Sum
*	date   : 02.09.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : BackJoon_1912
**/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int centerMcss(vector<int>& arr, int first, int mid, int end) {
	int l = 0;
	int r = 0;
	int lmax = arr[mid];
	int rmax = arr[mid + 1];

	for (int i = mid; i >= first; i--) {
		l = l + arr[i];
		if (l > lmax)
			lmax = l;
	}

	for (int i = mid + 1; i <= end; i++) {
		r = r + arr[i];
		if (r > rmax)
			rmax = r;
	}

	return lmax + rmax;

}

int mcss(vector<int>& arr,int first, int end) {
	int leftMax;
	int rightMax;
	int centerMax;

	if (first == end)
		return arr[first];

	int mid = (first + end) / 2;
	leftMax = mcss(arr, first, mid);
	rightMax = mcss(arr, mid+1, end);
	centerMax = centerMcss(arr, first, mid, end);

	//Compare
	if (centerMax > leftMax) {
		if (centerMax >= rightMax)
			return centerMax;
		else
			return rightMax;
	}
	else {
		if (leftMax >= rightMax)
			return leftMax;
		else
			return rightMax;
	}
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
	cout << mcss(arr,0,arr.size()-1);
}
