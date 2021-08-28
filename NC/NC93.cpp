struct DLinkNode {
    int key, val;
    DLinkNode *prev;
    DLinkNode *next;
    DLinkNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
    DLinkNode(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        vector<int> ret;
        head->next = tail;
        tail->prev = head;
        capacity = k;
        for(auto op : operators) {
            if(op[0] == 1) {
                set(op[1], op[2]);
            }
            else {
                ret.push_back(get(op[1]));
            }
        }
        return ret;
    }
    
private:
    DLinkNode *head = new DLinkNode();
    DLinkNode *tail = new DLinkNode();
    unordered_map<int, DLinkNode*> cache;
    int size = 0;
    int capacity = 0;
    void set(int key, int val) {
        if(cache.count(key) != 0) {
            DLinkNode* node = cache[key];
            node->val = val;
            removeNode(node);
            addToHead(node);
        }
        else {
            DLinkNode* node = new DLinkNode(key, val);
            cache.insert(pair<int, DLinkNode*>(key, node));
            addToHead(node);
            ++size;
            if(size > capacity) {
                deleteTail();
                --size;
            }
        }
    }
    int get(int key) {
        if(cache.count(key) != 0) {
            DLinkNode* node = cache[key];
            removeNode(node);
            addToHead(node);
            return node->val;
        }
        else
            return -1;
    }
    void removeNode(DLinkNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addToHead(DLinkNode* node) {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    void deleteTail() {
        DLinkNode* node = tail->prev;
        if(node != head) {
            node->prev->next = tail;
            tail->prev = node->prev;
            cache.erase(node->key);
            delete node;
        }
    }
    
};