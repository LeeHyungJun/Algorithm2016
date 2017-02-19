// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

//#define MAX 1000000000
//int stone[MAX];

vector<int> v;

int main(int argc, char** argv) {
	
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);	// cin 사용 가능
	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.

		int n,k,tmp,last,first;
		scanf("%d", &n);
		v.push_back(0);
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			v.push_back(tmp);
			//stone[tmp] = 1;
		}
		scanf("%d", &k);
		//k거리보다 넓어서 갈 수 없거나
		//마지막에 도착하면
		int idx = 0; // 돌다리 찍는 idx
		int keep = 0;
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
		
			if (v[j] <= v[idx] + k) {
				keep = j;
			}
			else {
				if (idx == keep) {
					cnt = -1;
					break;
				}
				idx = keep;
				j--;
				cnt++;
			}
			if (j == n) {
				idx = keep;
				cnt++;
			}
		}

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
		printf("%d\n", cnt);
		v.clear();
		//memset(stone, 0, sizeof(stone));
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
