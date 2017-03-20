#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

int main(void) {

	string input_str;
	getline(cin, input_str);
	int i = 0;
	int j = input_str.length()-1;
	bool check = true;
	while (i <= j) {
		if (input_str[i] != input_str[j]) {
			printf("0\n");
			check = false;
			break;
		}
		i++;
		j--;
	}
	if (check == true)
		printf("1\n");
	return 0;
}
