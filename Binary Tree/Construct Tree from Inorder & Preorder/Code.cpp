class Solution{
private:
    int findPosition(int in[], int element, int startInOrder, int endInOrder) {
        for(int i=startInOrder;i<=endInOrder;i++) {
            if(in[i] == element) {
                return i;
            }
        }
        return -1;
    }
    Node *recursiveTree(int in[],int pre[], int n, int &preOrderIndex,
                        int startInOrder, int endInOrder, unordered_map<int, queue<int>> &mp) {
        if(startInOrder > endInOrder) {
            return NULL;
        }
        Node *root = new Node(pre[preOrderIndex++]);

        int positionInInorder = mp[root->data].front();
        mp[root->data].pop();

//         if(mp[element].size() == 0) mp.erase(element);

        root->left = recursiveTree(in, pre, n, preOrderIndex, startInOrder, positionInInorder-1, mp);
        root->right = recursiveTree(in, pre, n, preOrderIndex, positionInInorder+1, endInOrder, mp);

        return root;
    }
public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0;
        unordered_map<int, queue<int>> mp;
        for(int i=0;i<n;i++) {
            mp[in[i]].push(i);
        }
        return recursiveTree(in, pre, n, preOrderIndex, 0, n-1, mp);
    }
};
