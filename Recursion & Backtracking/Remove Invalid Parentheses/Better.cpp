class Solution {
public:

    int countOfIncorrectParentheses(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')') {
                if(st.empty()) st.push(s[i]);
                else if(st.top() == ')') st.push(s[i]);
                else if(st.top() == '(') st.pop();
            }
            else {
                continue;
            }
        }
        return st.size();
    }

    void util(string s, int start, int minimumRequired, 
                unordered_set<string> &validParentheses) {

        if(minimumRequired == 0) {
            if(countOfIncorrectParentheses(s) == 0) {
                validParentheses.insert(s);
            }
            return;
        }
        
        for(int i=start; i<s.size(); i++) {
            string leftPart = s.substr(0, i);
            string rightPart = s.substr(i+1, s.size()-(i+1));
            util(leftPart + rightPart, i, minimumRequired-1, validParentheses);
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
        unordered_set<string> validParentheses;
        int minimumRequired = countOfIncorrectParentheses(s);
        util(s, 0, minimumRequired, validParentheses);
        return validParenthesesToList(validParentheses);
    }
};