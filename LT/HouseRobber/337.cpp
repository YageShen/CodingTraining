/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> m;
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        if(m.count(root) > 0) return m.find(root)->second;
        int do_it = root->val + 
                    (root->left == nullptr ? 0 : rob(root->left->left) + rob(root->left->right)) + 
                    (root->right == nullptr ? 0 : rob(root->right->left) + rob(root->right->right));
        int not_do = rob(root->left) + rob(root->right);
        int ret = max(do_it, not_do);
        m.insert(pair<TreeNode*, int>(root, ret));
        return ret;
    }
};