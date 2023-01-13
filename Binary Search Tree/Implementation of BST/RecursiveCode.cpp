#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *left, *right;

	Node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

/* Binary Search Tree in the input
			 60
		    /  \
		  30    90
		 / \    / \
	   20   40 80  110
	  			   / \
				 100  120
				 		\
			   			130
*/

void printTree(Node *root) {
	if(root != NULL) {
		cout << root->data << " ";
		printTree(root->left);
		printTree(root->right);
	}
}

Node* insert(Node* root, int Key) {
    if(root == NULL) {
        root = new Node(Key);
    }
    else if(Key > root->data) {
        root->right = insert(root->right, Key);
    }
    else if(Key < root->data) {
        root->left = insert(root->left, Key);
    }
    return root;
}

int main() {
	int arr[] = {60,30, 90,20,40,80,110,100,120,130};
	int n = 10; // total nodes 

	Node *root = NULL;
	for(int i=0;i<n;i++) {
		root = insert(root, arr[i]);
	}


	printTree(root); cout << endl;
	return 0;
}