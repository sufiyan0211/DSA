class Solution {
public:
    void insertAtBottom(stack<int> &st, int element) {
        if(st.empty()) {
            st.push(element);
            return;
        }
        int topp = st.top();
        st.pop();
        // recursive call
        insertAtBottom(st, element);
        st.push(topp);
    }
    
    void Reverse(stack<int> &st) {
        if(st.empty()) {
            return;
        }
        int topp = st.top();
        st.pop();
        // recursive call
        Reverse(st);
        insertAtBottom(st, topp);
    }
};