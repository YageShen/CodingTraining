class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * p = head;
        if (p == NULL)
        {
            return head;
        }
        while (p->next != NULL)
        {
            if (p->val == p->next->val) // 关键步骤：跳过数值相同的节点
            {
                p->next = p->next->next;
            }
            else
            {
                p = p->next;
            }
        }
        return head;
    }
};