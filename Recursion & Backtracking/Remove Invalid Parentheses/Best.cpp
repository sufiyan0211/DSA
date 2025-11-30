class Solution {
public:

    bool isValid(string s) {
        int bal = 0;
        for (char c : s) {
            if (c == '(') bal++;
            else if (c == ')') bal--;
            if (bal < 0) return false;
        }
        return bal == 0;
    }

    void util(string s, int start, int open, int close, 
                unordered_set<string> &validParentheses) {

        if(open == 0 && close == 0) {
            if(isValid(s)) validParentheses.insert(s);
            return;
        }
        
        for(int i=start; i<s.size(); i++) {
            string leftPart = s.substr(0, i);
            string rightPart = s.substr(i+1);
            if(open > 0 && s[i] == '(')
                util(leftPart + rightPart, i, open-1, close, validParentheses);
            if(close > 0 && s[i] == ')')
                util(leftPart + rightPart, i, open, close-1, validParentheses);
        }
    }

    vector<string> validParenthesesToList(unordered_set<string> &validParentheses) {
        vector<string> validParenthesesList;
        for(auto &validParenthese : validParentheses) {
            validParenthesesList.push_back(validParenthese);
        }
        return validParenthesesList;
    }

    vector<string> removeInvalidParentheses(string s) {

        int open = 0;
        int close = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') open++;
            else if(s[i] == ')') {
                if(open != 0) open--; // balanced 
                else close++; // imbalance
            }
            else continue; // ignore non-parentheses characters
        }

        unordered_set<string> validParentheses;

        util(s, 0, open, close, validParentheses);
        return validParenthesesToList(validParentheses);
    }
};