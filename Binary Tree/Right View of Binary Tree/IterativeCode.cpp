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

vector<int> leftView(Node *root) {
	queue<Node *> q;
	Node *curr = root;
	q.push(curr);
	vector<int> ans;

	while(!q.empty()) {
		int width = q.size();
		bool first = true;
		while(width--) {
			curr = q.front();
			q.pop();
			if(first == true) {
				ans.push_back(curr->key);
				first = false;
			}
			if(curr->right) {
				q.push(curr->right);
			}
			if(curr->left) {
				q.push(curr->left);
			}
			
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


	vector<int> ans = leftView(root);
	for(auto s: ans) {
		cout << s << " ";
	} cout << endl;

	return 0;
}