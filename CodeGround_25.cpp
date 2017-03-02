#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

unsigned long long min_;
unsigned long long max_;

void search(unsigned long long x, int k) {
	if (k == 0) {
		if (x > max_)
			max_ = x;
		if (x < min_)
			min_ = x;
		return;
	}
	//even
	if (x % 2 == 0) {
		if ( (x - 1) % 3 == 0 && (x - 1) / 3 != 1) {
			search((x - 1) / 3, k - 1);
		}
	}
	search(2 * x, k - 1);
}

int main(int argc, char** argv) {
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		int k;
		scanf("%d", &k);

		//d[i]는 출발점(노드16)에서 i노드까지의 거리.
			
		int x = 1;
		int count = 0;
		//f가 16개. 0xff가 1바이트. 2진 : 1111 1111 10진 : 2^8-1 을 뜻함.
		//long long은 8바이트. 원래 2^(n-1)-1까지 양수로 표기되므로
		//unsigned 를 써주면 2^n-1까지 양수로 표기가능.
		//즉 unsigned int 는 4바이트이므로 마지막 값은 0xffffffff임.
		min_ = 0xffffffffffffffff;
		max_ = 0;
		search(x, k);
			
		printf("Case #%d\n", test_case);
		printf("%llu %llu\n", min_, max_);
		
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
