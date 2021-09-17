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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

    }
private:
    vector<TreeNode*> ret;
    unordered_map<string, int> m;
    string traverse(TreeNode* root) {
        if(root == nullptr) return "#";
        string left = traverse(root->left);
        string rigth = traverse(root->right);
        string subTree = left + "," + right + "," + to_string(root->val);
        return left + right;
    }
};