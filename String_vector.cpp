#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	string s;
	vector<string> v;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		v.push_back(s.substr(i, s.size()-i));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		//printf(" %s", v[i]);
		cout << v[i] << endl;
	}
}
