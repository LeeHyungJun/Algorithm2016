#include <stdio.h>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

//////////////////////////////////////////////////
//	itoa_1 using recursion and no library.	  	//
//											                      	//
//////////////////////////////////////////////////
int i = 0;

void recursion_itoa(int integer,char* c_str) {
	if (integer == 0)
		return;
	recursion_itoa(integer / 10, c_str);
	//int to char
	c_str[i++] = integer % 10 + '0';
}

void my_itoa_1(int integer, char* c_str) {

	if (integer < 0) {
		c_str[i++] = '-';
		integer = -integer;
	}

	recursion_itoa(integer, c_str);

	c_str[i] = NULL;
}

//////////////////////////////////////////////////
//	itoa_2 using stack							            //
//										                       		//
//////////////////////////////////////////////////

void my_itoa_2(int integer, char* c_str) {
	int idx = 0;
	stack<char> s;
	bool negative = false;
	if (integer < 0) {
		integer = -integer;
		negative = true;
	}
	s.push(NULL);

	while (integer > 0) {
		s.push(integer % 10 + '0');
		integer = integer / 10;
	}
	if (negative)
		s.push('-');

	while (!s.empty()) {
		//printf("%c", s.top());
		c_str[idx++] = s.top();
		s.pop();
	}
}

int main(void) {
	int integer;
	char c_str[100];
	char* a = c_str;
	scanf("%d", &integer);
	
	//itoa1 is using RECURSION
	my_itoa_1(integer, c_str);
	//itoa2 is using STACK
	my_itoa_2(integer, c_str);

	//"%s"는 \0 널문자까지 출력한다.
	printf("%s", c_str);
	return 0;

}
