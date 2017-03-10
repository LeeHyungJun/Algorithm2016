#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second < b.second)
		return 1;
	else if (a.second == b.second)
		return a.first < b.first;
	else
		return 0;
}

int main(void) {
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> vPair(n);
	int t1, t2;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &t1, &t2);
		vPair[i] = pair<int, int>(t1, t2);
	}
	sort(vPair.begin(), vPair.end(), cmp);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", vPair[i].first, vPair[i].second);
	}
	return 0;
}
