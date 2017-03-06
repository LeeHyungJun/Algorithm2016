#include <iostream>
#include <vector>
using namespace std;

//Binomial Coefficient
void bi_Coef(int a, int b, vector<vector<int>>& v) {
	for (int n = 1; n <= a; n++) {
		for (int r = 1; r <= n; r++) {
			if (r == 1)
				v[n][r] = n;
			else if (n == r)
				v[n][r] = 1;
			else
				v[n][r] = v[n - 1][r] + v[n - 1][r - 1];
		}
	}
}

int main(void) {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n, r;
		scanf("%d %d", &r, &n);
		vector<vector<int>> v(n+1,vector<int>(n+1,0));

		bi_Coef(n, r, v);
		printf("%d\n", v[n][r]);
	}
}
