class Solution{
public:
    void insertAtBottom(stack<int> &s, int topper) {
        if(s.empty() == true) {
            s.push(topper);
        }
        else {
            int nextTopper = s.top();
            s.pop();
            insertAtBottom(s, topper);
            s.push(nextTopper);
        }
    }
    void Reverse(stack<int> &s){
        
        if(s.empty()) return;
        
        int topper = s.top();
        s.pop();
        
        Reverse(s);
        
        insertAtBottom(s, topper);
    }
};