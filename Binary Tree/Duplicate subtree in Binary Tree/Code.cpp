class Solution {
private:
    string preOrder(Node *root, int &count,
                    unordered_map<string, int> &subtreeCount) {
        if(root == NULL) return "N";

        string s = to_string(root->data) + "," +
                   preOrder(root->left, count, subtreeCount) + "," +
                   preOrder(root->right, count, subtreeCount);

        if(subtreeCount[s] == 1. && !(root->left == NULL && root->right == NULL)) {
            count++;
        }

        subtreeCount[s]++;
        return s;
    }
public:
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false */
    int dupSub(Node *root) {
        // code here
        int count = 0;
        unordered_map<string, int> subtreeCount;
        preOrder(root, count, subtreeCount);

        return count;
    }
};
