/**
*	file   : Most_Used_Alphabt.cpp
*	date   : 01.25.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : BaekJoon 1157
**/
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main(void) {
	int a[26] = { 0 };
	int b[26];
	int cnt = 0;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		//lowercase
		if (s[i] < 97)
			a[s[i] - 65]++;
		//Upper
		else
			a[s[i] - 97]++;
	}
	copy(a, a + 26, b);
	sort(b, b + 26);
	if (b[25] == b[24]) {
		cout << "?";
	}
	else {
		int max = 0;
		int maxIdx = 0;
		for (int j = 0; j < 26; j++) {
			if (a[j] > max) {
				max = a[j];
				maxIdx = j;
			}
		}
		cout << (char)(maxIdx + 65);
	}
}
