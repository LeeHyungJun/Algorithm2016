#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sol(int N, vector<int>& a) {
	//s[i] = i번째 숫자 (=a[i])를 꼭 포함하는 최장 수열의 길이.
	vector<int> s(N + 1,1);
	//maxS = s[] 배열의 요소 중 가장 큰 값
	int maxS = 0;
	//i번째 숫자를 꼭 포함하는 수열을 찾기 위해서는, i보다
	//이전값인 j번째의 숫자인 a[j] 가 a[i]보다 작아야한다.
	//그 중 가장 큰값을 s[i]에 넣는다.
	for (int i = 2; i <= N; i++) {
		int max = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j]) {
				if (max < s[j] + 1)
					max = s[j] + 1;
			}
		}
		//i보다 이전 인덱스인 j들 중 가장 큰값을 s[i]에 넣는다.
		s[i] = max;
		//s[i]에서 가장 큰 값 찾기.
		if (maxS < s[i])
			maxS = s[i];
	}
	return maxS;
}

int main(void) {
	int N;
	scanf("%d", &N);
	vector<int> a(N + 1);
	a[0] = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
	}
	
	if (N == 1)
		printf("%d", 0);
	else
		printf("%d", sol(N, a));
}
