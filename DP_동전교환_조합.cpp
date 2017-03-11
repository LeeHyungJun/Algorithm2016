#include <iostream>
#include <vector>
using namespace std;

//dp[n][k]
//k원을 n개의 동전으로 나타낼 수 있는 경우의 수
//같은 동전을 여러번 사용 가능 = > 조합의 수

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> v(n+1);
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	//Base case
	dp[0][0] = 1;
	//dp[n][0]: 0원을 n개의 동전으로 나타낼 수 있는 수 = 1
	for (int i = 1; i <= n; i++)
		dp[i][0] = 1;
	//dp[0][k]: k원을 0개의 동전으로 나타낼 수 없음 = 0
	for (int j = 1; j <= k; j++)
		dp[0][j] = 0;

	//k원을 n개의 동전으로 나타낼 수 있는 경우의수
	//v[i]원 동전이 포함되지 않는 경우 + v[i]원 동전이 포함되는 경우.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= v[i])
				dp[i][j] = dp[i - 1][j] + dp[i][j - v[i]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	//for (int i = 0; i <= n; i++) {
	//	for (int j = 0; j <= k; j++) {
	//		printf("%d", dp[i][j]);
	//	}printf("\n");
	//}
	printf("%d\n", dp[n][k]);
}
