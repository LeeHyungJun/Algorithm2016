#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

void add_edge(int v, int u, vector<vector<int>>& adj) {
		adj[v][u] = 1;
		adj[u][v] = 1;
}

void dfs(int s, int n, vector<vector<int>> adj) {
	stack<int> st;
	vector<int> d(n + 1, -1);
	cout << s << " ";
	st.push(s);
	d[s] = 0;
	int pos = st.top();
	while (!st.empty()) {
		//find adj
		for (int i = 1; i < n + 1; i++) {
			//인접한 노드 중 방문안한 노드가 있다면
			if (adj[pos][i] == 1 && d[i] == -1) {
				d[i] = 0;
				cout << i << " ";
				st.push(i);
				//i = 1;
				pos = i;
				break;
			}
			//방문안한 노드가 없다면 이전 노드로 돌아간다.
			if (i == n && a == 0) {
				st.pop();
				pos = st.top();
			}
		}
	}
}
void bfs(int s, int n, vector<vector<int>> adj) {
	queue<int> q;
	vector<int> d(n + 1, -1);
	int before;

	cout << s << " ";
	q.push(s);
	d[s] = 0;
	//before = s;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i < n + 1; i++) {
			if (adj[cur][i] == 1 && d[i] == -1) {
				//d[i] = d[before] + 1;
				//before = cur;
				d[i] = 0;
				cout << i << " ";
				q.push(i);
			}
		}
	}//end of While
}//end of bfs

int main(void) {
	int n,m,s;
	int v, u;
	cin >> n >> m >> s;

	vector<vector<int>> adj;
	for(int i=0; i<n+1; i++)
		adj.push_back(vector<int>(n + 1));

	for (int i = 0; i < m; i++) {
		cin >> v >> u;
		add_edge(v, u, adj);
	}
	bfs(s, n, adj);
	cout << endl;
	dfs(s,n,adj);


}
/*
for (int i = 0; i < n; i++) {
	for (int j = 0; j<n; j++)
		cout << adj[i][j] << " ";
	cout << endl;
}*/
