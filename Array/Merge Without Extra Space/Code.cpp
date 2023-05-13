class Solution{
    private:
    int nextGap(int n) {
        if(n <= 1) return 0;
        return (n/2) + (n%2);
    }

    public:
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        int gap = n+m;
        int i,j;
        for(gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {

            for(i=0; i+gap<n; i++) {
                if(arr1[i] > arr1[i+gap]) {
                    swap(arr1[i], arr1[i+gap]);
                }
            }

            for(j= gap>n ? gap-n : 0; i<n && j<m; i++,j++) {
                if(arr1[i] > arr2[j]) {
                    swap(arr1[i], arr2[j]);
                }
            }

            if(j < m) {
                for(j=0;j+gap<m;j++) {
                    if(arr2[j] > arr2[j+gap]) {
                        swap(arr2[j], arr2[j+gap]);
                    }
                }
            }
        }

    }
};