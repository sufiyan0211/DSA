#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int key;
	Node *left;
	Node *right;
	Node(int key) {
		this->key = key;
		left = right = NULL;
	}
};

int size(Node *root) {
	// basically level order Traversal
	queue<Node*> q;
	Node *curr = root;
	q.push(curr);
	int count = 0;
	while(!q.empty()) {
		count++;
		curr = q.front();
		q.pop();
		if(curr->left) {
			q.push(curr->left);
		}
		if(curr->right) {
			q.push(curr->right);
		}
	}
	return count;
}

/* Binary Tree in the input
			10
		   /   \
		 20     30
		/ \     / \
	  40   50  60  70
*/

int main() {
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right->left = new Node(60);
	root->right->right = new Node(70);

	cout << size(root);
	cout << endl;

	return 0;
}