#include<bits/stdc++.h>
using namespace std;
#define N 1000

class Node {
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


class compare{
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};



pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
    //code here
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    
    int maxi = INT_MIN, mini = INT_MAX;
    for(int i=0;i<k;i++){
        maxi = max(maxi, arr[i][0]);
        mini = min(mini, arr[i][0]);
        Node * newNode = new Node(arr[i][0], i, 0);
        minHeap.push(newNode);
    }
    
    
    pair<int, int> ans;
    
    ans.first = mini;
    ans.second = maxi;
    
    while(!minHeap.empty()) {
        Node *top = minHeap.top();
        minHeap.pop();
        
        int data = top->data;
        int row = top->row;
        int col = top->col;
        
        mini = data;
        
        if(maxi-mini < ans.second-ans.first) {
            ans.first = mini;
            ans.second = maxi;
        }
        
        if(col+1 < n) {
            maxi = max(maxi, arr[row][col+1]);
            Node* newNode = new Node(arr[row][col+1], row, col+1);
            minHeap.push(newNode);
        }
        else {
            break;
        }
    }
    
    return ans;
}

int main() {
	int n = 5, k = 3;
	int arr[][N] = {{1, 3, 5, 7, 9},
                    {0, 2, 4, 6, 8},
                    {2, 3, 5, 7, 11}};


	pair<int, int> ans = findSmallestRange(arr, n, k);
	cout << ans.first << " " << ans.second << endl;

	return 0;
}


