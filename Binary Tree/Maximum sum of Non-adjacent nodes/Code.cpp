class Solution{
    // pair<int, int> => <including current node, excluding current node>
private:
    pair<int, int> RecursiveTree(Node *root) {
        if(root == NULL) {
            return make_pair(0,0);
        }

        pair<int, int> left = RecursiveTree(root->left);
        pair<int, int> right = RecursiveTree(root->right);

        pair<int, int> ans;
        // including root
        ans.first = root->data + left.second + right.second;
        // excluding root
        ans.second = max(left.first, left.second) + max(right.first, right.second);
        return ans;
    }
public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root)
    {
        // Add your code here
        pair<int, int> p;
        p = RecursiveTree(root);
        return max(p.first, p.second);
    }
};