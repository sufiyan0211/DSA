class Solution {
private:
    Node* findTargetNode(Node *root, int target,
                         unordered_map<Node*, Node*> &parentOfNode) {

        if(root == NULL) return NULL;
        Node *targetNode = NULL;
        queue<Node*> q;
        q.push(root);
        parentOfNode[root] = NULL;

        while(!q.empty()) {
            Node *curr = q.front();
            q.pop();
            if(curr->data == target) {
                targetNode = curr;
            }
            if(curr->left) {
                parentOfNode[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right) {
                parentOfNode[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return targetNode;
    }

    int burnTree(Node *root, unordered_map<Node*, Node*> parentOfNode) {
        queue<Node*> q;
        unordered_map<Node*, bool> visited;
        q.push(root);
        visited[root] = true;
        int timer = 0;
        while(!q.empty()) {
            int size = q.size();
            bool flag = false;
            for(int i=0;i<size;i++) {
                root = q.front();
                q.pop();
                if(root->left != NULL && visited[root->left] == false) {
                    q.push(root->left);
                    visited[root->left] = true;
                    flag = true;
                }
                if(root->right != NULL && visited[root->right] == false) {
                    q.push(root->right);
                    visited[root->right] = true;
                    flag = true;
                }
                if(parentOfNode[root] != NULL && visited[parentOfNode[root]] == false){
                    q.push(parentOfNode[root]);
                    visited[parentOfNode[root]] = true;
                    flag = true;
                }
            }
            if(flag == true) timer++;
        }
        return timer;
    }

public:
    int minTime(Node* root, int target)
    {
        // Your code goes here
        // step1: find the parent of every nodes
        // step2: find the targetNode
        // step3: burn the tree from target node

        unordered_map<Node*, Node*> parentOfNode;
        Node *targetNode = findTargetNode(root, target, parentOfNode);
        if(targetNode == NULL) return -1;
        int ans = burnTree(targetNode, parentOfNode);
        return ans;
    }
};