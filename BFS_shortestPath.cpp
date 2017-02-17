#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 200002
//거리와 방문.
//-1 : 미방문 / 그 외 : 방문.
vector<int> d(MAX, -1);

int solBFS(int n, int k) {
	queue<int> q;
	//푸시전에 출력함.
	//start에서 start까지 거리는 0.
	d[n] = 0;
	q.push(n);
	while (!q.empty()) {
		int x = q.front();
		
		if (x == k)
			return d[x];
		q.pop();

		// 3-adjacent
		if (d[x - 1] == -1) {
			//printf("%d ", x - 1);
			q.push(x - 1);
			d[x - 1] = d[x] + 1;
		}
		if (d[x + 1] == -1) {
			//printf("%d ", x + 1);
			q.push(x + 1);
			d[x + 1] = 1;
			d[x + 1] = d[x] + 1;
		}
		if (d[2 * x] == -1) {
			//printf("%d ", 2 * x);
			q.push(2 * x);
			d[2 * x] = 1;
			d[2 * x] = d[x] + 1;
		}
	}
}

int main(void) {
	int n, k;
	cin >> n >> k;
	printf("%d", solBFS(n, k));
}
