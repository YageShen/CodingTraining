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
        vector<vector<int> > ret;
        if(!pRoot)
            return ret;
        queue<TreeNode*> q;
        q.push(pRoot);
        int depth = 0;
        while(!q.empty()) {
            ++depth;
            int sc = q.size();
            vector<int> ret_row;
            while(sc--) {
                TreeNode* node = q.front();
                q.pop();
                ret_row.push_back(node->val);
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            if(depth % 2 == 0)
                reverse(ret_row.begin(), ret_row.end());
            ret.push_back(ret_row);
        }
            
        return ret;
    }
    
};