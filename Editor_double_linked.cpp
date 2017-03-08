#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <string>

#define MAX 600002
using namespace std;


class Node {
public:
	//다음 노드의 포인터를 저장하는 변수.
	Node* next;
	Node* pre;
	char data;
	//생성자
	Node(char d) {
		data = d;
		next = NULL;
		pre = NULL;
	}
};

class Solution {
public:
	Node* insert(Node* head, char data) {
		//노드가 암껏도 없었을때
		if (head == NULL) {
			head = new Node(data);
		}
		//노드가 있을때
		else {
			//previous Node를 찾기 위해서
			//노드가 1개였을 때, 2개이상을 때를 나눈다.
			Node* cur = head;
			//노드가 1개밖에 없을때.
			if (cur->next == NULL) {
				cur->next = new Node(data);
				cur->next->pre = head;
			}
			//노드가 2개 이상일때.
			else {
				while (cur->next != NULL) {
					cur = cur->next;
				}
				cur->next = new Node(data);
				cur->next->pre = cur;
			}
		}
		return head;
	}
	void display(Node* head) {
		Node *start = head;
		while (start->next != NULL) {
			printf("%c", start->data);
			start = start->next;
		}
		printf("%c",start->data);
	}
};
int main(void) {
	Node* head = NULL;
	Solution mylist;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		head = mylist.insert(head, s.at(i));
	}

	int N;
	scanf("%d", &N);
	Node* cur = head;
	//cur를 마지막 노드의 위치로 이동시킨다.
	while (cur->next != NULL) {
		cur = cur->next;
	}
	while (N-- > 0) {	
		//엔터, 스페이스 버퍼 받아준다.
		char command;
		scanf(" %c", &command);
		//cout << "command: " << command << endl;

		if (command == 'P') {
			char context;
			scanf(" %c", &context);
			//tail에 push하는 경우.
			if (cur->next == NULL) {
				cur->next = new Node(context);
			}
			//중간에 push하는 경우.
			else {
				Node* link = new Node(context);
				link->next = cur->next;
				link->pre = cur;
				cur->next = link;
			}
			//커서 이동.
			cur->next->pre = cur;
			cur = cur->next;
		}
		else if (command == 'L') {
			if(cur->pre != NULL)
				cur = cur->pre;
			//cout << "works L" << endl;
		}
		else if (command == 'D') {
			if(cur->next != NULL)
				cur = cur->next;
		}
		//Delete
		else if (command == 'B') {
			//tail 에서의 Delete.
			if (cur->next == NULL) {
				cur = cur->pre;
				cur->next = NULL;
			}
			//중간에서의 Delete
			else {
				//before
				cur = cur->pre;
				cur->next = cur->next->next;
				cur->next->pre = cur;
			}
		}
		else {
			cout << "error" << endl;
			return 0;
		}
	}

	//cout << "current pos : " << cur->data << endl;
	mylist.display(head);

}
