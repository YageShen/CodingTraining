/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* pre;
    TreeNode* head;
    void dfs(TreeNode* node) {
        if(node == nullptr)
            return;
        else {
            dfs(node->left);
            
            if(pre == nullptr) {
                head = node;
            } else {
                pre->right = node;
            }
            node->left = pre;
            pre = node;
            
            dfs(node->right);
        }
    }
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(pRootOfTree) {
            dfs(pRootOfTree);
            return head;
        }
        else
            return nullptr;
    }
};