#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void bfs(int n, vector<vector<int>> adj) {
	queue<int> q;
	vector<int> d(n + 1, -1);
	vector<int> before(n + 1, 0);
	int start = 1;
	cout << start << " ";
	q.push(start);
	// "d[i]" means distance from "start node(s)" to "certain node(i)"
	d[start] = 0;
	before[start] = NULL;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		//find adjacent node.
		for (int i = 1; i < n + 1; i++) {
			//if there is unvisited adjacent node.
			if (adj[cur][i] == 1 && d[i] == -1) {
				d[i] = d[cur] + 1;
				before[i] = cur;
				cout << i << " ";
				q.push(i);
			}
		}
	}//end of While
	cout << endl;
}//end of bfs

void dfs(int n, vector<vector<int>> adj) {
	stack<int> s;
	vector<int> visit(n + 1, -1);
	//시작노드 지정
	int start = 1;
	s.push(start);
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		//cur노드와 인접한 노드를 모두 push했다면
		//그 다음 cur 노드를 방문한다.
		for (int ad = 1; ad <= n; ad++) {
			if (adj[cur][ad] == 1 && visit[ad] == -1) {
				s.push(ad);
			}
		}
		visit[cur] = 1;
		cout << cur << " ";
	}
	cout << endl;
}

int main(void) {
	//입력값 : 노드개수 n
	//그 다음 라인부터 n*n행렬 으로 값이 0또는 1이 옴. 
	int n;
	scanf("%d", &n);
	vector<vector<int>> adj(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	cout << "BFS : ";
	bfs(n, adj);
	cout << "DFS : ";
	dfs(n, adj);
}
