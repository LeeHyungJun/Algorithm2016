#include<stdio.h>
#include<string>

int main(void) {
	char* str = new char[100];
	char* str_;
	char* end_pointer;

	scanf("%s", str);
	str_ = str;

	end_pointer = str + strlen(str) - 1;
	while (str < end_pointer) {
		char tmp = *str;
		*str = *end_pointer;
		*end_pointer = tmp;
		str++;
		end_pointer--;
	}

	printf("%s", str_);

	return 0;
}
