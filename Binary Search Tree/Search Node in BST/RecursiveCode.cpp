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

bool search(Node* root, int x) {
    if(root == NULL) {
        return false;
    }
    
    if(root->data == x) {
        return true;
    }
    
    if(x > root->data) {
        return search(root->right, x);
    }
    else {
        return search(root->left, x);
    }
    
    return root->data == x;
}

int main() {
	int arr[] = {60,30, 90,20,40,80,110,100,120,130};
	int n = 10; // total nodes 

	Node *root = NULL;
	for(int i=0;i<n;i++) {
		root = insert(root, arr[i]);
	}
	cout << "Printing BST in Preorder Traversal\n";
	printTree(root); cout << endl;

	cout << "search value 120\n";
	cout << search(root, 120) << endl;

	return 0;
}