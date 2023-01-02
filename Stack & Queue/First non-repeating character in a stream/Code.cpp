#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string FirstNonRepeating(string str){
	    // Code here
	    string ans = "";
	    queue<char> q;
	    unordered_map<char, int> count;
	    
	    for(int i=0;i<str.size();i++) {
	        // increase the count
	        count[str[i]]++;
	        
	        // push into the queue
	        q.push(str[i]);
	        
	        while(!q.empty()) {
	           
	            if(count[q.front()] > 1) {
	                 // if repeating char then pop
	                 q.pop();
	            }
	            else {
	                // if non-repeating chars then add into ans
	                ans.push_back(q.front());
	                break;
	            }
	        }
	        
	        // if q is empty
	        if(q.empty() == true){
	            ans.push_back('#');
	        }
	    }
	    return ans;
	}
};

int main() {
	string A;
	cin >> A;
	Solution obj;
	string ans = obj.FirstNonRepeating(A);
	cout << ans << "\n";
	
	return 0;
}