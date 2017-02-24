//다익스트라 using priority queue.


#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <functional>	//greater, less
using namespace std;

#define V 200001
#define E 300001

vector<vector<pair<int,int>>> adj(V);
vector<int> d;
priority_queue<int,vector<int>,greater<int>> q;


int main(void) {
	int n, m, s;
	scanf("%d %d", &n, &m);
	scanf("%d", &s);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(pair<int, int>(v, w));
	}
	//initialize
	


}
