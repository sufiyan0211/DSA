#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node *right;
	Node(int data) {
		this->data = data;
		left = right = NULL;
	}
};


int sizeOfBT(Node *root) {
    if(root == NULL) return 0;
    return 1+sizeOfBT(root->left) + sizeOfBT(root->right);
}

/*
There are 2 properties to be a MaxHeap
    1. It should be complete binary Tree
    2. Value of every node is greater than its descendents
*/

bool isCompleteBT(Node *root, int n, int i) {
    
    if(root == NULL) return true;
    if(i >= n) return false;
    
    int left = (2*i) + 1;
    int right = (2*i) + 2;
    
    return isCompleteBT(root->left, n, left) && isCompleteBT(root->right, n, right);
}

bool checkNodes(Node *root) {
    if(root == NULL) return true;
    
    if(root->left == NULL && root->right == NULL) return true;
    
    if(root->left == NULL && root->right != NULL) return false;
    
    if(root->left != NULL && root->right == NULL) {
        return (root->data > root->left->data);
    }
    
    bool left = checkNodes(root->left);
    bool right = checkNodes(root->right);
    bool currNode = (root->data > root->left->data) && 
                    (root->data > root->right->data);
    return (left && right && currNode);
}


bool isHeap(Node* root) {
    int n = sizeOfBT(root);
    return isCompleteBT(root, n, 0) && checkNodes(root);
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

	cout << isHeap(root) << endl;

	return 0;
}



