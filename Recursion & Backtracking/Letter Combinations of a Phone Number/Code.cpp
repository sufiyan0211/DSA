class Solution {
public:
    void letterCombinations(int index, string currString, string digits, 
        unordered_map<char, string> &digitsMap, 
        vector<string> &ans) {

        if(index == digits.size()) {
            ans.push_back(currString);
            return;
        }

        string str = digitsMap[digits[index]];
        for(int i=0; i<str.size(); i++) {
            letterCombinations(index+1, currString+str[i], digits, digitsMap, ans);
        }

    }

    vector<string> letterCombinations(string digits) {

        unordered_map<char, string> digitsMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> ans;
        letterCombinations(0, "", digits, digitsMap, ans);
        return ans;
    }
};