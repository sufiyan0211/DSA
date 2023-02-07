#include<bits/stdc++.h>
using namespace std;

class Node {
	int key, value, count;
	Node *prev, *next;

	Node(int key, int value) {
		this->key = key;
		this->value = value;
		this->count = 1;
	} 
};

class List {
	int size;
	Node *head, *tail;
	List() {
		head = new Node(0,0);
		tail = new Node(0,0);
		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	void addFront(Node *newNode) {
		Node *nextToHead = head->next;


		newNode->next = nextToHead;
		newNode->prev = head;

		nextToHead->prev = newNode;
		head->next = newNode;

		size++;
	}

	void deleteNode(Node *node) {
		Node *prevNode = node->prev;
		Node *nextNode = node->next;

		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		size--;
	}
};


class LFU{
	map<int, Node*> keyNode;
	map<int, List*> frequencyListMap;
	int capacity;;
	int minFreq;
	int currSize;

	LFU(int capacity) {
		this->capacity = capacity;
		minFreq = 0;
		currSize = 0;
	}

	void updateFreqListMap(Node *node) {
		keyNode.erase(node->key);
		List *oldList = frequencyListMap[node->count];
		oldList->deleteNode(node);

		if(node->count == minFreq && oldList->size == 0) {
			minFreq++;
		}


		List *nextFrequencyList = new List();
		if(frequencyListMap.find(node->count + 1) != frequencyListMap.end()) {
			nextFrequencyList = frequencyListMap[node->count + 1];
		}


		node->count += 1;
		nextFrequencyList->addFront(node);
		frequencyListMap[node->count] = nextFrequencyList;
		keyNode[node->key] = node;
	}

	int get(int key) {
		if(keyNode.find(key) != keyNode.end()) {
			Node *node = keyNode[key];
			int val = node->value;
			updateFreqListMap(node);
			return val;
		}
		return -1;
	}

	void put(int key, int value) {
		if(capacity == 0) return;

		if(keyNode.find(key) != keyNode.end()){
			Node *node = keyNode[key];
			node->value = value;
			updateFreqListMap(node);
			return;
		}
		else {
			if(currSize == capacity) {
				// delete least frequently used node
				List *LFUList = frequencyListMap[minFreq];
				Node *lastElementOfLFUList = LFUList->tail->prev;
				keyNode.erase(lastElementOfLFUList);
				LFUList->deleteNode(lastElementOfLFUList);
				currSize--;
			}
			currSize++;

			minFreq = 1;
			List *newList = new List();
			if(frequencyListMap.find(minFreq) != frequencyListMap.end()) {
				newList = frequencyListMap[minFreq];
			}
			Node *newNode = new Node(key, value);
			newList->addFront(newNode);
			keyNode[key] = newNode;
			frequencyListMap[minFreq] = newList;
		}
	}

};




int main() {



}