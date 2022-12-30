#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    
    bool matching(char c1, char c2) {
        return ( (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}')) ? true : false;
    }
    bool ispar(string str)
    {
        // Your code here
        stack<char> s;
        for(int i = 0;i<str.size();i++) {
            if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
                s.push(str[i]);
            }
            else {
                if(s.empty()) {
                    return false;
                }
                else if(matching(s.top(), str[i]) == true) {
                    s.pop();
                }
                else {
                    return false;
                }
            }
        }
        
        if(s.empty() == false) return false;
        return true;
    }

};


int main()
{
   string a;
   cin>>a;
   Solution obj;
   if(obj.ispar(a))
    cout<<"balanced"<<endl;
   else
    cout<<"not balanced"<<endl;
}