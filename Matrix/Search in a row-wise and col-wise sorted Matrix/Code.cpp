class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int rows = matrix.size(), cols = matrix[0].size();
        int r = 0, c = cols-1; // starting from top-right
        while(r>=0 && r<rows && c>=0 && c<cols) {
            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] < target) {
                r++;
            }
            else if(matrix[r][c] > target) {
                c--;
            }
        }
        return false;
    }
};