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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* node1 = pHead1;
        ListNode* node2 = pHead2;
        unordered_set<ListNode*> ss;
        while(node1 && node2) {
            if(ss.find(node1) == ss.end()) {
                ss.insert(node1);
                node1 = node1->next;
            }
            else
                return node1;
            if(ss.find(node2) == ss.end()) {
                ss.insert(node2);
                node2 = node2->next;
            }
            else
                return node2;
        }
        ListNode* node = node1 ? node1 : node2;
        while(node) {
            if(ss.find(node) == ss.end()) {
                node = node->next;
            }
            else
                return node;
        }
        return node;
    }
};