#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	char a[100000];
	scanf("%s", a);
	string str = a;
	stack<bool> s;
	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')
			s.push(true);
		// str[i] ==  ')'
		else{
			if (!s.empty()) {
				s.pop();
				//닫는괄호가 레이저였다면
				if (i != 0 && str[i - 1] == '(')
					sum = sum + s.size();
				//닫는괄호가 막대기였다면
				else
					sum = sum + 1;
			}
		}
	}
	printf("%d", sum);
}
