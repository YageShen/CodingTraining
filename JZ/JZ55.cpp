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
        unordered_set<ListNode*> ss;
        ListNode* node = pHead;
        while(node) {
            if(ss.find(node) == ss.end()) {
                ss.insert(node);
                node = node->next;
            }
            else {
                break;
            }
        }
        return node;
    }
};