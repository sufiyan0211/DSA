class Solution
{
    public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    int signum(int first, int second) {
        if(first == second) return 0;
        if(first > second) return 1;
        return -1;
    }
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(maxHeap.empty()) {
            maxHeap.push(x);
            return;
        }
        int median = getMedian();
        switch(signum(maxHeap.size(), minHeap.size())) {
            case 0:
                if(x > median) {
                    // insert x into minHeap 
                    minHeap.push(x);
                }
                else {
                    // insert x into maxHeap
                    maxHeap.push(x);
                }
                break;
            case 1:
                if(x > median) {
                    // insert x into minHeap 
                    minHeap.push(x);
                }
                else {
                    // insert x into maxHeap
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(x);
                }
                break;
            case -1:
                if(x > median) {
                    // insert x into minHeap 
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(x);
                }
                else {
                    // insert x into maxHeap
                    maxHeap.push(x);
                }
                break;
        }
    }
    
    double getMedian()
    {
        double median = 0.0;
        if(maxHeap.size() == 0) return median;
        switch(signum(maxHeap.size(), minHeap.size())) {
            case 0:
                median = 1.0 * (maxHeap.top()+minHeap.top()) / 2.0;
                break;
            case 1:
                median = maxHeap.top();
                break;
            case -1:
                median = minHeap.top();
                break;
        }
        return median;
    }
};