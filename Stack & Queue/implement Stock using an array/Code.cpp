#include<bits/stdc++.h>
using namespace std;

#define MAX 100000

class Stack{
private:
	int capacity;
	int topp;
	int arr[MAX];
public:
	Stack() {
		capacity = MAX;
		topp = -1;
	}
	int top() {
		return arr[topp];
	}
	void push(int value) {
		topp++;
		if(topp == capacity){
			cout<< "stack is Overflow\n";
			return;
		} 
		arr[topp] = value;
	}
	int pop() {
		if(topp == -1) {
			cout << "Stack is underflow\n";
		}
		topp--;
		return arr[topp];
	}
	bool empty() {
		if(topp == -1){
			return true;
		}
		return false;
	}
	int size() {
		if(topp == -1) return 0;
		return topp+1;
	}
	
};

int main() {
	int n; cin >> n;
	Stack s;

	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		s.push(x);s
	}

	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	} cout << endl;


	return 0;
}