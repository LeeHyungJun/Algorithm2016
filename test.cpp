#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {
	int n;
	int quotient;
	vector <int> reminderVector;

	cin >> n;
	quotient = n;
	while (quotient > 1) {
		reminderVector.push_back(quotient % 2);
		quotient = quotient / 2;
	}

	while (!reminderVector.empty()) {
		cout << reminderVector.back();
		reminderVector.pop_back();
	}

	return 0;
}
