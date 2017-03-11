#include <iostream>
using namespace std;

int mtx[101][101];
int ans[101][101];
int visit[101];
int n;

void DFS(int v)
{
	visit[v] = 1;	//무조건 방문하면 안됨! 고쳐야 하는부분
	for (int i = 0; i < n; i++)
	{
		//가는 길이 있을때 & 방문하지 않았을 때
		if (mtx[v][i] == 1 && visit[i] == 0)
			DFS(i);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d ", &mtx[i][j]);
	}

	for (int i = 0; i < n; i++)
	{
		DFS(i);

		//방문한 점을 결과 행렬에 넣음 & 초기화
		for (int j = 0; j < n; j++)
		{
			ans[i][j] = visit[j];
			visit[j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", ans[i][j]);
		puts("");
	}
}
