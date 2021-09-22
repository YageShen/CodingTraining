/*
 * @Author: your name
 * @Date: 2021-09-21 20:23:47
 * @LastEditTime: 2021-09-21 21:22:24
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \CodingTraining\LT\HandCodes\LRU.cpp
 */
struct DLinkNode {
    int key, val;
    DLinkNode *prev;
    DLinkNode *next;
    DLinkNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
    DLinkNode(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        cache.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.count(key) > 0) {
            DLinkNode* node = cache[key];
            removeNode(node);
            addToHead(node);
            return node->val;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key) > 0) {
            DLinkNode* node = cache[key];
            node->val = value;
            removeNode(node);
            addToHead(node);
        }
        else {
            DLinkNode* node = new DLinkNode(key, value);
            cache[key] = node;
            addToHead(node);
            size++;
            if(size > cap) {
                deleteTail();
                size--;
            }
        }
    }
private:
    int cap, size;
    unordered_map<int, DLinkNode*> cache;
    DLinkNode* head = new DLinkNode();
    DLinkNode* tail = new DLinkNode();
    
    void addToHead(DLinkNode* node) {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    void removeNode(DLinkNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
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