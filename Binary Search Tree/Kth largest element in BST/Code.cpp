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
		printTree(root->left);
		cout << root->data << " ";
		printTree(root->right);
	}
}

Node* insert(Node* root, int key) {
    if(root == NULL){
    	root = new Node(key);
        return root;
    }
    if(key < root->data)
    	root->left = insert(root->left, key);
    else if(key > root->data)
    	root->right = insert(root->right, key);
    return root;
}


void findSize(Node *root, int &size) {
    if(root != NULL) {
        findSize(root->left, size);
        size++;
        findSize(root->right, size);
    }
}
   

void traverseInorder(Node *root, int &count, Node* &ans) {
    if(root != NULL) {
        traverseInorder(root->left, count, ans);
        count--;
        if(count == 0) {
            ans = root;
        }
        traverseInorder(root->right, count, ans);
    }
}
    

int kthLargest(Node *root, int k)
{
    int size = 0;
    findSize(root, size);
    int count = size - k + 1;
    Node* ans = NULL;
    traverseInorder(root, count, ans);
    return ans == NULL ? -1 : ans->data;
}



int main() {
	int arr[] = {60,30, 90,20,40,80,110,100,120,130};
	int n = 10; // total nodes 

	Node *root = NULL;
	for(int i=0;i<n;i++) {
		root = insert(root, arr[i]);
	}
	cout << "Printing BST in Inorder Traversal\n";
	printTree(root); cout << endl;

	cout << "3rd Largest Element: ";
	cout << kthLargest(root, 3) << endl;

	return 0;
}