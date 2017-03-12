#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	vector<int> dp(n + 1,100000);
	vector<int> pow(sqrt(n) + 1);
	for (int i = 1; i <= sqrt(n); i++) {
		pow[i] = i*i;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sqrt(n); j++) {
			if (pow[j] <= i && dp[i] > dp[i-pow[j]] + 1) {
				dp[i] = dp[i - pow[j]] + 1;
			}
		}
	}

	printf("%d\n", dp[n]);
}
