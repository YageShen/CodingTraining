struct LinkNode {
    int val;
    struct LinkNode* next;
    LinkNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if(m <= 0 || n <= 0) {
            return -1;
        }
        ListNode* head = new ListNode(0);
        ListNode* tail = nullptr;
        ListNode* pre = head;
        for(int i(1); i < n; ++i) { // build link
            tail = new ListNode(i);
            pre->next = tail;
            pre = tail;
        }
        tail->next = head;
        
        ListNode* node = head;
        while(n != 1) {
            for(int i = 1; i < m - 1; ++i) {
                node = node->next;
            }
            ListNode* p = node->next;
            node->next = p->next;
            node = node->next;
            delete p;
            --n;
        }
        return node->val;
    }
};