/**
*	file   : Linked_List.cpp
*	date   : 01.20.2017 / 01.23.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : Hacker Rank
**/

#include <iostream>
#include <cstddef>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int d) {
		data = d;
		next = NULL;
	}
};
class Solution {
public:
	Node* removeDuplicates(Node *head)
	{
		Node* current = head;
		while (current->next != NULL) {
			if (current->data == current->next->data) {
				current->next = current->next->next;
				//delete current;
			}
			else
				current = current->next;
		}
		return head;
	}
	Node* insert(Node* head, int data)
	{
		if (head == NULL) {
			head = new Node(data);
		}
		else {
			Node* temp = head;
			//temp를 head주소값으로 받았으므로, temp안에있는 값들을 변경시키면 head에도 적용됨.
			while (temp->next != NULL){
				//temp노드가 다음 노드로 한칸씩 움직인다고 생각하면 됨.
				temp = temp->next;
			}
			//마지막 노드에 삽입.
			temp->next = new Node(data);
		}
		//Node형 포인터 변수인 temp를 이용해 insert를 진행하였고, head에도 적용이 된 상태이므로, head를 반환한다.
		return head;
	}
	void display(Node *head)
	{
		Node *start = head;
		while (start)
		{
			cout << start->data << " ";
			start = start->next;
		}
	}
};
int main()
{
	Node* head = NULL;
	Solution mylist;
	int T, data;
	cin >> T;
	while (T-->0) {
		cin >> data;
		head = mylist.insert(head, data);
	}
	head = mylist.removeDuplicates(head);
	mylist.display(head);

}
