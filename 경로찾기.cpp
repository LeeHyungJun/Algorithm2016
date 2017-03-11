#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	vector<vector<int>> adj(n + 1, vector<int>(n + 1));
	vector<vector<int>> sol(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &adj[i][j]);
		}
	}

	//각 노드 i마다 어디까지 갈 수 있는 지 확인한다.
	for (int i = 1; i <= n; i++) {

			//여기부터 DFS
			stack<int> s;
			vector<int> visit(n + 1,-1);
			int cur = i;
			//cur노드에서 j노드까지 갈 수 있는지 DFS알고리즘으로 확인한다.
			while (1) {
				visit[cur] = 1;
				//forward : 전진하는데 성공 여부
				bool forward = false;
				//adj 존재 확인
				for (int ad = 1; ad <= n; ad++) {

					//adj존재 && 미방문 = 전진 가능.
					if (adj[cur][ad] == 1 && visit[ad] == -1) {
						s.push(ad);
						//visit[cur] = 1;
						forward = true;
						cur = ad;
						break;
					}
				}
				//전진 할 수 없다면
				if (forward == false) {
					if (s.empty()) {
						break;
					}
					cur = s.top();
					s.pop();
				}
			}

			//이게 핵심코드...
			for (int j = 1; j <= n; j++) {
				if (visit[j] == 1)
					sol[i][j] = visit[j];
				else
					sol[i][j] = 0;
			}
			visit.clear();

	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", sol[i][j]);
		}
		printf("\n");
	}

}
