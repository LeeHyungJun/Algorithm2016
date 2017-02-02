/**
*	file   : ACM_Hotel.cpp
*	date   : 02.02.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : BackJoon_10250
**/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string Solve(int h, int w, int n) {
	
	int front;
	int end;
	string res;

	end = (n / h) + 1;
	front = n%h;

	if ((n % h) == 0) {
		front = h;
		end = end - 1;
	}

	if (end < 10)
		res = to_string(front)+ "0" + to_string(end);
	else
		res = to_string(front)+ to_string(end);
	
	return res;
}

int main(void) {
	int T,h,n,w;
	cin >> T;
	while (T-- > 0) {
		cin >> h >> w >> n;
		cout << Solve(h,w,n) << endl;
	}
	return 0;
}
