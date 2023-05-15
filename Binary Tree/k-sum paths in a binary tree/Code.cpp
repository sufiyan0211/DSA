class Solution{
private:
    void recursiveTree(Node *root, vector<int> path, int& count, int k) {
        if(root == NULL) return;

        path.push_back(root->data);

        int size = path.size();
        int sum = 0;
        for(int i=size-1;i>=0;i--) {
            sum += path[i];
            if(sum == k) {
                count++;
            }
        }

        recursiveTree(root->left, path, count, k);
        recursiveTree(root->right, path, count, k);



    }

public:
    int sumK(Node *root,int k)
    {
        // code here
        vector<int> path;
        int count = 0;
        recursiveTree(root, path, count, k);
        return count;
    }
};