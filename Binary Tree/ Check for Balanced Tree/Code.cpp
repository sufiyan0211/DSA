class Solution{
public:
    //Function to check whether a binary tree is balanced or not.
    // pair<height, balancedOrNot> ans;
    pair<int, bool> recursiveBalanced(Node *root) {
        if(root == NULL) {
            return make_pair(0, true);
        }

        pair<int, bool> left = recursiveBalanced(root->left);
        pair<int, bool> right = recursiveBalanced(root->right);

        pair<int, bool> ans;
        ans.first = 1+max(left.first, right.first);
        ans.second = ( (left.second == true) && (right.second == true)
                       && (abs(left.first - right.first) <= 1) ) ? true : false;

        return ans;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return recursiveBalanced(root).second;
    }
};