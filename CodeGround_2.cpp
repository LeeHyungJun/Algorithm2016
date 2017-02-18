// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);	// cin 사용 가능
	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.

		int n,_n,tmp;
		int max = 0;
		int res = 0;
		vector<int> v;
		vector<int> _v;
		scanf("%d", &n);
		_n = n;
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			v.push_back(tmp);
			/*if (tmp > max)
				max = tmp;
				*/
		}
		_v = v;
		sort(_v.begin(), _v.end());
		for (int i = 0; i < n; i++) {
			_v[i] = _v[i] + _n--;
			if (_v[i] > max)
				max = _v[i];
		}

		for (int i = 0; i < n; i++) {
			if (v[i] + n >= max)
				res++;
		}

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
		printf("%d\n", res);
		v.clear();
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
