#include<bits/stdc++.h>
using namespace std;


string solve(int arr[], int n) {
    // code here
    string a, b;
    sort(arr, arr+n);
    
    for(int i=0;i<n;i+=2){
        a+=(arr[i]+'0');
    }
    
    for(int i=1;i<n;i+=2){
        b+=(arr[i]+'0');
    }
    string ans;
    // return a+'-'+b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    int i=0;
    int j=0;
    int carry=0;
    int val;
	while(i< a.length() and j<b.length()){
	    val=((a[i] - '0') + (b[j] -'0') + carry)%10;
	    int temp=(a[i] - '0') + (b[j] -'0') + carry;
	    ans+=to_string(val);
	    carry=temp/10;
	    i++;
	    j++;
	}

	while(i<a.length()){
	    val=((a[i] - '0')  + carry)%10;
	    int temp=(a[i] - '0')  + carry;
	    ans+=to_string(val);
	    carry=temp/10;
	    i++;
	}
	while(j<b.length()){
	    val=((b[j] - '0')  + carry)%10;
	    int temp=(b[j] - '0')  + carry;
	    ans+=to_string(val);
	    carry=temp/10;
	    j++;
	}
	if(carry>=1)
	    ans+= to_string(carry);
	i=ans.length()-1;
	while(ans[i]=='0'){
	    ans.pop_back();
	    i--;
	}
	reverse(ans.begin(), ans.end());
   	return ans;
}



int main() {
	int n = 6;
	int arr[] = {6, 8, 4, 5, 2, 3};
	string ans = solve(arr, n);
	cout << ans << endl;

	return 0;
}






