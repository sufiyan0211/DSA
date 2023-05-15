class Solution
{
private:
    // pair => <sum, sumEqualOrNot>
    pair<int, bool> recursiveTree(Node* root) {
        if(root == NULL) {
            return make_pair(0, true);
        }
        if(root->left == NULL && root->right == NULL) {
            return make_pair(root->data, true);
        }
        pair<int, bool> left = recursiveTree(root->left);
        pair<int, bool> right = recursiveTree(root->right);

        pair<int, bool> ans;
        ans.first = root->data + left.first + right.first;
        ans.second = (left.second && right.second && (left.first + right.first == root->data )) ? true : false;
        return ans;
    }
public:
    bool isSumTree(Node* root)
    {
        // Your code here
        return recursiveTree(root).second;

    }
};