#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
#define MAX 301

int sol[MAX];
int m[MAX];

void _print() {
	for (int i = 0; i < MAX; i++)
		cout << m[i] << " ";
}

void _init() {
	for (int i = 0; i < MAX; i++) {
		sol[i] = -10001;
		m[i] = -1;
	}
}

int stairs(int n) {
	int conti_cnt = 0;
	for (int i = 0; i <= n; i++) {
		if (i == 0)
			sol[0] = 0;
		else {
			int bf = sol[i - 1];
			int bbf = sol[i - 2];

			if (conti_cnt == 2) {
				sol[i] = bbf + m[i];
				conti_cnt = 1;
			}
			else if (bf >= bbf) {
				sol[i] = bf + m[i];
				conti_cnt++;
			}
			else {
				sol[i] = bbf + m[i];
				conti_cnt = 1;
			}
		}
	}
	return sol[4];
}


int main() {
	int n;
	int _n;
	cin >> n;
	_n = n;
	int cnt = 0;
	_init();
	m[0] = 0;
	while (n-->0) {
		scanf("%d", &m[++cnt]);
	}
	cout << stairs(_n);
	//_print();
	
}
