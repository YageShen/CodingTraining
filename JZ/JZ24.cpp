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
    vector<vector<int> > ret;
    
    void dfs(TreeNode* root, int sum, vector<int> route, int expectNumber) {
        sum += root->val;
        if(sum > expectNumber)
            return;
        else {
            route.push_back(root->val);
            if(root->left) {
                dfs(root->left, sum, route, expectNumber);
            }
            if(root->right) {
                dfs(root->right, sum, route, expectNumber);
            }
            if(!root->left && !root->right && sum == expectNumber) {
                ret.push_back(route);
                return;
            }
        }
            
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int> route;
        if(root != nullptr)
            dfs(root, 0, route, expectNumber);
        return ret;
    }
};