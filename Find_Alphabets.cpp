/**
*	file   : Find_Alphabets.cpp
*	date   : 01.26.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : BaekJoon_10809
**/

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	string s;
	vector<int> a(26, -1);
	getline(cin, s);
	int idx;
	vector<int> isVisit(26,0);
	for (int i = 0; i < s.size(); i++) {
		idx = int(s[i]) - 97;
		
		if(isVisit[idx] == 0)
			a[idx] = i;
		isVisit[idx]++;
	}

	for (int j = 0; j < a.size(); j++)
		cout << a[j] << " ";
}
 
