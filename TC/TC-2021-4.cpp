#include <iostream>

using namespace std;

struct LinkNode{
    int val;
    struct LinkNode* next;
    LinkNode(int x) : val(x), next(nullptr) {}
};

class queue {
public:
    queue() {
        size = 0;
        head->next = nullptr;
        tail->next = nullptr;
    }
    void push(int x) {
        LinkNode* node = new LinkNode(x);
        if(size > 0) {
            tail->next->next = node;
            tail->next = node;
        }
        else {
            head->next = node;
            tail->next = node;
        }
        ++size;
    }
    int pop() {
        if(size > 0) {
            LinkNode* node = head->next;
            head->next = node->next;
            delete node;
            --size;
            return 1;
        }
        else
            return -1;
    }
    void clear() {
        while(head->next) {
            LinkNode* node = head->next;
            head->next = node->next;
            delete node;
        }
        tail->next = nullptr;
        size = 0;
    }
    int top() {
        if(size > 0)
            return head->next->val;
        else
            return -1;
    }
    int getSize() {
        return size;
    }
    
private:
    int size = 0;
    LinkNode* head = new LinkNode(0);
    LinkNode* tail = new LinkNode(0);
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        queue myQueue;
        int Q;
        cin >> Q;
        while(Q--) {
            string op;
            cin >> op;
            if(op == "PUSH") {
                int val;
                cin >> val;
                myQueue.push(val);
            }
            else if(op == "TOP") {
                cout << myQueue.top() <<endl;
            }
            else if(op == "POP") {
                if(myQueue.pop() == -1)
                    cout << -1 << endl;
            }
            else if(op == "SIZE") {
                cout << myQueue.getSize() << endl;
            }
            else if(op == "CLEAR") {
                myQueue.clear();
            }
        }
    }
    return 0;
}