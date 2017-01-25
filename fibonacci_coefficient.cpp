#include <iostream>
#include <algorithm>
using namespace std;


int recursion_fibonacci(int n) {
	if (n == 0 || n == 1)
		return n;
	return recursion_fibonacci(n - 1) + recursion_fibonacci(n - 2);
}

void for_fibonacci(int n) {
	int* a = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		if (i == 0 || i == 1)
			a[i] = i;
		else
			a[i] = a[i - 1] + a[i - 2];
	}
	cout << a[n] << endl;
}

int factorial(int n) {
	int res = 1;
	if (n == 0)
		return 1;
	for (int i = 1; i <= n; i++)
		res *= i;
	return res;
}

int for_binomial_coefficient(int n, int k) {
	if (k > n)
		return 0;
	else if (k < 0)
		return 0;
	
	return factorial(n) / (factorial(n - k)*factorial(k));
}

int main(void) {
	
	//fibonacci
	/**
	int n;
	cin >> n;
	cout << recursion_fibonacci(n) << endl;
	for_fibonacci(n);
	*/

	//binomial_coefficient
	/*int n, k;
	cin >> n >> k;
	cout << for_binomial_coefficient(n,k);
	*/
}
