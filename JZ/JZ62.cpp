/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    void midOrder(TreeNode* pRoot, vector<TreeNode*>& ret, int k) {
        if(!pRoot)
            return;
        if(ret.size() >= k)
            return;
        midOrder(pRoot->left, ret, k);
        ret.push_back(pRoot);
        midOrder(pRoot->right, ret, k);
    }
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if(k <= 0 || pRoot == nullptr) {
            return nullptr;
        }
        vector<TreeNode*> ret;
        midOrder(pRoot, ret, k);
        if(k > ret.size())
            return nullptr;
        return ret[k-1];
    }

    
};