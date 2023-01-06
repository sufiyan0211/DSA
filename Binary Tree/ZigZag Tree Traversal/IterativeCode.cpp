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

vector<int> zigZagTraversal(Node *root) {
	vector<int> ans;
	queue<Node *> q;
	q.push(root);
	bool leftToRight = true;
	while(!q.empty()) {
	    int width = q.size();
	    vector<int> level(width);
	    for(int i=0;i<width;i++) {
	        root = q.front();
	        q.pop();
	        
	        int index = (leftToRight) ? i : width-i-1;
	        level[index] = root->key;
	        
	        if(root->left) {
	            q.push(root->left);
	        }
	        if(root->right) {
	            q.push(root->right);
	        }
	    }
	    leftToRight = !leftToRight;
	    for(auto ele : level) {
	        ans.push_back(ele);
	    }
	}
	return ans;
}
/* Binary Tree in the input
			10
		   /   \
		 20     30
		/ \     / \
	  40   50  60  70
	  	\		  /
		110		80
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
	root->left->left->right = new Node(110);

	vector<int> ans = zigZagTraversal(root);
	for(auto ele : ans) {
		cout << ele << " ";
	}
	cout << endl;

	return 0;
}