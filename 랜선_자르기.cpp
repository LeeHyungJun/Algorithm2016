#include <iostream>
#include <vector>
using namespace std;

vector<unsigned int> v(10001);
int N, K;

int check(unsigned int mid) {
	int sum = 0;
	for (int i = 1; i <= K; i++) {
		sum = sum + (v[i] / mid);
	}
	return sum;
}

int main(void) {
	scanf("%d %d", &K, &N);

	for (int i = 1; i <= K; i++) {
		scanf("%ud", &v[i]);
	}
	//cout << v[1] << " " << min << endl;
	unsigned int left = 0;
	unsigned int right = 0xffffffff;
	unsigned int mid, res = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		//cout << " mid : " << mid;
		//sum = 랜선의 개수
		int n = check(mid);
		//cout << "lan cnt : "<< n << endl;
		if (n >= N) {
			//mid를 구하는게 아니라 mid의 최대값을 구하는것이다.
			//n > N인경우는 mid가 현재 높다는 낮다는 뜻이므로
			//계속 mid값을 올리는 중이다.
			if (res < mid)
				res = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
		
	}

	printf("%u\n", res);
	return 0;
}
