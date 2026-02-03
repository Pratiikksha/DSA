class Node {
public:
    int key, value;
    Node* prev;
    Node* next;
    Node(int m, int n) {
        key = m;
        value = n;
        prev = next = NULL;
    }
};
class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp;
    Node* tail;
    Node* head;
    LRUCache(int capacity) {
        cap = capacity;
        tail = new Node(-1, -1);
        head = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (mp.count(key) == 0)
            return -1;
        Node* node = mp[key];
        remove(node);
        insertAtHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->value = value;
            remove(node);
            insertAtHead(node);
        } else {
            if (mp.size() == cap) {
                Node* lru = tail->prev;
                mp.erase(lru->key);
                remove(lru);
                delete (lru);
            }
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            insertAtHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */