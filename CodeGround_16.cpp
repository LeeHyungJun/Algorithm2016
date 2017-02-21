

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long x, long long y) {
	if (y == 0)
		return x;
	else
		gcd(y, x%y);
}

int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		int m;
		scanf("%d", &m);
		vector<long long> v(m);
		for (int i = 0; i < m; i++) {
			scanf("%lld", &v[i]);
		}
		int min;
		int res = 0;
		int cnt = 1;
		bool zero = false;

		if (m == 2) {
			min = v[1] - v[0];
			if (min == 0)
				zero = true;
		}
		else
			min = gcd(v[1] - v[0], v[2] - v[1]);

		for (int i = 1; i < v.size() - 1; i++) {
			int tmp = gcd((v[i] - v[i - 1]), (v[i + 1] - v[i]));
			if (min == 0 || tmp == 0) {
				zero = true;
			}
			if (min > tmp) {
				min = tmp;
			}
		}


		bool sqr=false;
		for (int i = 1; i*i <= min; i++) {
			if (min%i == 0)
				res++;
			if (i*i == min)
				sqr = true;
		}

		if (sqr)
			res = 2 * res - 1;
		else
			res = 2*res;


		if (zero) {
			int t = v[0];
			for (int i = 1; i < v.size(); i++) {
				if (t != v[i]) {
					res = 0;
					break;
				}
				if (i == v.size() - 1) {
					res = 1;
				}
			}
		}
		v.clear();
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		printf("%d\n", res);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
