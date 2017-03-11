#include<stdio.h>
#include<string>

typedef struct _node{
	int data;
	struct _node* next;
} node;

node* reverse_list(node* head) {
	node* cur = head;
	node* prev = NULL;
	node* tmp_next = NULL;

	//cur의 next노드를 tmp에 저장시켜놓는다.
	while (cur) {
		//다음에 탐색하여 나갈 노드를 tmp_next에 저장.
		tmp_next = cur->next;
		//cur노드의 next방향을 prev로 꺽어놓고
		cur->next = prev;
		
		//prec가 자신이 된다.
		prev = cur;
		//아까 저장해놓은 next를 cur에 대입.
		cur = tmp_next;
	}
	//while종료시 cur은 맨 마지막의 NULL값이 되어있음.
	return prev;
}

node* tail_insert(node* head, int data) {
	if (head == NULL) {
		head = (node*)malloc(sizeof(node));
		head->data = data;
		head->next = NULL;
	}
	else {
		node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = (node*)malloc(sizeof(node));
		temp->next->data = data;
		temp->next->next = NULL;
	}
	return head;
}

void display(node *head)
{
	node *cur = head;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main(void) {
	int n,data;
	node* head = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int data;
		scanf("%d", &data);
		head = tail_insert(head, data);
	}
	head = reverse_list(head);
	display(head);
	return 0;
}
