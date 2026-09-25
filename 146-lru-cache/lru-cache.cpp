class LRUCache {
public:

    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

    unordered_map<int, Node*> m;
    int limit;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    // Add node just after head
    void addNode(Node* newNode) {
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    // Delete node from linked list
    void deleteNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (m.find(key) == m.end()) {
            return -1;
        }

        Node* ansNode = m[key];

        // Remove from current position
        deleteNode(ansNode);

        // Add at front = recently used
        addNode(ansNode);

        return ansNode->val;
    }

    void put(int key, int value) {

        // Key already exists
        if (m.find(key) != m.end()) {

            Node* oldNode = m[key];

            deleteNode(oldNode);
            m.erase(key);
        }

        // Capacity full
        if (m.size() == limit) {

            Node* oldNode = tail->prev;

            deleteNode(oldNode);

            m.erase(oldNode->key);

            delete oldNode;
        }

        // Add new node at front
        Node* newNode = new Node(key, value);

        addNode(newNode);

        m[key] = newNode;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */