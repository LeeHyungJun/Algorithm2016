
//middle of the solving



#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	vector<int> a(n + 1);
	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	//원소의 개수가 1개면 증가하는 수열이아니다..

	//원소의 개수가 1 이상일 때.
	//else {
		//dp : i번째를 마지막으로하는 증가부분 수열의 합이 가장 큰값.
	dp[1] = a[1];
	int result = dp[1];
	for (int i = 2; i <= n; i++) {
		int max = 0;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && dp[j] + a[i] > max) {
				max = dp[j] + a[i];
			}
		}
		dp[i] = max;
		//dp[i]중 제일 큰 값을 찾는다.
		if (result < dp[i])
			result = dp[i];
	}

	printf("%d\n", result);
	//}

}
