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

// pair(predecessor, successor)
pair<Node*, Node*> findPnD(Node *root, int val) {

	// if(root == NULL) return make_pair(NULL, NULL);

	Node *predecessor=NULL, *successor=NULL;

	// finding predecessor
	Node *curr = root;
	while(curr != NULL) {
		if(curr->data == val) {
			curr = curr->left;
		}
		else if(val < curr->data) {
			curr = curr->left;
		}
		else if(val > curr->data) {
			predecessor = curr;
			curr = curr->right;
		}
	}

	// finding successor
	curr = root;
	while(curr != NULL) {
		if(curr->data == val) {
			curr = curr->right;
		}
		else if(val < curr->data) {
			successor = curr;
			curr = curr->left;
		}
		else if(val > curr->data) {
			curr = curr->right;
		}
	}

	return make_pair(predecessor, successor);

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

	cout << "find predecessor and successor value 90\n";
	pair<Node*, Node*> ans = findPnD(root, 90);

	cout << "predecessor: " << ans.first->data << endl;
	cout << "successor: " << ans.second->data << endl;
	
	return 0;
}
