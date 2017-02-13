/**
*	file   : DP_fibonacci.cpp
*	date   : 02.13.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : BackJoon 1003
**/

#include <iostream>

using namespace std;
#define MAX 41

int front[MAX];
int _end[MAX];

void _init() {
	for (int i = 0; i <= 40; i++) {
		front[i] = -1;
		_end[i] = -1;
	}
}

void fibonacci(int n) {
	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			front[0] = 1;
			_end[0] = 0;
		}
		else if (i == 1) {
			front[1] = 0;
			_end[1] = 1;
		}
		else {
			front[i] = front[i - 1] + front[i - 2];
			_end[i] = _end[i - 1] + _end[i - 2];
		}
	}
}

int main() {
	int T;
	cin >> T;

	while (T-->0) {
		int n;
		cin >> n;
		_init();
		fibonacci(n);
		cout << front[n] << " " << _end[n] << endl;
	}
	
}
