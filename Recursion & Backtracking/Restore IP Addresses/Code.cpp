class Solution {
public:
    bool isValid(string s) {
        if(s[0] == '0') return false;

        int stringInt = stoi(s);

        return stringInt<=255;
    }

    void restoreIpAddresses(int currIdx, string currStr, int part, string s, vector<string> &validIps, int n) {
        if(currIdx == n && part == 4) {
            currStr.pop_back(); // poping ending dot
            validIps.push_back(currStr);
            return;
        }

        if(part == 4) return;

        if(currIdx+1 <= n) 
            restoreIpAddresses(currIdx+1, currStr + s.substr(currIdx, 1) + ".", part+1, s, validIps, n);

        if(currIdx+2 <= n && isValid(s.substr(currIdx, 2))) 
            restoreIpAddresses(currIdx+2, currStr + s.substr(currIdx, 2) + ".", part+1, s, validIps, n);

        if(currIdx+3 <= n && isValid(s.substr(currIdx, 3))) 
            restoreIpAddresses(currIdx+3, currStr + s.substr(currIdx, 3) + ".", part+1, s, validIps, n);                                      
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> validIps;
        if(s.size() > 12 || s.size() < 4) return validIps;

        restoreIpAddresses(0, "", 0, s, validIps, s.size());

        return validIps;
    }
};