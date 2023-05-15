class Solution
{
private:
    // pair<height, sum>
    pair<int, int> recursiveTree(Node *root) {
        if(root == NULL) {
            return make_pair(0,0);
        }
        if(root->left == NULL && root->right == NULL) {
            return  make_pair(1, root->data);
        }

        pair<int, int> left = recursiveTree(root->left);
        pair<int, int> right = recursiveTree(root->right);

        pair<int, int> ans;
        if(left.first ==  right.first) {
            ans.first = 1+left.first; // 1+right.first
            ans.second = max(left.second, right.second) + root->data;
        }
        else if(left.first > right.first) {
            ans.first = 1+left.first;
            ans.second = left.second + root->data;
        }
        else {
            ans.first = 1+right.first;
            ans.second = right.second + root->data;
        }

        return ans;
    }
public:

    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        return recursiveTree(root).second;
    }
};