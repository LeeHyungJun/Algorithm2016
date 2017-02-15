/**
*	file   : DP_LCS.cpp
*	date   : 02.15.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : BackJoon_9251
**/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 1001

int s[MAX][MAX];

void lcs(string X, string Y) {
	//int i = X.size();
	//int j = Y.size();
	for (int r = 1; r <= X.size(); r++) {
		for (int c = 1; c <= Y.size(); c++) {
			if (X.at(r-1) == Y.at(c-1))
				s[r][c] = s[r - 1][c - 1] + 1;
			else
				s[r][c] = max(s[r - 1][c], s[r][c - 1]);
		}
	}
}

void printString(string X, string Y) {
	cout << X << endl;
	cout << Y << endl;
}

void printArr(string X, string Y) {
	for (int i = 1; i <= X.size(); i++) {
		for (int j = 1; j <= Y.size(); j++) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void) {
	string X, Y;
	getline(cin, X);
	getline(cin, Y);

	lcs(X, Y);
	//printString(X,Y);
	//printArr(X, Y);
	printf("%d", s[X.size()][Y.size()]);
}
