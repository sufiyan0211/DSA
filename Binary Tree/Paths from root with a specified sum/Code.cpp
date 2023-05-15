class Solution
{
private:
    void recursiveTree(Node *root, vector<int> path, int k, vector<vector<int>> &ans) {
        if(root == NULL) return;

        path.push_back(root->key);

        int size = path.size();
        int sum = 0;
        for(int i=0;i<size;i++) {
            sum += path[i];
        }
        if(sum == k) {
            ans.push_back(path);
        }

        recursiveTree(root->left, path, k, ans);
        recursiveTree(root->right, path, k, ans);
    }
public:
    vector<vector<int>> printPaths(Node *root, int k)
    {
        //code here
        vector<vector<int>> ans;
        vector<int> path;
        recursiveTree(root, path, k, ans);
        return ans;
    }
};