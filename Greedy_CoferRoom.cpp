/**
*	file   : Greedy_ConferRoom.cpp
*	date   : 02.01.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : BaekJoon_1931
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//소팅을 두번째 pair값으로 진행한다.
//두번째 pair값이 같을경우 첫 번째 pair값을기준으로 한다.
bool cmp1(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else if (a.second < b.second)
		return true;
	else
		return false;
}

bool cmp2(pair<int, int>& a, pair<int, int>& b) {
	return a.first < b.first;
}

class Solution {
private:
	vector<pair<int, int>> v;
	int sIdx;
	int eIdx;
	int n;
public:
	Solution(int n) {
		this->n = n;
		sIdx = 0;
		eIdx = 0;
	}
	int getNumOfConference() {
		int idx = 0;
		int cnt = 1;
		sort(v.begin(), v.end(), cmp1);
		
		for (int i = 1; i < n; i++) {
			if ((v[idx].second <= v[i].first)){
				cnt++;
				idx = i;
			}
		}
		return cnt;
	}
	void addConference(int s, int e) {
		v.push_back(pair<int, int>(s, e));
	}
	void printMap() {
		sort(v.begin(), v.end(), cmp1);
		//그냥 기본형태 sort 함수돌리면 pair.first기준으로 정렬.
		//pair.first가 같으면 pair.second기준으로 정렬.
		//sort(v.begin(), v.end());
		for (int i = 0; i < n; i++) {
			cout << v[i].first << " " << v[i].second << endl;
		}
	}
};


int main(void) {
	int n;
	cin >> n;
	Solution sol(n);
	while (n-- > 0) {
		int s, e;
		cin >> s >> e;
		sol.addConference(s, e);
	}
	cout << sol.getNumOfConference() << endl;
	//sol.printMap();
}
