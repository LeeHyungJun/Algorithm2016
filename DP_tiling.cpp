/**
*	file   : DP_tiling.cpp
*	date   : 02.16.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : BackJoon 11726
**/

#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 1001

int s[MAX];

int tiling(int n) {
	s[1] = 1;
	s[2] = 2;
	for (int i = 3; i <= n; i++) {
		//계산할 때마다 나머지로 나누어 준다. 그래야 오버플로우가 생기지않는다.
		s[i] = (s[i - 1] + s[i - 2]) % 10007;
	}
	return s[n];
	//s[n]에서 n이 100정도 되면 오버플로우가 난다.
	//return s[n] % 10007;
}

int main(void) {
	int n;
	cin >> n;
	printf("%d", tiling(n));
}
