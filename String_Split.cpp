#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int main(void) {
	string s;
	getline(cin, s);
	char* c_s = new char[s.length() + 1];
	strcpy(c_s, s.c_str());

	int cnt = 0;
	char* pch = strtok(c_s, " ");
	while (pch != NULL) {
			cnt++;
			pch = strtok(NULL, " ");
	}
	cout << cnt;
}
