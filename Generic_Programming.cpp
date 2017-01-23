/**
*	file   : Day21_Generic_Programming.cpp
*	date   : 01.23.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : Hacker Rank
**/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void printArray(vector<T>& n_vector){
	typename vector<T>::iterator it;
	for (it = n_vector.begin(); it < n_vector.end(); it++) {
		cout << *it << ' ';
	}
}

int main() {
	int n;

	cin >> n;
	vector<int> int_vector(n);
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		int_vector[i] = value;
	}

	cin >> n;
	vector<string> string_vector(n);
	for (int i = 0; i < n; i++) {
		string value;
		cin >> value;
		string_vector[i] = value;
	}

	printArray<int>(int_vector);
	printArray<string>(string_vector);

	return 0;
}
