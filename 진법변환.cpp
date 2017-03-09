#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	char s[10000];
	scanf("%s", s);
	int n;
	scanf(" %d", &n);
	//char* 형에서 string으로 형변환은 쉽다. 그냥 넣으면됨.
	string str = s;
	long long sum = 0;
	int cnt = 0;
	for (int i = str.size()-1; i >= 0; i--) {
		//숫자일 때.
		//char형 0 -> int형 48
		//char형 9 -> int형 57
		if(48 <= str[i] && str[i] <= 57)
			sum = sum + (str[i] - 48)*(pow(n, cnt++));
		//문자일 때.
		//char형 A -> int형 65
		//char형 Z -> int형 90
		else
			sum = sum + (str[i] - 55)*(pow(n, cnt++));
	}
	printf("%lld", sum);
}
