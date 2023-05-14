class Solution{
    public:
    long long int merge(long long arr[], long long start, long long mid, long long end) {
        long long n1 = mid-start+1;
        long long n2 = end-mid;
        long long int inversion = 0;

        long long a[n1], b[n2];
        long long k = start;
        for(long long i=0; i<n1; i++) a[i] = arr[k++];
        for(long long i=0; i<n2; i++) b[i] = arr[k++];

        long long i=0, j=0;
        k = start;

        while(i<n1 && j<n2) {
            if(a[i] <= b[j]) {
                arr[k++] = a[i++];
            }
            else {
                inversion += (n1-i);
                arr[k++] = b[j++];
            }
        }

        while(i<n1) {
            arr[k++] = a[i++];
        }

        while(j<n2) {
            arr[k++] = b[j++];
        }

        return inversion;
    }

    long long int sorting(long long arr[], long long start, long long end) {
        long long int inversion = 0;
        if(start < end) {
            long long mid = start + (end-start)/2;
            inversion += sorting(arr, start, mid);
            inversion += sorting(arr, mid+1, end);
            inversion += merge(arr, start, mid, end);
        }
        return inversion;
    }

    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        return sorting(arr, 0, n-1);
    }
};