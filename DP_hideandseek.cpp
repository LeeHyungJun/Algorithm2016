/**
*	file   : DP_hideandseek.cpp
*	date   : 02.18.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : BackJoon_1697
**/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100001
//거리와 방문.
//-1 : 미방문 / 그 외 : 방문 및 start부터의 거리
//vector<int> d(MAX, -1);
int d[MAX];

void _init() {
	for (int i = 0; i <= MAX; i++) {
		d[i] = -1;
	}
}

int solBFS(int n, int k) {
	queue<int> q;
	//start에서 start까지 거리는 0.
	d[n] = 0;
	q.push(n);
	while (!q.empty()) {
		int x = q.front();

		if (x == k)
			return d[x];

		q.pop();

		// 3-adjacent
		// BFS탐색을 할 수록, 2*x값이 기하급수적으로 커지기 때문에
		// 상한선이 필요하다.
		if (x - 1 < MAX) {
			if (d[x - 1] == -1) {
				q.push(x - 1);
				d[x - 1] = d[x] + 1;
			}
		}
		if (x + 1 < MAX) {
			if (d[x + 1] == -1) {
				q.push(x + 1);
				d[x + 1] = d[x] + 1;
			}
		}
		if (2 * x < MAX) {
			if (d[2 * x] == -1) {
				q.push(2 * x);
				d[2 * x] = d[x] + 1;
			}
		}
	}
}

int main(void) {
	int n, k;
	cin >> n >> k;
	_init();

	printf("%d", solBFS(n, k));

}
