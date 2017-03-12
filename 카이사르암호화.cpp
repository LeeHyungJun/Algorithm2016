#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (65 <= s[i] && s[i] <= 90) {
			if (s[i] >= 78)
				s[i] = s[i] - 26;
			printf("%c", int(s[i]) + 13);
		}
		else if (97 <= s[i] && s[i] <= 122) {
			if (s[i] >= 110)
				s[i] = s[i] - 26;
			printf("%c", int(s[i]) + 13);
		}
		else
			printf("%c", s[i]);
	}
}
