class Solution {
    // <height, diameter>
    pair<int, int> diameterUtil(Node* root) {
        if(root == NULL)
        {
            return make_pair(0,0);
        }
        pair<int, int> left = diameterUtil(root->left);
        pair<int, int> right = diameterUtil(root->right);
        
        pair<int, int> ans;
        ans.first = 1+max(left.first, right.first);
        ans.second = max(1+left.first + right.first, max(left.second, right.second));
        return ans;
    }
  public:
  
    int diameter(Node* root) {
        // code here
        return diameterUtil(root).second;
    }
};