//User function template in C++

class Solution
{
public:
    int countStudent(int A[], int N, int mid) {
        int students = 1;
        int pagesPerStudent = 0;
        for(int i=0; i<N; i++) {
            if(pagesPerStudent + A[i] <= mid) {
                pagesPerStudent += A[i];
            }
            else {
                students++;
                pagesPerStudent = A[i];
            }
        }
        return students;
    }

    int findPages(int A[], int N, int M)
    {
        if(M > N) return -1;
        int sum = 0;
        int maxElement = A[0];
        for(int i=0;i<N;i++) {
            maxElement = max(maxElement, A[i]);
            sum += A[i];
        }

        int low = maxElement;
        int high = sum;

        while(low <= high) {
            int mid = (low+high)/2;
            int studentCount = countStudent(A, N, mid);
            /*
            studentCount is more at 'low' and it is lesser at 'high'
            */
            if(studentCount > M) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};