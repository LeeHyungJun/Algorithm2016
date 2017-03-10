#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> vPair(n);
	int t1, t2;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &t1, &t2);
		vPair[i] = pair<int, int>(t1, t2);
	}
	//first값으로 먼저 오름차순, first값이 같으면 second값을 기준으로 오름차순.
	sort(vPair.begin(), vPair.end());
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", vPair[i].first, vPair[i].second);
	}
	return 0;
}
