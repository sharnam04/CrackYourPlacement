class LRUCache {
public:
    class Node {
    public:
        int key;int value;
        Node* prev;
        Node* next;
        Node(int _key, int _val) {
            key = _key;
            value = _val;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mpp;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void insertAfterHead(Node* newnode) {
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;

        int val = mpp[key]->value;
        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        mpp[key]=head->next;
        return val;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->value = value;
            mpp.erase(key);
            deleteNode(node);
        }
        if (mpp.size() == cap) {
            Node* node = tail->prev;
            mpp.erase(node->key);
            deleteNode(node);
        }
        Node* Newnode = new Node(key, value);
        mpp[key] = Newnode;
        insertAfterHead(Newnode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */