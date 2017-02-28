// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;
typedef pair<int, int> tpair;

int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);	// cin 사용 가능

	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
		int n, m;
		scanf("%d %d", &n, &m);
		vector<vector<tpair> > adj(n+1);
		int a, b, c;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back(tpair(b, c));
			//무방향 그래프라서
			adj[b].push_back(tpair(a, c));
		}

		
		vector<bool> possibleNode(n + 1, true);

		//Dijkstra를 n번 돌린다.
		for (int inode = 1; inode <= n; inode++) {
			int start = inode;
			//q를 왜 int형 큐로 만들지않고 tpair형으로 만들었을까?
			//adj한 노드에서 가장 작은 d값을 찾아야 하는데 d에대한 정보도 저장하기위해 pair를 사용한다.
			//q.first = d값 / q.second : 노드값
			priority_queue<tpair,vector<tpair>, greater<tpair> > q;
			vector<int> d(n+1,10000000);
			//vector<vector<int>> via(n+1);
			d[start] = 0;
			//q.first : d값 / q.second : 노드번호
			//adj.first : to / adj.second : cost
			q.push(tpair(d[start],start));
			//역추적
			//via[start].push_back(0);
			//다익스트라 시작
			while (!q.empty()) {
				int from = q.top().second;
				q.pop();
				for (int i = 0; i < adj[from].size(); i++) {
					int to = adj[from][i].first;
					int cost = adj[from][i].second;
					
					//Relax 연산
					if (d[to] > d[from] + cost) {
						d[to] = d[from] + cost;
						q.push(tpair(d[to],to));
						//역추적
						//via[to].push_back(from);
					}
				}
			}//다익스트라 1번 종료.



			//중간정점이 될 수 있는지 확인한다.
			//from이 to로 가는데 중간이 될 수 있나?
			for (int i = 1; i <= n; i++) {
				int to = i;
				for (int j = 0; j < adj[i].size(); j++) {
					int from = adj[i][j].first;
					int cost = adj[i][j].second;
					//이거 안써줘서 개고생
					if (from != start) {
						if (d[to] == d[from] + cost) {
							possibleNode[from] = false;
							//printf("from : %d to : %d \n", from, to);
						}
					}
				}	
			}

		}//다익스트라 n번 돌리는거 종료.

		
		// 이 부분에서 정답을 출력하십시오.
		//
		
		int cnt = 0;
		printf("Case #%d\n", test_case);	// cout 사용 가능
		for (int i = 1; i <= n; i++) {
			if (possibleNode[i] == true) {
				cnt++;
			}
		}
		printf("%d ", cnt);
		for (int i = 1; i <= n; i++) {
			if (possibleNode[i] == true) {
				printf("%d ", i);
			}
			//printf("%d ", possibleNode[i]);
		}
		printf("\n");
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
