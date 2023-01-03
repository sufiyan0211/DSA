// using Auxilary Queue
#include<bits/stdc++.h>
using namespace std;

void interleave(queue<int> &q, int size) {
	queue<int> aq;
	int halfSize = (size >> 1);

	for(int i=0;i<halfSize;i++) {
		aq.push(q.front());
		q.pop();
	}

	while(!aq.empty()) {
		q.push(aq.front());
		aq.pop();
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