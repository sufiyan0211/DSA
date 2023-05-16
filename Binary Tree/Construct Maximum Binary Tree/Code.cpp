class Solution {
private:
    int findMax(vector<int> &nums, int start, int end) {
        int maxi = nums[start];
        int position = start;
        for(int i=start; i<=end; i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
                position = i;
            }
        }
        return position;
    }

    TreeNode *constructTree(vector<int> &nums, int start, int end) {
        if(start > end) return NULL;
        int position = findMax(nums, start, end);

        TreeNode *node = new TreeNode(nums[position]);

        if(start == end) return node;

        node->left = constructTree(nums, start, position-1);
        node->right = constructTree(nums, position+1, end);

        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(nums, 0, nums.size()-1);
    }
};