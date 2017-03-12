#include <stdio.h>
#include <string>
unsigned char count_bit(unsigned char number)
{
	unsigned char count = 0;

	while (number) {
		printf("%d\n", number);
		count += number & 1;
		number = number >> 1;
	}

	return count;
}

int main(void) {
	//printf("1바이트 2진수를 입력하시오\n");
	unsigned char a = 255;
	printf("%d", count_bit(a));
	//}
	return 0;

}
