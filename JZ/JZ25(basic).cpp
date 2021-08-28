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
        RandomListNode* newHead = new RandomListNode(-1);
        RandomListNode* newNode = newHead;
        while(oldNode) {
            newNode->next = new RandomListNode(oldNode->label);
            newNode = newNode->next;
            oldNode = oldNode->next;
        }
        newHead = newHead->next;
        newNode = newHead;
        oldNode = pHead;
        while(oldNode) {
            if(oldNode->random == nullptr)
                newNode->random = nullptr;
            else {
                RandomListNode* findRandomNode = newHead;
                while(findRandomNode && findRandomNode->label != oldNode->random->label) {
                    findRandomNode = findRandomNode->next;
                }
                newNode->random = findRandomNode;
            }
            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        return newHead;
    }
};