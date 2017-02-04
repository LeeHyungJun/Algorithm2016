#include <iostream>
#include <vector>
using namespace std;


void getArrThePrimeNum(int n, vector<bool>& v) {
	for (int i = 2; i*i < n + 1; i++) {
		if (v[i] == true) {
			for (int j = i*i; j < n + 1; j = j + i) {
				v[j] = false;
			}
		}
	}
}
void printPrimeNumArr(int n, vector<bool>& v) {
	for (int i = 0; i < n+1; i++) {
		if (v[i] == true)
			printf("%d ", i);
	}
	cout << endl;
}

void isGoldBach(int n, vector<bool>& v) {
	for (int i = 3; i < v.size(); i++) {
		if()
		if (v[i] + v[i + 1] > n)
			continue;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] + v[j] == n) {
				cout << n << " = " << v[i] << " + " << v[j] << endl;
				return;
			}
		}
	}
	cout << "no";
}

int main(void) {
	int n;
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		vector<bool> v(n+1,true);
		getArrThePrimeNum(n,v);
		printPrimeNumArr(n,v);
		isGoldBach(n,v);
		v.clear();
	}
 }
