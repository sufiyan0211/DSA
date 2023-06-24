class Node {
public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node (int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class LRUCache {
private:
    int capacity;
    Node *head, *tail;
    unordered_map<int, Node*> mp;
public:
    void deleteNode(Node *target) {
        Node *nodeAfterTarget = target->next;
        Node *nodeBeforeTarget = target->prev;

        nodeAfterTarget->prev = nodeBeforeTarget;
        nodeBeforeTarget->next = nodeAfterTarget;

        // free(target);
    }

    Node* addNodeAfterHead(int key, int value) {
        Node *node = new Node(key, value);

        Node *nodeAfterHead = head->next;

        head->next = node;
        node->prev = head;
        node->next = nodeAfterHead;
        nodeAfterHead->prev = node;
        return node;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;

        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1);

        this->head->next = tail;
        this->tail->prev = head;
    }

    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node *target = mp[key];
            int val = target->value;
            mp.erase(key);

            deleteNode(target);
            Node *node = addNodeAfterHead(key, val);
            mp[key] = node;

            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        // update the value if key already exist in the cache
        if(mp.find(key) != mp.end()) {
            Node *target = mp[key];
            mp.erase(key);
            deleteNode(target);
            Node *node = addNodeAfterHead(key, value);
            mp[key] = node;
        }
        else {
            Node *node = addNodeAfterHead(key, value);
            mp[key] = node;
            if(mp.size() > capacity) {
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
        }
    }
};