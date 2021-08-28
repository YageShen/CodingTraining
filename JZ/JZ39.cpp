class Solution {
public:
    unordered_map<TreeNode*, int> hashMap;
    int treeDeep(TreeNode* pRoot) {
        if(pRoot == nullptr)
            return 0;
        return hashMap[pRoot] = max(treeDeep(pRoot->left), treeDeep(pRoot->right)) + 1;
    }
    bool judgeBalanceTree(TreeNode* pRoot) {
        if(pRoot == nullptr)
            return true;
        return abs(treeDeep(pRoot->left) - treeDeep(pRoot->right)) <= 1 
                && judgeBalanceTree(pRoot->left) && judgeBalanceTree(pRoot->right);
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        treeDeep(pRoot);
        return judgeBalanceTree(pRoot);
    }
};