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

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    stack <int > s;
    vector<int> ans;
    queue<Node *> q;
    Node *curr = root;
    q.push(curr);

    while(!q.empty()) {
        curr = q.front();
        s.push(curr->key);
        q.pop();
        
        if(curr->right) {
            q.push(curr->right);
        }
        if(curr->left) {
            q.push(curr->left);
        }
       
    }
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
/* Binary Tree in the input
			10
		   /   \
		 20     30
		/ \     / \
	  40   50  60  70
*/

int main() {
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right->left = new Node(60);
	root->right->right = new Node(70);

	vector<int> ans = reverseLevelOrder(root);
	for(auto s: ans) {
		cout << s << " ";
	}
	cout << endl;

	return 0;
}