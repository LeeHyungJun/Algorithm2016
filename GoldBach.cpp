/**
*	file   : GoldBach.cpp
*	date   : 02.04.2017 ~ 02.07.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : BackJoon_6588
**/

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

//전역변수 많이 쓰면 안좋다고 듣긴했는데
//막상 써보니까 메모리 낭비도 심하지 않고 파라미터 안넘겨서 좋은거같은데??

#define MAX 1000001
//v vector means result of the Eratos.
vector<bool> v(MAX,true);
//bool v[MAX];
// 어레이 vs 벡터 속도차이 실험 해봤으나 별로 차이 없는거같음;;

//p vector's value is prime number array.
vector<int> p;
//int p[MAX];

//Eratos
void getArrThePrimeNum() {
	for (int i = 2; i*i < MAX; i++) {
		if (v[i] == true) {
			for (int j = i*i; j < MAX; j = j + i) {
				v[j] = false;
			}
		}
	}
}
//Change V[] to P[] for easy solution. 
void changeContainer() {
	int cnt = 0;
	for (int i = 3; i*i < MAX; i++) {
		if (v[i] == true) {
			p.push_back(i);
			//p[cnt++] = i;
		}
	}
}

void isGoldBach(int n) {
	for (int i = 0; i < n; i++) {
		//i가 정해지면, n-i값이 자동으로 정해지기 때문에
		//우리는 이미 bool 타입의 인덱스가 소수일때 값이 true인 배열이 있으므로
		//for문 1번으로 충분하다.
		if (v[n - p[i]] == true) {
			printf("%d = %d + %d\n", n, p[i], n - p[i]);
			return;
		}
	}
}

int main(void) {
	int n;
	getArrThePrimeNum();
	changeContainer();
	
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		isGoldBach(n);
	}
}

