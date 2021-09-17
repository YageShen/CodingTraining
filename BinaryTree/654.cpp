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
    // unordered_map<int, int> m;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildMaxBinaryTree(nums, 0, nums.size() - 1);
    }
    TreeNode* buildMaxBinaryTree(vector<int>& nums, int l, int r) {
        if(l > r) return nullptr;
        int max_num = nums[l];
        int max_idx = l;
        for(int i = l + 1; i <= r; ++i) {
            if(nums[i] > max_num) {
                max_num = nums[i];
                max_idx = i;
            }
        }
        TreeNode* root = new TreeNode(max_num);
        root->left = buildMaxBinaryTree(nums, l, max_idx - 1);
        root->right = buildMaxBinaryTree(nums, max_idx + 1, r);
        return root;
    }
};