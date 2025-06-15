class MinStack {
    public:
        stack<int> mainStack;
        stack<int> minStack;
    
        // idea is that both mainStack and minStack will be of same size.
        // Each time I push value in mainStack then I'll push the minElement with respect to that value.
        MinStack() {
            
        }
        
        void push(int val) {
            mainStack.push(val);
            // insert in minStack
            if(minStack.empty()) {
                minStack.push(val);
                return;
            }
    
            if(val < minStack.top()) {
                minStack.push(val);
            }
            else {
                minStack.push(minStack.top());
            }
        }
        
        void pop() {
            // mainStack and minStack will be of same size
            if(mainStack.empty()) return;
    
            mainStack.pop();
            minStack.pop();
        }
        
        int top() {
            if(mainStack.empty()) return -1;
    
            return mainStack.top();
        }
        
        int getMin() {
            if(minStack.empty()) return -1;
    
            return minStack.top();
        }
    };
