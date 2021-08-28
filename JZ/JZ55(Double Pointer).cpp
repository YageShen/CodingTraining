/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* slow = pHead;
        ListNode* fast = pHead;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(!fast || !fast->next)
            return nullptr;
        
        ListNode* slow2 = pHead;
        while(slow != slow2) {
            slow = slow->next;
            slow2 = slow2->next;
        }
        return slow;
    }
};