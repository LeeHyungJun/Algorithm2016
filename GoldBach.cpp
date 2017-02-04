#include <iostream>
#include <vector>
using namespace std;

class Sol {
private:
	vector<int> primeNumArr;
public:
	Sol(int n) {
		vector<int> a((n/2)+1,0);
		primeNumArr = a;
	}
	void getArrThePrimeNum(int n) {
		int tmp = n / 2;
		int cnt=0;
		for (long i = 3; i <= tmp; i++) {
			for (long j = 3; j <= tmp; j++) {
				if (tmp%j != 0)
					cnt++;
				if (cnt != 0)
					break;
				if (j == tmp)
					primeNumArr.push_back(j);
			}
		}
	}
	void printPrimeNumArr(int n) {
		int tmp = n / 2;
		for (long i = 0; i <= tmp; i++) {
			cout << primeNumArr[i] << " ";
		}
		cout << endl;
	}
};

int main(void) {
	int n;
	while (1) {
		cin >> n;
		Sol a(n);
		if (n == 0)
			break;
		else {
			a.getArrThePrimeNum(n);
			a.printPrimeNumArr(n);
		}
	}
 }
