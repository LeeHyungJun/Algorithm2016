#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
	int N,M;
	scanf("%d", &N);
	vector<int> v(N + 1);
	for (int i = 0; i < N; i++)
		scanf("%d", &v[i]);

	sort(v.begin(), v.end());

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int tmp=0;
		scanf("%d", &tmp);
		int left = 0;
		int right = N;
		int mid = 0;
		while (left <= right) {
			mid = (left + right) / 2;
			//check
			if (v[mid] < tmp)
				left = mid + 1;
			else if (v[mid] > tmp)
				right = mid - 1;
			else
				break;
		}
		if (v[mid] == tmp)
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");
	return 0;
}
