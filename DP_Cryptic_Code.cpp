#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	string s;
	getline(cin, s);
	vector<int> dp(s.size() + 1);
	//1자리라고 1이 아니다.!! 0도있다!!!!!
	if (s[0] != '0')
		dp[0] = 1;
	else
		dp[0] = 0;

	for (int i = 1; i < s.size(); i++) {
		//substr(a,b)
		//0을 front, i를 end 인덱스라고 했을때.
		//a번째인데스부터 b번째까지 출력.
		int tmp = stoi(s.substr(i - 1, 2));
		//printf("%d ", tmp);
		//두 자리 일때, 20이 아닐때.
		if (tmp == 10 || tmp == 20) {
			if (i == 1)
				dp[1] = 1;
			else
				dp[i] = dp[i - 2];
		}
		else if ( 10 < tmp && tmp <= 26) {
			if (i == 1)
				dp[1] = 2;
			else
				dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000;
		}
		//한 자리 일때
		else
			dp[i] = dp[i - 1];
	}

	printf("%d", dp[s.size() - 1] % 1000000);
}
