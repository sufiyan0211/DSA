class Solution{ 
public:
    int minJumps(int arr[], int n) {
        // Your code here
        if(n == 1) return 0;
        if(arr[0] == 0) return -1;

        int maxReach = arr[0];
        int steps = arr[0];
        int jump = 1;

        for(int i=1;i<n;i++) {
            if(i == n-1) return jump;
            maxReach = max(maxReach, i+arr[i]);
            steps--;
            if(steps == 0) {
                if(maxReach <= i) {
                    return -1;
                }
                jump++;
                steps = maxReach - i;
            }
        }
        
        return -1;
    }
};