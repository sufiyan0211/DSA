void insertInSortedStack(stack<int> &s, int element) {
    if(s.empty() || (s.top() <= element)) {
        s.push(element);
        return;
    }
    
    int topp = s.top();
    s.pop();
    
    // recursive call
    insertInSortedStack(s, element);
    
    s.push(topp);
}


void sortStack(stack<int> &s) {
    // Your code here
    if(s.empty()) {
        return;
    }
    
    
    int topp = s.top();
    s.pop();
    
    // recursive call
    sortStack(s);
    
    insertInSortedStack(s, topp);
}
