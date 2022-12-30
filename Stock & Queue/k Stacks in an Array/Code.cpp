#include <bits/stdc++.h>
using namespace std;

class kStacks {
private:
	int freespot;
	int k;
	int n;
	int *arr;
	int *top;
	int *next;
public:
	kStacks(int n, int k) {
		freespot = 0;
		this->k = k;
		this->n = n;
		arr = new int[n];
		top = new int[k];
		next = new int[n];

		for(int i=0;i<k;i++) top[i] = -1;
		for(int i=0;i<n;i++) next[i] = (i+1);
		next[n-1] = -1;
	}

	bool push(int x, int s) {
		if(freespot == -1) return false; // stack overflow

		int index = freespot;
		arr[index] = x;
		freespot = next[index];
		next[index] = top[s];
		top[s] = index;
		return true;
	}

	int pop(int s) {
		if(top[s] == -1) return -1; // stack underflow

		int index = top[s];
		top[s] = next[index];
		next[index] = freespot;
		freespot = index;

		return arr[index];
	}

};


int main() {
	int n,k; cin >> n >> k;

	kStacks ks(n,k);

	// let ip n=10 and k=3;

	ks.push(15, 2);
    ks.push(45, 2);
  
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
  
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
  
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

	return 0;
}