#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
int res[333334];

int main(void) {
	string s;
	getline(cin, s);
	int cnt = 0;
	double sum = 0.0;
	int len = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		res[len] = res[len] + ((double(s[i])-48) * pow(2.0, double(cnt)));
		cnt++;
		if (cnt == 3 || i == 0) {
			cnt = 0;
			sum = 0.0;
			len++;
		}
	}
	for (int i = len-1; i >= 0; i--) {
		printf("%d", res[i]);
	}

}
