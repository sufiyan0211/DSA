class Solution
{
private:
    stack<int> deleteMidEle(stack<int> s, int size, int curr) {
        if(s.empty() == true) return s;

        int top = s.top();
        s.pop();
        stack<int> temp = deleteMidEle(s, size, curr+1);

        if(curr != (size/2)) {
            temp.push(top);
        }
        return temp;
    }

public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        s = deleteMidEle(s, sizeOfStack, 0);
    }
};