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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ret;
        if(root == nullptr)
            return ret;
        q.push(root);
        ret.push_back(root->val);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left) {
                q.push(temp->left);
                ret.push_back(temp->left->val);
            }
            if(temp->right) {
                q.push(temp->right);
                ret.push_back(temp->right->val);
            }
        }
        return ret;
    }
};