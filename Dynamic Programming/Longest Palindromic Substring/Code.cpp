class Solution {
private:
    /*
    @return <startIdx, endIdx>
    */
    pair<int, int> explorePalindrome(string s, int start, int end, int n,
                                     int &maxLen, int &startIdx, int &endIdx) {
        while (start >= 0 && end < n && s[start] == s[end]) {
            int len = end - start + 1;
            if (len > maxLen) {
                maxLen = len;
                startIdx = start, endIdx = end;
            }
            start--;
            end++;
        }
        return make_pair(startIdx, endIdx);
    }

    string formString(int startIdx, int endIdx, string s) {
        string ans = "";
        for (int i = startIdx; i <= endIdx; i++) {
            ans += s[i];
        }
        return ans;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;
        int startIdx = 0, endIdx = 0;
        for (int i = 0; i < n; i++) {

            // for odd length palindrome
            int start = i, end = i;
            pair<int, int> indices = explorePalindrome(s, start, end, n, maxLen, startIdx, endIdx);
            startIdx = indices.first, endIdx = indices.second;

            // for even length palindrome
            start = i, end = i + 1;
            indices = explorePalindrome(s, start, end, n, maxLen, startIdx, endIdx);
            startIdx = indices.first, endIdx = indices.second;
        }
        return formString(startIdx, endIdx, s);
    }
};










