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

void leftTraversal(Node *root, vector<int> &ans) {
    if(root == NULL || (root->left == NULL && root->right == NULL))  
        return;
    ans.push_back(root->key);
    if(root->left) {
        leftTraversal(root->left, ans);
    }
    else {
        leftTraversal(root->right, ans);
    }
}
// preOrderTraversal
void leafTraversal(Node *root, vector<int> &ans) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(root->key);
    }
    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
}

// postorderTraversal
void rightTraversal(Node *root, vector<int> &ans) {
    if(root == NULL || (root->left == NULL && root->right == NULL))  
        return;
        
    if(root->right != NULL) {
        rightTraversal(root->right, ans);
    }
    else {
        rightTraversal(root->left, ans);
    }
    
    ans.push_back(root->key);
}
vector <int> boundary(Node *root)
{
    //Your code here
    vector<int> ans;
    if(root == NULL) return ans;
    
    // store root
    ans.push_back(root->key);
    
    // store left boundries (except: root, leaf Nodes)
    leftTraversal(root->left, ans);
    
    // store left leaf nodes
    leafTraversal(root->left, ans);
    
    // store right leaf nodes
    leafTraversal(root->right, ans);
    
    // store right boundries
    rightTraversal(root->right, ans);
    
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


    vector<int> ans = boundary(root);
    for(auto s: ans) {
        cout << s << " ";
    } cout << endl;

    return 0;
}