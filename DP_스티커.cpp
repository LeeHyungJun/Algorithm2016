#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		int n;
		scanf("%d", &n);
		vector<vector<int>> arr(3,vector<int>(n + 1));
		vector<vector<int>> dp(3, vector<int>(n + 1));
		arr[1][0] = 0;
		arr[2][0] = 0;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		dp[1][0] = 0;
		dp[2][0] = 0;
		dp[1][1] = arr[1][1];
		dp[2][1] = arr[2][1];

		for (int j = 2; j <= n; j++) {
			dp[1][j] = max(max(dp[1][j - 2], dp[2][j - 2]), dp[2][j - 1]) + arr[1][j];
			dp[2][j] = max(max(dp[1][j - 2], dp[2][j - 2]), dp[1][j - 1]) + arr[2][j];
		}
		printf("%d\n", max(dp[1][n], dp[2][n]));

	}
}
