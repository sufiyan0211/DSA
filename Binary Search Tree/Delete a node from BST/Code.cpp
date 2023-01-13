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


Node* minVal(Node* root) {
    Node *minn = root;
    while(minn->left != NULL) {
        minn = minn->left;
    }
    return minn;
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int key) {
    // your code goes here
    if(root == NULL) {
        return root;
    }
    
    if(root->data == key) {
        /* There will 3 cases 
            1. delete leaf node
            2. delete node which has either left or right child
            3. delete node which has both left and right child
        */
        
        // delete leaf node
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        
        // delete node which has either left or right child
        if(root->left != NULL && root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        
        // delete node which has both left and right child
        if(root->left != NULL && root->right != NULL) {
            int minn = minVal(root->right) -> data;
            root->data = minn;
            root->right = deleteNode(root->right, minn); // transform to 0 or 1 child deletion 
            return root;
        }
        
    }
    else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        root->left = deleteNode(root->left, key);
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


	cout << "Delete node 20\n";
	deleteNode(root, 20);
	cout << "Tree after deleting 20\n InorderTraversal\n";
	printTree(root); cout << endl;
	
	return 0;
}