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

class Solution {
  public:
  
    void leftTraversal(Node *root, vector<int> &ans) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return;
        
        ans.push_back(root->data);
        
        if(root->left) leftTraversal(root->left, ans);
        else leftTraversal(root->right, ans);
    }
    
    void leafTravesal(Node *root, vector<int> &ans) {
        if (root == NULL) return;
        
        if(root->left == NULL && root->right == NULL) ans.push_back(root->data);
        
        leafTravesal(root->left, ans);
        leafTravesal(root->right, ans);
    }
    
    
    void rightTraversal(Node *root, stack<int> &rightNodesStack) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return;
        
        rightNodesStack.push(root->data);
        
        if(root->right) rightTraversal(root->right, rightNodesStack);
        else rightTraversal(root->left, rightNodesStack);
    }
    
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        
        if (root == NULL) return ans;
        
        // This for to handle [1 N N]
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return ans;
        }
        
        // push root ka data
        ans.push_back(root->data);
        
        leftTraversal(root->left, ans);
        leafTravesal(root, ans);
        
        stack<int> rightNodesStack;
        rightTraversal(root->right, rightNodesStack);
        
        while(!rightNodesStack.empty()) {
            ans.push_back(rightNodesStack.top());
            rightNodesStack.pop();
        }
        
        return ans;
    }
};
