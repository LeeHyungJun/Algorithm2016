/**
*	file   : Balanced_Brackets.cpp
*	date   : 01.25.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : Hacker Rank / BackJoon
**/

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;
 
string isVPS(string ps) {
	int len = ps.length();
	vector<int> st;
	
	for (int i = 0; i < len; i++) {
		if (ps[i] == '(') {
			st.push_back(1);
		}
		else if (ps[i] == ')') {
			if (st.empty())
				return "NO";
			st.pop_back();
		}
	}
	//Return Value
	//true  : empty
	//false : otherwise.
	if (!st.empty())
		return "NO";
	else
		return "YES";
}

int main(void) {
	int T;
	string ps;	//Parenthesis String
	cin >> T;
	cin.ignore();	// important
	while (T-- > 0) {
		getline(cin, ps);
		cout << isVPS(ps) << endl;
	}
}
