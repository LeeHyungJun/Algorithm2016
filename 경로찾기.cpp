#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	vector<vector<int>> adj(n + 1, vector<int>(n+1));
	vector<vector<int>> sol(n + 1, vector<int>(n + 1,-1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &adj[i][j]);
		}
	}

	//각 노드 i마다 어디까지 갈 수 있는 지 확인한다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {


			stack<int> s;
			int cur = i;
			//cur노드에서 j노드까지 갈 수 있는지 DFS알고리즘으로 확인한다.
			while (1) {
				//forward : 전진하는데 성공 여부
				bool forward = false;
				//cur노드에서 인접노드가 있는지 확인.
				for (int ad = 1; ad <= n; ad++) {
					//인접노드있고 가보지 않았더라면(-1).
					if (adj[cur][ad] == 1 && sol[cur][ad] == -1) {
						//방문한 노드를 스텍에 push.
						s.push(ad);
						forward = true;
						cur = ad;
						break;
					}
				}
				if (forward == false) {
					if (s.empty()) {
						break;
					}
					cur = s.top();
					s.pop();
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", sol[i][j]);
		}
		printf("\n");
	}

}
