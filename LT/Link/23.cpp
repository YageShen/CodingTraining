// 合并k个升序链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct ListNodeUp {
        bool operator () (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        priority_queue<ListNode*, vector<ListNode*>, ListNodeUp> pq;
        for (ListNode* head : lists) {
            if(head != nullptr)
                pq.push(head);
        }
        while(!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            p->next = node;
            if (node->next != nullptr) {
                pq.push(node->next);
            }
            p = p->next;
        }
        return dummy->next;
    }
};