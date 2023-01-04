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

void preorder(Node *root) {
	stack <Node*> s;
	Node *curr = root;
	s.push(curr);
	while(!s.empty()) {
		curr = s.top();
		s.pop();
		cout << curr->key << " ";
		if(curr->right != NULL) {
			s.push(curr->right);
		}
		if(curr->left != NULL) {
			s.push(curr->left);
		}
	}

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

	preorder(root);
	cout << endl;

	return 0;
}