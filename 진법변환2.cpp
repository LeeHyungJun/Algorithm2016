#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	long long N;	//10진법의 수 N
	int B;			//B 진법
	scanf("%lld", &N);
	scanf(" %d", &B);
	int a;			//a 몫
	int b;			//b 나머지
	int n = N;
	stack<int> v;
	while (n >= B) {
		b = n % B;
		n = n / B;
		v.push(b);
	}
	v.push(n);
	int tmp;
	while(!v.empty()) {
		tmp = v.top();
		v.pop();
		//int to char. -> +55
		if (tmp > 9)
			printf("%c", tmp + 55);
		//9보다 작으면 걍 출력
		else
			printf("%d", tmp);
	}
}
