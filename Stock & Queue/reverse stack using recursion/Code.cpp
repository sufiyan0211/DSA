#include<bits/stdc++.h>
using namespace std;


void insertAtTheBottom(stack<int> &s, int value) {
	if(s.empty() == true) {
		s.push(value);
		return;
	}
	else {
		int temp = s.top();
		s.pop();
		insertAtTheBottom(s, value);
		s.push(temp);
	}
}


void reverse(stack<int> &s) {
	if(s.empty() == true) return;
	int temp = s.top();
	s.pop();
	reverse(s);
	insertAtTheBottom(s, temp); 
}


int main() {
	stack<int> s;
	

	int n; cin >>n;
	for(int i=0;i<n;i++) {
		int val; cin >> val;
		s.push(val);
	}
	
	reverse(s);

	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	} cout << endl;

	return 0;
}