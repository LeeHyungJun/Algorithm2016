#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	sort(p.begin(), p.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum = sum + p[j];
		}
	}
	printf("%d\n", sum);
	return 0;
}
