
void quickSort(vector<int>& arr, int low, int high) {
    // code here
    if(low < high) {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex-1);
        quickSort(arr, partitionIndex+1, high);
    }
}


// Function that takes last element as pivot, places the pivot element at
// its correct position in sorted array, and places all smaller elements
// to left of pivot and all greater elements to right of pivot.
int partition(vector<int>& arr, int low, int high) {
    // code here'
    int pivotElement = arr[low];
    
    // Step 1: put pivot element in its correct position.
    
    int countOfElementLesserThanPivot = 0;
    
    for(int i = low+1; i<=high; i++) {
        if(arr[i]<=pivotElement) countOfElementLesserThanPivot++;
    }
    
    int pivotIndex = low+countOfElementLesserThanPivot;
    swap(arr[low], arr[pivotIndex]);
    
    // Step 2:
    // put elements lesser than pivotElement to left of pivotElement.
    // put elements greater than pivotElement to right of pivotElement.
    
    int i = low, j = high;
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivotElement) i++;
        while(arr[j] > pivotElement) j--;
        
        if(i < j && i < pivotIndex && j > pivotIndex) swap(arr[i++], arr[j--]);
    }
    
    return pivotIndex;
    
}

