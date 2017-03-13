#include <iostream>
#include <stdio.h>
using namespace std;

class circularQueue {
public:
	int front, back;
	int capacity;
	int* arr;
public:
	circularQueue(int n, int m) : front(0), back(0) {
		this->capacity = n + 1;
		this->arr = new int[n + 1];
	}
	bool isEmpty() {
		if (front == back)
			return true;
		else
			return false;
	}
	bool isFull() {
		if (front == (back + 1) % capacity)
			return true;
		else
			return false;
	}

	int getFront() {
		if (!isEmpty()) {
			//cout <<"front : "<< front << " ";
			return arr[(front + 1) % capacity];
		}
		else
			return -1;
	}

	int getBack() {
		if (!isEmpty())
			return arr[back];
		else
			return -1;
	}

	void push(int data) {
		if (!isFull()) {
			back = (back + 1) % capacity;
			arr[back] = data;
		}
		else {
			printf("< full queue >\n");
			cout << "capacity :  " << capacity << endl;
			cout << "front : " << front << "back : " << back << endl;
		}
	}

	void pop() {
		if (!isEmpty())
			front = (front + 1) % capacity;
		else
			printf("< empty qeueue > \n");
	}
};

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	circularQueue cq(n, m);
	for (int i = 1; i <= n; i++) {
		cq.push(i);
	}
	printf("<");
	while (!cq.isEmpty()) {
		for (int i = 1; i <= m - 1; i++) {
			int tmp = cq.getFront();
			cq.pop();
			cq.push(tmp);
		}
		//마지막 직전에.
		if (cq.back == cq.front + 1)
			printf("%d", cq.getFront());
		else
			printf("%d, ", cq.getFront());
		cq.pop();
	}
	printf(">");
}
