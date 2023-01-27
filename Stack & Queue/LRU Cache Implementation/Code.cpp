#include <bits/stdc++.h>
using namespace std;

class Cache {
public:

	class Node{
	public:
		int key;
		int val;
		Node *prev;
		Node *next;

		Node(int key, int val) {
			this->key = key;
			this->val = val;
			prev = NULL;
			next = NULL;
		}

	};

	int capacity;
	unordered_map<int, Node*> mp;

	Node* head = new Node(-1, -1);
	Node* tail = new Node(-1, -1);

	Cache(int capacity) {
		this->capacity = capacity;
		head->next = tail;
		tail->prev = head;
	}

	void addElementAfterHead(int key, int val) {
		Node *newNode = new Node(key, val);
		mp[key] = newNode;

		Node *nextOfHead = head->next;

		newNode->prev = head;
		newNode->next = nextOfHead;

		nextOfHead->prev = newNode;

		head->next = newNode;
		mp[key] = newNode;
	}


	void deleteElement(Node *targetNode) {
		Node *NodeBeforeTarget = targetNode->prev;
		Node *NodeAfterTarget = targetNode->next;

		NodeBeforeTarget->next = NodeAfterTarget;
		NodeAfterTarget->prev = NodeBeforeTarget;
	}

	void put(int key, int val) {
		if(mp.size() >= capacity) {
			// delete the last element from DLL (element just before the tail) and also erase it from map
			mp.erase(tail->prev->key);
			deleteElement(tail->prev);

			// Add element after head
			addElementAfterHead(key, val);

		}
		else {
			// add element after head;
			addElementAfterHead(key, val);

		}
	}

	int get(int key) {
		if(mp.find(key) != mp.end()) {
			Node *targetNode = mp[key];
			int val = targetNode->val;

			mp.erase(key);
			deleteElement(targetNode);

			addElementAfterHead(key, val);
			return val;
		}
		else {
			return -1;
		}
	}


};


int main() {
	Cache cache(2);

	cache.put(1,1);
	cache.put(2,2);
	cout << cache.get(1) << endl;
	cache.put(3,3);
	cout<< cache.get(2) << endl;
	cache.put(4,4);
	cout<< cache.get(1) << endl;
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;


	return 0;
}