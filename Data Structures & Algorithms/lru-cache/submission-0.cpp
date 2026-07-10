struct DLNode {
    DLNode* next;
    DLNode* prev;
    int key;
    int val;
    DLNode():key(0),val(0),next(nullptr),prev(nullptr) {}
    DLNode(int key,int val):key(key),val(val),next(nullptr),prev(nullptr) {}
};

class LRUCache {
public:

    unordered_map<int,DLNode*> hmap;
    int capacity;
    DLNode* head;
    DLNode* tail;

    void remove(DLNode* node) {
        DLNode* prev = node->prev;
        DLNode* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
    void insert(DLNode* node) {
        DLNode* prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;
    }
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        hmap.clear();
        head = new DLNode(0,0);
        tail = new DLNode(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(hmap.find(key) == hmap.end()) return -1;

        remove(hmap[key]);
        insert(hmap[key]);
        
        return hmap[key]->val;
    }
    
    void put(int key, int value) {
        if(hmap.find(key) != hmap.end()) { //if key is found in the hmap
            remove(hmap[key]);
        }
        DLNode* newNode = new DLNode(key, value); //make new node
        hmap[key] = newNode;
        insert(newNode);

        if(hmap.size() > capacity) {
            DLNode* recent = head->next;
            remove(recent);
            hmap.erase(recent->key);
            delete recent;
        }

    }
};
