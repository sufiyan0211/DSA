class Node {
    public:
    int key;
    int value;
    Node *prev;
    Node *next;
    
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};


class LRUCache {
  private:
  int capacity;
  Node *head, *tail;
  unordered_map<int, Node*> um;
  int size;
  
  
  void deleteNode(Node *targetNode) {
      Node *nodeBeforeTarget = targetNode->prev;
      Node *NodeAfterTarget = targetNode->next;
      
      nodeBeforeTarget->next = NodeAfterTarget;
      NodeAfterTarget->prev = nodeBeforeTarget;
  }
  
  void addNodeAtStart(Node *newNode) {
      Node *nodeBeforeHead = head->prev;
      
      newNode->prev = nodeBeforeHead;
      nodeBeforeHead->next = newNode;
      
      newNode->next = head;
      head->prev = newNode;
  }
  
  public:
    LRUCache(int cap) {
        // code here
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        
        head->prev = tail;
        tail->next = head;
    }

    int get(int key) {
        // code here
        if(um.find(key) == um.end()) {
            return -1;
        }
        
        Node *targetNode = um[key];
        
        deleteNode(targetNode);
        addNodeAtStart(targetNode);
        
        return targetNode->value;
    }

        
    void put(int key, int value) {
        // if key is already present in unordered_set us
        if(um.find(key) != um.end()) {
            Node *updateNode = um[key];
            
            deleteNode(updateNode);
            
            Node *newNode = new Node(key, value);
            addNodeAtStart(newNode);
            um[key] = newNode;
            return;
        }
        
        Node *newNode = new Node(key, value);
        um[key] = newNode;
        addNodeAtStart(newNode);

        if(um.size() > capacity) {
            um.erase(tail->next->key);
            deleteNode(tail->next);
        }
    }
};