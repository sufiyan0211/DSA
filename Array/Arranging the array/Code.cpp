void reverse_array(int arr[], int left, int right) {
    if(left < right) {
        swap(arr[left], arr[right]);
        reverse_array(arr, left++, right--);
    }
}
    
void merge(int arr[], int left, int mid, int right) {
    int leftPartIndex = left;
    int rightPartIndex = mid+1;
    
    // arr[l,r] = {Ln,Lp,Rn,Rp}
    
    // Lp -> arr[leftPartIndex,...,mid]
    while(leftPartIndex <= mid && arr[leftPartIndex] < 0) leftPartIndex++;
    
    // Rp -> arr[rightPartIndex,...,right]
    while(rightPartIndex <= right && arr[rightPartIndex] < 0) rightPartIndex++;
    
    
    // Ln -> arr[left, leftPartIndex-1]
    // Rn -> arr[mid+1, rightPartIndex-1]
    
    // reverse Lp  
    // result = Lp'
    reverse_array(arr, leftPartIndex, mid);
    
    // reverse Rn 
    // result = Rn'
    reverse_array(arr, mid+1, rightPartIndex-1);
    
    // reverse Lp'Rn' 
    // result = RnLp
    reverse_array(arr, leftPartIndex, rightPartIndex-1);
    
}

void rearrangePosNeg(int arr[], int left, int right) {
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    rearrangePosNeg(arr, 0, mid);
    rearrangePosNeg(arr, mid+1, right);
    merge(arr, left, mid, right);
}

void Rearrange(int arr[], int n)
{
    // Your code goes here
    rearrangePosNeg(arr, 0, n-1);
}