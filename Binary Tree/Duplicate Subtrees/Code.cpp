string preorder(Node *root, vector<Node*> &duplicates,
                unordered_map<string, int> &subtreeCount) {
    if(root == NULL) return "N";

    string s = to_string(root->data) + "," +
               preorder(root->left, duplicates, subtreeCount) + "," +
               preorder(root->right, duplicates, subtreeCount);

    if(subtreeCount[s] == 1) {
        duplicates.push_back(root);
    }

    subtreeCount[s]++;

    return s;
}
vector<Node*> printAllDups(Node* root)
{
    // Code here
    vector<Node*> duplicates;
    unordered_map<string, int> subtreeCount;
    preorder(root, duplicates, subtreeCount);
    return duplicates;
}