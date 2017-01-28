//Double Ended Queue
#include <iostream>
#include <deque>
using namespace std;

void push(deque<char>& q){
	q.push_back('a');
	q.push_back('b');
	q.push_back('c');
}

int main(void) {
	deque<char> queue;

	push(queue);
	cout << "< Like Queue >" << endl;
	while (!queue.empty()) {
		cout << queue.front() << " ";
		queue.pop_front();
	}

	push(queue);
	cout << endl << "< Like Stack >" << endl;
	while (!queue.empty()) {
		cout << queue.back() << " ";
		queue.pop_back();
	}
}
