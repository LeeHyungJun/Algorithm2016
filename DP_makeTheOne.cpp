/**
*	file   : DP_makeTheOne.cpp
*	date   : 02.16.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : BackJoon_1463
**/

#include <iostream>
using namespace std;
#define MAX 1000001

int s[MAX];

int getMin2(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int getMin3(int a, int b, int c) {
	if (a > b) {
		if (b > c)
			return c;
		else
			return b;
	}
	else {
		if (c > a)
			return a;
		else
			return c;
	}
}

void makeTheOne_hj_draft(int n) {
	s[0] = -1;
	for (int i = 1; i <= n; i++) {
		if (i % 6 == 0)
			s[i] = getMin3(s[i / 3], s[i / 2], s[i - 1]) + 1;
		else if (i % 3 == 0)
			s[i] = getMin2(s[i / 3], s[i - 1]) + 1;
		else if (i % 2 == 0)
			s[i] = getMin2(s[i / 2], s[i - 1]) + 1;
		else
			s[i] = s[i - 1] + 1;
	}
}

//최소값 구할때, 함수호출하지말고 바로 사용하기.
void makeTheOne(int n) {
	s[0] = -1;
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + 1;
		if (i % 3 == 0 && s[i] > s[i/3]+1 )
			s[i] = s[i / 3] + 1;
		//else if 가 아닌 if인 이유?
		//6일 경우 n/2 n/3둘다 확인하고 min값을 대입해야 하기 때문.
		if (i % 2 == 0 && s[i] > s[i/2]+1 )
			s[i] = s[i / 2] + 1;
	}
}

void printArr(int n) {
	for (int i = 1; i <= n; i++)
		cout << s[i] << " ";
}

int main(void) {
	int n;
	cin >> n;
	makeTheOne(n);
	//printArr(n);
	printf("%d", s[n]);
}
