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
                        int startInOrder, int endInOrder, unordered_map<int, deque<int>> &mp) {
        if(startInOrder > endInOrder) {
            return NULL;
        }
        int element = pre[preOrderIndex++];
        Node *root = new Node(element);

        int positionInInorder = mp[element].front();
        mp[element].pop_back();

        if(mp[element].size() == 0) {
            mp.erase(element);
        }

        root->left = recursiveTree(in, pre, n, preOrderIndex, startInOrder, positionInInorder-1, mp);
        root->right = recursiveTree(in, pre, n, preOrderIndex, positionInInorder+1, endInOrder, mp);

        return root;
    }
public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0;
        unordered_map<int, deque<int>> mp;
        for(int i=0;i<n;i++) {
            mp[in[i]].push_back(i);
        }
        Node *root = recursiveTree(in, pre, n, preOrderIndex, 0, n-1, mp);
        return root;
    }
};