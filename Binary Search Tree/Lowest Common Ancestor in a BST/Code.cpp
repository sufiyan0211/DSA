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


Node* LCA(Node *root, int n1, int n2)
{
   if(root == NULL) return NULL;
   if(root->data > n1 && root->data > n2) {
       return LCA(root->left, n1, n2);
   }
   if(root->data < n1 && root->data < n2) {
       return LCA(root->right, n1, n2);
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
	cout << "Printing BST in Preorder Traversal\n";
	printTree(root); cout << endl;

	int ans = LCA(root, 80, 130) == NULL ? -1 : LCA(root, 80, 130)->data; 
	cout << ans << endl;

	return 0;
}