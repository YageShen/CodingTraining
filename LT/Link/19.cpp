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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if(head->next == nullptr)
        //     return nullptr;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *node = findNthFromEnd(dummy, n + 1);
        if(node != nullptr && node->next != nullptr)
            node->next = node->next->next;
        else
            return nullptr;
        return dummy->next;
    }
private:
    ListNode* findNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for(int i = 0; i < n; ++i) {
            if(fast == nullptr)
                return nullptr;
            fast = fast->next;
        }
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};