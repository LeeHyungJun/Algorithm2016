#include <vector>
#include <iostream>
using namespace std;

int main(void) {
	//요소수 2개짜리 벡터를 만든다.
	//그리고 각 요소에 vector<int> x(3)을 넣는다.
	//벡터는 값들을 0으로 초기화한다.
	vector<vector<int>> v1(2, vector<int>(3));
	vector<vector<int>> v2;

	v2.push_back(vector<int>(3));
	v2.push_back(vector<int>(3));

	// v1과 v2는 동일하다.
	for (int i = 0; i<2; i++) {
		for (int j = 0; j<3; j++)
			cout << v1[i][j] << " ";
		  //cout << v2[i][j] << " "l
		cout << endl;
	}
}
