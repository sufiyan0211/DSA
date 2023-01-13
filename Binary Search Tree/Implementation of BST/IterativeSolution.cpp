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
    if(root == NULL){
    	root = new Node(Key);
        return root;
    }
    Node *curr = root, *prev;
    while(curr != NULL) {
        if(Key > curr->data) {
            prev = curr;
            curr = curr->right;
        }
        else {
            prev = curr;
            curr = curr->left;
        }
    }
    if(Key > prev->data) {
        prev->right = new Node(Key);
    }
    else {
        prev->left = new Node(Key);
    }
    return root;
}

int main() {
	int arr[] = {60,30, 90,20,40,80,110,100,120,130};
	int n = 10; // total nodes 

	Node *root = insert(NULL, arr[0]);

	for(int i=1;i<n;i++) {
		root = insert(root, arr[i]);
	}


	printTree(root); cout << endl;
	return 0;
}