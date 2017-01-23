/**
*	file   : Binary_Search_Tree.cpp
*	date   : 01.23.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : Hacker Rank
**/

#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};
class Solution {
public:
	Node* insert(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		}
		else {
			Node* cur;
			if (data <= root->data) {
				cur = insert(root->left, data);
				root->left = cur;
			}
			else {
				cur = insert(root->right, data);
				root->right = cur;
			}

			return root;
		}
	}
	int getHeight(Node* root) {
		if (root == NULL)
			return -1;

		int left = getHeight(root->left);
		int right = getHeight(root->right);

		if (left > right)
			return left + 1;
		else
			return right + 1;
	}
	
	void levelOrder(Node* root){
		queue<Node*> myQueue;
		cout << root->data << " ";
		myQueue.push(root);

		while (!myQueue.empty()) {
			if (myQueue.front()->left != NULL) {
				cout << myQueue.front()->left->data << " ";
				myQueue.push(myQueue.front()->left);
			}
			if (myQueue.front()->right != NULL) {
				cout << myQueue.front()->right->data << " ";
				myQueue.push(myQueue.front()->right);
			}
			myQueue.pop();
		}
	}		
};

int main() {
	Solution myTree;
	Node* root = NULL;
	int t;
	int data;

	cin >> t;

	while (t-- > 0) {
		cin >> data;
		root = myTree.insert(root, data);
	}
	int height = myTree.getHeight(root);
	cout << "Height : " << height << endl;
	cout << "Level Order : ";
	myTree.levelOrder(root);

	return 0;
}
