#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

//어떤 두 소수의 합이 answer을 이루는 지를 확인하기 보다는.
//answer - 어떤 소수가 소수인지를 확인하는 것이 범위를 줄여주는 방법이다.

//Eratos
void getArrThePrimeNum(int n, vector<int>& v) {
	for (int i = 2; i*i < n + 1; i++) {
		if (v[i] == 1) {
			for (int j = i*i; j < n + 1; j = j + i) {
				v[j] = 0;
			}
		}
	}
}
void changeContainer(int n, vector<int>& v, vector<int>& p) {
	for (int i = 3; i < n+1; i++) {
		if (v[i] == 1)
			p.push_back(i);
			//p[cnt++] = i;
	}
}

void print(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void isGoldBach(int n, vector<int>& p) {
	for (int i = 0; i < p.size(); i++) {
		for (int j = i + 1; j < p.size(); j++) {
			if ((n - p[i]) == p[j]) {
				printf("%d = %d + %d\n", n, p[i], p[j]);
				return;
			}
		}
		
	}
	//cout << "no";
}

int main(void) {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		vector<int> v(n+1,1);
		vector<int> p;
		getArrThePrimeNum(n,v);
		changeContainer(n,v,p);
		//print(p);
		isGoldBach(n,p);
		v.clear();
		p.clear();
	}
 }
