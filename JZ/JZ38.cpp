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
    int TreeDepth(TreeNode* pRoot) {
        if(!pRoot)
            return 0;
        queue<TreeNode*> q;
        q.push(pRoot);
        int depth = 0;
        while(!q.empty()) {
            int sc = q.size();
            while(sc--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ++depth;
        }
        return depth;
    }
};