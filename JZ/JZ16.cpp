/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode *first = pHead1;
        ListNode *second = pHead2;
        ListNode *resHead = new ListNode(-1);
        ListNode *third = resHead;
        while(first && second) {
            if(first->val < second->val) {
                third->next = first;
                first = first->next;
            }
            else {
                third->next = second;
                second = second->next;
            }
            third = third->next;
        }
        third->next = first ? first : second;
        return resHead->next;
    }
};