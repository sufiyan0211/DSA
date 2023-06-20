#include<iostream>
#include <algorithm>
using namespace std;

class Node {
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
    if (root != NULL) {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }
}

Node *insert(Node *root, int key) {
    if (root == NULL) {
        root = new Node(key);
        return root;
    }
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}


Node *findInorderSuccessor(Node *root) {
    Node *pre = root->right;
    while (pre->left != NULL) {
        pre = pre->left;
    }
    return pre;
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int key) {
    // your code goes here
    if (root == NULL) {
        return root;
    }
    /* There will 3 cases
        1. delete leaf node
        2. delete node which has either left or right child
        3. delete node which has both left and right child
    */

    if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (root->data == key) {
        // delete leaf node
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
            // delete node which has either left or right child
        else if (root->left != NULL && root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        } else if (root->left == NULL && root->right != NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
            // delete node which has both left and right child
        else if (root->left != NULL && root->right != NULL) {
            Node *temp = findInorderSuccessor(root);
            swap(root->data, temp->data);
            root->right = deleteNode(root->right, key); // transform to 0 or 1 child deletion
        }

    }

    return root;
}


int main() {
    int arr[] = {60, 30, 90, 20, 40, 80, 110, 100, 120, 130};
    int n = 10; // total nodes

    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    cout << "Printing BST in Inorder Traversal\n";
    printTree(root);
    cout << endl;


    cout << "Delete node 90\n";
    deleteNode(root, 90);
    cout << "Tree after deleting 90\n InorderTraversal\n";
    printTree(root);
    cout << endl;

    return 0;
}