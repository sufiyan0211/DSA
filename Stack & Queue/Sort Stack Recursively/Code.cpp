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

void insertAtCorrectPos(stack<int> &s, int val) {
    if(s.empty() == true || val >= s.top()) {
        s.push(val);
    }
    else {
        int temp = s.top();
        s.pop();
        insertAtCorrectPos(s, val);
        s.push(temp);
    }
}

void sort(stack<int> &s) {
	if(s.empty() == true) return; 
	int temp = s.top();
	s.pop();
	sort(s);
	insertAtCorrectPos(s,temp);
}


int main() {
	stack<int> s;

	int n; cin >>n;
	for(int i=0;i<n;i++) {
		int val; cin >> val;
		s.push(val);
	}
	
	sort(s);

	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	} cout << endl;

	return 0;
}