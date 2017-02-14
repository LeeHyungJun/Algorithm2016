/**
*	file   : DP_chainMatrix.cpp
*	date   : 02.14.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : BackJoon_11049
**/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 501

int p[MAX];
int m[MAX][MAX];
int cnt = 0;

void chainMatrix(int n) {
	int j,k;
	int c = 0 ;
	int tmp = 0;
	//Diagonal set the zero.
	for (int i = 1; i <= n; i++)
		m[i][i] = 0;
	//Bottom-up
	//r개의 대각선
	for (int r = 1; r <= n; r++) {
		//r번째 대각선에서 칸을 채워야 할 수.
		for (int i = 1; i <= n - r; i++) {
			//j값을 i+r로 해줘야 좌측상단에서 우측하단 방향으로 인덱스가 떨어진다.
			//i값은 그대로 사용가능.
			j = i + r;
			//이 식의 좌항에서의 최소값을 m[i][j]에 넣어야 한다. 우선 초항으로 하나 넣어놓고 시작.
			k = i;
			m[i][j] = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
			//윗 식의 좌항의 최소값을 찾는다.
			//k= i가 아니라 i+1한 이유는 위에서 한번 초항으로 값을 구했기 때문에 중복계산 방지.
			for (k = i+1; k <= j - 1; k++) {
				if (m[i][j] > m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]))
					m[i][j] = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);	
			}
			
		}
	}


}
void printM(int n) {
	for (int i = 1; i <= n; i++) {
		for(int j=1; j <= n; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

void printP() {
	for (int i = 0; i < cnt; i++)
		cout << p[i] << " ";
}

int main(void) {
	int n,_n;
	int trash;
	cin >> n;
	_n = n;
	while (n-- > 0) {
		if (n == 0) {
			cin >> p[cnt++];
			cin >> p[cnt++];
		}
		else
			cin >> p[cnt++] >> trash;
	}
	
	chainMatrix(_n);
	//printM(_n);
	printf("%d", m[1][_n]);
}
