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

int height(Node *root) {
	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL) return 1;
	return 1+max(height(root->left), height(root->right));
}
/* Binary Tree in the input
			10
		   /   \
		 20     30
		/ \     / \
	  40   50  60  70
	  			  /
				80
			   /	
			 90
			   \
			   100

*/

int main() {
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right->left = new Node(60);
	root->right->right = new Node(70);
	root->right->right->left = new Node(80);
	root->right->right->left->left = new Node(90);
	root->right->right->left->left->right = new Node(100);


	cout << height(root);
	cout << endl;

	return 0;
}