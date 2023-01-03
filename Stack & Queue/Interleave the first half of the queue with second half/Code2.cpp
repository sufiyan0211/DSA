// using Auxilary Stack
#include<bits/stdc++.h>
using namespace std;

//Q-> 11 12 13 14 15 16 17 18 19 20
void interleave(queue<int> &q, int size) {
	stack<int> as;
	int halfSize = (size >> 1);

	//  Q-> 16 17 18 19 20
	// AS-> 15 14 13 12 11
	for(int i=0;i<halfSize;i++) {
		as.push(q.front());
		q.pop();
	}

	// Q-> 16 17 18 19 20 15 14 13 12 11 
	while(!as.empty()) {
		q.push(as.top());
		as.pop();
	}

	// Q-> 15 14 13 12 11 16 17 18 19 20
	for(int i=0;i<halfSize;i++) {
		q.push(q.front());
		q.pop();
	}

	//  Q-> 16 17 18 19 20
	// AS-> 11 12 13 14 15
	for(int i=0;i<halfSize;i++) {
		as.push(q.front());
		q.pop();
	}


	//  Q-> 11 16 12 17 13 18 14 19 15 20
	while(!as.empty()) {
		q.push(as.top());
		as.pop();
		q.push(q.front());
		q.pop();
	}

}

int main() {
	int n; cin >> n;
	queue<int> q;
	for(int i=0;i<n;i++) {
		int x; 
		cin >> x;
		q.push(x);
	}
	interleave(q, n);

	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	} cout << endl;
	return 0;
}