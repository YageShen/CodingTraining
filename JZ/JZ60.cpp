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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if(pRoot) {
            queue<TreeNode*> q;
            q.push(pRoot);
            while(!q.empty()) {
                int sc = q.size();
                vector<int> row;
                while(sc--) {
                    TreeNode* node = q.front();
                    q.pop();
                    row.push_back(node->val);
                    if(node->left)
                        q.push(node->left);
                    if(node->right)
                        q.push(node->right);
                }
                res.push_back(row);
            }
        }
        return res;
    }
    
};