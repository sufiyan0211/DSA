class Solution {
    // return height
    int diameterUtil(Node* root, int &d) {
        if(root == NULL)
        {
            return 0;
        }
        int lh = diameterUtil(root->left, d);
        int rh = diameterUtil(root->right, d);
        
        d = max(1+lh+rh, d);
       
        return 1+max(lh, rh);
    }
  public:
      int diameter(Node* root) {
        // code here
        int d = 0;
        diameterUtil(root,d);
        return d;
    }
};