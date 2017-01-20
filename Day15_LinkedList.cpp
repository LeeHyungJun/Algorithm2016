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
	Node* insert(Node* head, int data)
	{
		if (head == NULL) {
			head = new Node(data);
		}
		else {
			Node* temp = head;
			//temp를 주소값으로 받았으므로, temp안에있는 값들을 변경시키면 head에도 적용됨.
			//move temp upto last node
			while (temp->next != NULL) {
				temp = temp->next;
			}
			//if temp is last node
			temp->next = new Node(data);
			//head -> next값도 바뀌게된다?? 왜? 포인터라서?
		}
		//temp는 분명 마지막 노드를 가리키는 포인터변수이다. head는 여전히 맨 첫노드의 주소값인가? 
		//head도 마지막 노드의 주소값아니냐? : 출력확인결과, head는 맨 첫노드의 주소값이고, temp만 마지막 노드의 주소값.
		return head;
		//Complete this method
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
	mylist.display(head);

}
