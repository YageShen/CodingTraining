/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        ListNode* node = head;
        while(node)
        {
            res.push_back(node->val);
            node = node->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};