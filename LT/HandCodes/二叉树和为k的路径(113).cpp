/*
 * @Author: your name
 * @Date: 2021-09-21 20:12:01
 * @LastEditTime: 2021-09-21 20:12:31
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \CodingTraining\LT\HandCode\二叉树和为k的路径(113).cpp
 */
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
    vector<vector<int>> ret;
    vector<int> path;
    void dfs(TreeNode* root, int sum, int target) {
        if(root == nullptr)
            return;
        path.push_back(root->val);
        sum += root->val;
        if(root->left == nullptr && root->right == nullptr && sum == target) {
            ret.push_back(path);
        }
        dfs(root->left, sum, target);
        dfs(root->right, sum, target);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, 0, target);
        return ret;
    }
};