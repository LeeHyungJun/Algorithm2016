#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sol(int N, vector<int>& p) {
	vector<int> s(N+1);
	s[0] = 0;
	int max = 0;
	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= n; i++) {
			if (max < s[n - i] + p[i])
				max = s[n - i] + p[i];
		}
		s[n] = max;
	}
	return s[N];
}

int main(void) {
	int N;
	scanf("%d", &N);
	vector<int> p(N+1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &p[i]);
	}

	printf("%d", sol(N, p));

	return 0;
}
