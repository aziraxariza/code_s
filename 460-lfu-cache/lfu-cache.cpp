class LFUCache {
public:

    class Node {
    public:
        int key, val, freq;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            val = v;
            freq = 1;
            prev = next = NULL;
        }
    };

    class List {
    public:
        Node *head, *tail;
        int size;

        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;

            size = 0;
        }

        void remove(Node *node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        void insert(Node *node) {
            Node *prevNode = tail->prev;          // insert before tail (MRU)

            prevNode->next = node;
            node->prev = prevNode;

            node->next = tail;
            tail->prev = node;

            size++;
        }
    };

    unordered_map<int, Node*> keyNode;          // key -> node
    unordered_map<int, List*> freqList;         // freq -> DLL

    int cap;
    int minFreq;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(Node *node) {

        int oldFreq = node->freq;

        freqList[oldFreq]->remove(node);        // remove from old freq list

        if (oldFreq == minFreq && freqList[oldFreq]->size == 0)
            minFreq++;                          // smallest freq became empty

        node->freq++;

        if (freqList.find(node->freq) == freqList.end())
            freqList[node->freq] = new List();

        freqList[node->freq]->insert(node);     // insert into new freq list
    }

    int get(int key) {

        if (keyNode.find(key) == keyNode.end())
            return -1;

        Node *node = keyNode[key];

        updateFreq(node);

        return node->val;
    }

    void put(int key, int value) {

        if (cap == 0)
            return;

        if (keyNode.find(key) != keyNode.end()) {

            Node *node = keyNode[key];

            node->val = value;

            updateFreq(node);

            return;
        }

        if (keyNode.size() == cap) {

            List *list = freqList[minFreq];

            Node *victim = list->head->next;    // LRU of minimum frequency

            list->remove(victim);

            keyNode.erase(victim->key);

            delete victim;
        }

        Node *node = new Node(key, value);

        minFreq = 1;

        if (freqList.find(1) == freqList.end())
            freqList[1] = new List();

        freqList[1]->insert(node);

        keyNode[key] = node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */