class LRUCache {
public:
    
    class Node{ // what a node is
    public:
        int key, val; // kya kya it is storing
        Node* prev;
        Node* next;
        Node(int k, int v){
            key = k; // defined everything it it idhar
            val = v;
            prev = next = NULL;
        }

    };

    unordered_map<int, Node*> mp; // key --> node

    Node* head; // for dummy head
    Node* tail; // for dummy tail

    int cap;

    LRUCache(int capacity) { // basically this defines cap, head and tail for the comp. code
        cap = capacity; // cap becomes capacity

        head = new Node(-1, -1); // dummy head
        tail = new Node(-1, -1); // dummy tail

        head->next = tail; // initially next of head tail hai
        tail->prev = head; // initially tail's prev is head
    }

    //1. remove node func
    void remove(Node* node){
        node->prev->next = node->next; // iske peeche ka next ab iska next hai
        node->next->prev = node->prev; // iiske next ka prev iska prev hai
    }

    //2. insert node func
    void insert(Node* node){
        //since we have to add at end we'll use tail's prev as pointer
        Node* prevNode = tail->prev;

        prevNode->next = node; // node ko beech mein dala
        tail->prev = node;

        node->prev = prevNode; // node ke aage peeche wale ptrs added as prevNode and tail
        node->next = tail;
    }
   
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1; // key nahi mili in mp 

        Node* node = mp[key]; // to get pointer to key's node
        remove(node); // hataya jagah se
        insert(node); // add to end

        return node->val;// val leli
    }

    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){ // key alr exists

            Node* node = mp[key]; //update key's node
            node->val = value; // store  the value in node

            remove(node);
            insert(node); // take and push to MRU

            return; // done
        }

        if(mp.size() == cap){ // full hai cache
            Node* lru = head->next;

            remove(lru); // remove lru node
            mp.erase(lru->key); // lru ki key hata do
            delete lru; //lru node del
        }

        Node* node = new Node(key, value); // made new node for this key
        mp[key] = node; // added to our mp to get ptr 
        insert(node);

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */