class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0 || n == 1) return n;

        int left = 0, right = 0;
        int ans = 0;

        unordered_map<char, int> uniques;

        while (left < n && right < n) {
            int len = 0;
            if (uniques.find(s[right]) == uniques.end()) {
                uniques[s[right]] = right;
                len = right - left + 1;
                right++;
            } else {
                if (uniques[s[right]] < left) {
                    uniques[s[right]] = right;
                    len = right - left + 1;
                    right++;
                } else {
                    left = uniques[s[right]] + 1;
                    uniques[s[right]] = right;
                    right++;
                }
            }
            ans = max(ans, len);
        }
        return ans;
    }
};