/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 已知中序、后序，重建二叉树
class Solution {
public:
    TreeNode* rebuild(vector<int>& vin, int vin_left, int vin_right, vector<int>& pos, int pos_left, int pos_right) {
        if(vin_left > vin_right || pos_left > pos_right)
            return nullptr;
        TreeNode* root = new TreeNode(pos[pos_right]);
        for(int i = vin_left; i <= vin_right; ++i) {
            if(vin[i] == pos[pos_right]) {
                root->left = rebuild(vin, vin_left, i-1, pos, pos_left, pos_left+i-vin_left-1);
                root->right = rebuild(vin, i+1, vin_right, pos, pos_left+i-vin_left, pos_right-1);
                break;
            }
        }
        return root;
    }
    
    TreeNode* reConstructBinaryTree(vector<int>& vin,vector<int>& pos) {
        return rebuild(vin, 0, vin.size()-1, pos, 0, pos.size()-1);
    }
};