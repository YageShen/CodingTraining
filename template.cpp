#include<iostream>
using namespace std;
struct node
{
    int val;
    struct node *left = NULL;
    struct node *right = NULL;
    node(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

int main()
{
    int n,m,i;
    node *head = NULL;           //头指针
    cin >> n;
    node *p;
    node *pre;
    for(i = 0; i < n; ++i) // 建链
    {
        pre = p;
        p = new node(i+1);
        if(head == NULL)
        {
            head = p;
        }
        else
        {
            pre->right = p;
            p->left = pre;
        }
    }
    
    cin >> m;
//     node* p = tail;
//     node* q;
    p = head;
//     node* q = p; // 备份
    int dir = 0;
    int del_num = 0;
    while(p) {
        for(int i = 1; i < m; ++i) {
//             q = p;
            if(dir == 0) {
                p = p->right;
            } 
            else {
                p = p->left;
            }
            if(p->left == NULL && dir == 1) // 换向
                dir = 0;
            else if(p->right == NULL && dir == 0) // 换向
                dir = 1;
        }
        
        if(p->left)
            p->left->right = p->right;
        if(p->right)
            p->right->left = p->left;
        delete p;
        ++del_num;
        if(dir == 0) {
            p = p->right;
            if(p->right == NULL) dir = 1;
        }
        else {
            p = p->left;
            if(p->left == NULL) dir = 0;
        }
        if(del_num == n - 1) break;
    }
    cout << p->val << endl;
    return 0;
}