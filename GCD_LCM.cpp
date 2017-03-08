#include <iostream>

int gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		gcd(y, x%y);
}

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	int gcdV = gcd(a, b);
	printf("%d\n", gcdV);
	printf("%d\n", a*b / gcdV);
}
