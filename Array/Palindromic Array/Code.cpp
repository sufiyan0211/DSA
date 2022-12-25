#include<iostream>
#include<string.h>
using namespace std;


class Solution {
public:
    int pow(int base, int expo) {
        int product = 1;
        for(int i=0;i<expo;i++) {
            product = product * base;
        }
        return product;
    }
    
    bool checkPalindromeNumber(int n) {
        int countOfDigit = 0;
        int temp = n;
        while(temp != 0) {
            temp /= 10;
            countOfDigit++;
        }
        
        temp = n;
        int sum = 0;
        countOfDigit--;
        while(temp!=0) {
            int lastDigit = temp % 10;
            sum += lastDigit* pow(10, countOfDigit);
            countOfDigit--;
            temp /= 10;
        }
        return sum==n ? true : false;
    }
    int PalinArray(int arr[], int n)
    {
    	for(int i=0;i<n;i++) {
    	    if(!checkPalindromeNumber(arr[i])) return false;
    	}
    	return true;
    }
};


int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin>>a[i];
	Solution obj;
	cout<<obj.PalinArray(a,n)<<endl;
	
}
