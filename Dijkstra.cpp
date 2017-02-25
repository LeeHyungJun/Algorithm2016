
//다익스트라 using priority queue.
//방향그래프, 서로 다른 두 정점 사이에 여러개 간선이 존재 가능.

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <functional>	//greater, less
using namespace std;

#define V 20001
typedef pair<int, int> tpair;

//연산자 오버로딩
/*
struct cmp {
	bool operator()(tpair a, tpair b) {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
	}
};*/


int main(void) {
	int n, m, s;
	scanf("%d %d", &n, &m);
	scanf("%d", &s);

	//adj : 노드 n에 인접한 노드를 찾는 2차원 벡터(동적할당)
	vector<vector<tpair>> adj(n+1);
	//d값이 가장 낮은 노드를 추출하기 위한 우선순위 큐
	//q.first : d값, q.second : 노드번호 
	//이 상태로 pop시, first 오름차순을 기준으로 정렬.
	priority_queue<tpair, vector<tpair>, greater<tpair>> q;


	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		//동적할당.
		adj[u].push_back(pair<int,int>(v,w));
	}

	vector<int> d(n + 1, 1000000);
	d[s] = 0;
	//q.first : d값 , q.second : 노드번호
	q.push(pair<int, int>(d[s],s));

	while (!q.empty()) {
		int curNode = q.top().second;
		int cost = q.top().first;
		q.pop();
		for (int i = 0; i < adj[curNode].size(); i++) {
			int adjNode = adj[curNode][i].first;
			int weight = adj[curNode][i].second;

			if (d[adjNode] > d[curNode] + weight) {
				d[adjNode] = d[curNode] + weight;
				q.push(pair<int, int>(d[adjNode], adjNode));
			}
			//이 문장 여기다 놨다가 메모리초과 존나..ㅠㅜ
			//q.push(pair<int, int>(d[adjNode], adjNode));
		}
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] == 1000000)
			printf("INF\n");
		else
			printf("%d\n", d[i]);
	}
	return 0;
}
