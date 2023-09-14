class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> countArr(n, 1);

        // Left to Right traversal
        for(int i=1; i<n; i++) {
            if(ratings[i-1] < ratings[i]) {
                countArr[i] = countArr[i-1]>=countArr[i] ? countArr[i-1]+1 : countArr[i];
            }
        }

        // Right to Left traversal
        int result = countArr[n-1];
        for(int i=n-2; i>=0; i--) {
            if(ratings[i+1] < ratings[i]) {
                countArr[i] = countArr[i+1]>=countArr[i] ? countArr[i+1]+1 : countArr[i];
                result += countArr[i];
            }
        }

        return result;
    }
};