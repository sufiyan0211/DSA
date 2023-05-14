class Solution {
    public:
    vector<int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
    {
        //code here.
        vector<int> ans;
        int ptr1 = 0, ptr2 = 0, ptr3 = 0;
        while(ptr1<n1 && ptr2 <n2 && ptr3<n3) {
            if(a[ptr1] == b[ptr2] && a[ptr1] == c[ptr3]) {
                if(!ans.empty() && ans.back() == a[ptr1]) {
                    ptr1++; ptr2++; ptr3++;
                    continue;
                }
                ans.push_back(a[ptr1]);
                ptr1++; ptr2++; ptr3++;
            }
            else if(a[ptr1] <= b[ptr2] && a[ptr1] <= c[ptr3]) {
                ptr1++;
            }
            else if(b[ptr2] <= a[ptr1] && b[ptr2] <= c[ptr3]) {
                ptr2++;
            }
            else if(c[ptr3] <= a[ptr1] && c[ptr3] <= b[ptr2]) {
                ptr3++;
            }
        }
        return ans;
    }
};