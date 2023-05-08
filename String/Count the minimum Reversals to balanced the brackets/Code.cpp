int countRev(string s)
{
    // your code here
    int n = s.size();
    if(n&1) return -1;  // if odd
    int count = 0;
    int open = 0, close = 0;
    stack<char> st;
    for(int i=0; i<n; i++) {
        if(s[i] == '{') {
            st.push(s[i]);
            open++;
        }
        else if(s[i] == '}' && !st.empty() && st.top() == '{') {
            st.pop();
            open--;
        }
        else {
            close++;
        }
    }
    if(open&1) open = (open/2)+1;   // if odd
    else open = open/2;

    if(close&1) close = (close/2)+1;   // if odd
    else close = close/2;

    return open+close;
}