/**
*	file   : DFS_BFS.cpp
*	date   : 01.27.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : BackJoon 1260
**/

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

//  < 이문제 풀고나서 교훈 >
// 1. 함수 인자로 2차원 벡터 계속 넘기면 메모리 초과난다.
//    class 멤버변수로 인자로 계속 넘어가는걸 막으면 개꿀ㅎㅎ;
// 2. DFS가 stack으로 풀면 이해하기는 간단하나, 코드구현 너무 ....
//    recursion을 이용하면 정말 간단하게 DFS해결이 가능하다.

class Graph {
private:
	vector<vector<int>> adj;
	vector<int> isVisitDFS;
	int n, s;
public:
	Graph(int _n, int _s) {
		this->n = _n;
		this->s = _s;
		for (int i = 0; i < _n + 1; i++) {
			adj.push_back(vector<int>(_n + 1));
			isVisitDFS.push_back(-1);
		}

	}//.,
	void add_edge(int v, int u) {
		adj[v][u] = 1;
		adj[u][v] = 1;
	}
	void dfs(int start) {
		cout << start << " ";
		isVisitDFS[start] = 1;
		for (int i = 1; i < n + 1; i++) {
			if (adj[start][i] == 1 && isVisitDFS[i] == -1) {
				dfs(i);
			}
		}
	}
	void bfs() {
		queue<int> q;
		vector<int> d(n + 1, -1);
		vector<int> before(n + 1, 0);

		cout << s << " ";
		q.push(s);
		// "d[i]" means distance from "start node(s)" to "certain node(i)"
		d[s] = 0;
		before[s] = NULL;
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
	}//end of bfs

};


int main(void) {
	int n, m, s;
	int v, u;
	cin >> n >> m >> s;
	Graph g(n,s);
	
	for (int i = 0; i < m; i++) {
		cin >> v >> u;
		g.add_edge(v, u);
	}
	g.dfs(s);
	cout << endl;
	g.bfs();

}
