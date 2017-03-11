#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] <= k) {
			cnt++;
			k = k - v[i];
			//cout << "cnt : " << cnt <<" k: " << k <<" v[i] : "<<v[i]<<endl;
			i++;
		}
		else if (k <= 0)
			break;
	}
	printf("%d\n", cnt);
}
