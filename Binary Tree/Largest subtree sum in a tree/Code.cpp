class Solution {
  public:
    // Function to find largest subtree sum.
    
    
    int traverse(Node *root, int &ans) {
        if(root == NULL) return 0;
        int sum = root->data + traverse(root->left, ans) + traverse(root->right, ans);
        ans = max(ans, sum);
        return sum;
    }
    
    
    int findLargestSubtreeSum(Node* root) {
        // Write your code here
        if(root == NULL) return 0;
        int ans = INT_MIN;
        traverse(root, ans);
        return ans;
    }
};