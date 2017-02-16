/**
*	file   : DP_stairs.cpp
*	date   : 02.15 ~ 02.16.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : BackJoon_2579
**

#include <iostream>

using namespace std;
#define MAX 301

int x[MAX];
int s[MAX][3];

int getMax(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
// s[i] = max(s[i-1],s[i-2])+x[i]
//위의 식은 계단이 연속3번 올 수 있기 때문에 사용불가.
//해답에 영향을 미치는 상수 c가 있다.
//따라서 2차원 배열로 조건을 추가 해 준다.

//s[i][c] = i번째 계단, 이전 단계에서 c계단 올라옴.

//Case1   -> s[i][1] = s[i - 1][2] + x[i];
//           이전단계에서 1계단 올라온 것은 무조건 그 전에 2계단 올라왔던 것 임.
//Case2   -> s[i][2] = getMax(s[i - 2][1], s[i - 2][2]) + x[i];
//           이전단계에서 2계단 올라온 것은 그 전 단계에서 1계단 혹은 2계단 올라온 것 임.

int stairs(int n) {
	s[1][1] = x[1];
	s[1][2] = x[1];
	for (int i = 2; i <= n; i++) {
		s[i][1] = s[i - 1][2] + x[i];
		s[i][2] = getMax(s[i - 2][1], s[i - 2][2]) + x[i];
	}
	return getMax(s[n][1], s[n][2]);
}

int main(void) {
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> x[i];
	}
	cout << stairs(n);
}
