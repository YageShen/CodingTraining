/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

// 复杂链表的复制
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        RandomListNode* oldNode = pHead;
        unordered_map<RandomListNode*, RandomListNode*> m;
        while(oldNode) {
            m[oldNode] = new RandomListNode(oldNode->label);
            oldNode = oldNode->next;
        }
        oldNode = pHead;
        while(oldNode) {
            m[oldNode]->next = oldNode->next;
            m[oldNode]->random = m[oldNode->random];
            oldNode = oldNode->next;
        }
        return m[pHead];
    }
};