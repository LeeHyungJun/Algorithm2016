#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	vector<int> drink(n+1);
	vector<vector<int>> dp(n+1,vector<int>(4,0));
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		scanf("%d", &tmp);
		drink[i] = tmp;
	}
	//계단오르기와 비슷하면서도 다른 문제.


	//예시.
	//4 5 1 1 10 11 일때
	//4,5,10,11을 선택할 수 있음.
	//4 5 1 1 1 10 11 일때
	//1을 모두 넘어갈 필요가 없음
	//즉 3번 앞까지만 보면됨.

	//dp[i][j] i번째오기 위해서 j칸 점프해서 왔다.
	//항상 j <= i
	//단, i일때, j=1이면 i+1일때 j는 2 이상이다. ( 3연속조건)
	int result;
	dp[1][1] = drink[1];
	dp[1][2] = drink[1];
	dp[1][3] = drink[1];
	result = dp[1][1];
	
	if (n > 1) {
		dp[2][1] = drink[1] + drink[2];
		dp[2][2] = drink[2];
		dp[2][3] = drink[2];
		result = dp[2][1];
	}

	for (int i = 3; i <= n; i++) {
		//한칸 점프해서 왔을 경우.
		//j가 2부터 시작하는 이유 : 1칸점프하고 또 1칸점프할 수 없기 때문.
		dp[i][1] = max(dp[i - 1][2], dp[i - 1][3]) + drink[i];
		dp[i][2] = max(max(dp[i - 2][1], dp[i - 2][2]), dp[i - 2][3]) + drink[i];
		dp[i][3] = max(max(dp[i - 3][1], dp[i - 3][2]), dp[i - 3][3]) + drink[i];

		if (result < max(max(dp[i][1], dp[i][2]), dp[i][3]))
			result = max(max(dp[i][1], dp[i][2]), dp[i][3]);
	}
	/*for (int i = 1; i <= n; i++) {
		cout << "i:["<<i<<",1]  -> " << dp[i][1] << "  " << "i:[" << i << ",2]  -> " << dp[i][2]
			<< "  " << "i:[" << i << ",3]  -> " << dp[i][3] << "  " << endl;
	}*/
	printf("%d", result);
}
