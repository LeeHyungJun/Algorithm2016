#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> v(1002, vector<int>(1002));
queue<pair<int, int>> q;
vector<vector<int>> d(1002, vector<int>(1002));

int max_ = 0;

void func(int x, int y, int n, int m, int bx, int by) {
	if (v[x][y] == 0 && (1 <= x && x <= n && 1 <= y && y <= m)) {
		v[x][y] = 1;
		q.push(pair<int, int>(x, y));
		d[x][y] = d[bx][by] + 1;
		if (max_ < d[x][y])
			max_ = d[x][y];
	}
}

int main(void) {
	int m, n;
	scanf("%d %d", &m, &n);

	//입력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	//BFS시작점을 찾는다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[i][j] == 1) {
				q.push(pair<int, int>(i, j));
				d[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		pair<int,int> cur = q.front();
		q.pop();
		//adj찾기
		int x = cur.first;
		int y = cur.second;
		
		func(x+1, y, n, m, x, y);
		func(x-1, y, n, m, x, y);
		func(x, y+1, n, m, x, y);
		func(x, y-1, n, m, x, y);

	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[i][j] == 0) {
				printf("%d", -1);
				return 0;
			}
		}
	}
	printf("%d", max_);

}
