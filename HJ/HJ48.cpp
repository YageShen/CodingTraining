#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next = nullptr;
};

class list
{
public:
    void creat(int val)
    {
        head = new ListNode;
        head->val = val;
        head->next = nullptr;
    }
    void insert(int a, int b) // 在b后面插入a
    {
        ListNode* node = head;
        while(node)
        {
            if(node->val == b)
            {
                ListNode* insertNode = new ListNode;
                insertNode->val = a;
                insertNode->next = node->next;
                node->next = insertNode;
                break;
            }
            node = node->next;
        }
    }
    void erase(int a)
    {
        ListNode* node = head;
        if(node->val == a)
        {
            node = node->next;
            return;
        }
        while(node)
        {
            if(node->next->val == a)
            {
                node->next = node->next->next;
                break;
            }
            node = node->next;
        }
    }
    void print()
    {
        ListNode* node = head;
        while(node)
        {
            cout << node->val << ' ';
            node = node->next;
        }
        cout << endl;
    }
public:
    ListNode* head;
};

int main()
{
    int node_num, root_val;
    list L;
    cin >> node_num >> root_val;
    L.creat(root_val);
    for(int i(1); i < node_num; ++i)
    {
        int parent_val, node_val;
        cin >> node_val >> parent_val;
        L.insert(node_val, parent_val);
    }
    int deleteNum;
    cin >> deleteNum;
    L.erase(deleteNum);
    L.print();
    return 0;
}