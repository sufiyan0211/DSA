class Solution {
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n) {
        vector<long long> previousSmaller(n);
        previousSmaller[0] = -1;
        stack<long long> st1;
        st1.push(0);
        for (int i = 1; i < n; i++) {
            while (!st1.empty() && arr[st1.top()] >= arr[i]) {
                st1.pop();
            }
            previousSmaller[i] = st1.empty() ? -1 : st1.top();
            st1.push(i);
        }

        vector<long long> nextSmaller(n);
        nextSmaller[n - 1] = n;
        stack<long long> st2;
        st2.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (!st2.empty() && arr[st2.top()] >= arr[i]) {
                st2.pop();
            }
            nextSmaller[i] = st2.empty() ? n : st2.top();
            st2.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long currMax = (nextSmaller[i] - previousSmaller[i] - 1) * arr[i];
            ans = max(ans, currMax);
        }
        return ans;
    }
};
