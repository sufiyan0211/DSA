#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    int row;
    int col;
    
    Node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare {
    public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    //code here
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    for(int i=0;i<k;i++) {
        Node *newNode = new Node(arr[i][0], i, 0);
        minHeap.push(newNode);
    }
    
    vector<int> ans;
    while(!minHeap.empty()) {
        Node *top = minHeap.top();
        
        ans.push_back(top->data);
        
        minHeap.pop();
        
        int row = top->row;
        int col = top->col;
        
        if(col+1 < arr[row].size()) {
            Node *newNode = new Node(arr[row][col+1], row, col+1);
            minHeap.push(newNode);
        }
        
    }
    return ans;
}


int main() {
	int k = 3;
	int n = 3;
	vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
	vector<int> ans = mergeKArrays(arr, k);
	for(auto x: ans) {
		cout << x << " ";
	} cout << endl;

	return 0;
}




