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
    void dfs(TreeNode* root, vector<TreeNode*>& vec) {
        if(root == nullptr)
            return;
        else {
            dfs(root->left, vec);
            vec.push_back(root);
            dfs(root->right, vec);
        }
    }
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(pRootOfTree) {
            vector<TreeNode*> vec;
            dfs(pRootOfTree, vec);
            for(int i = 0; i < vec.size() - 1; ++i) {
                vec[i]->right = vec[i+1];
                vec[i+1]->left = vec[i];
            }
//             vec[0]->left = vec[vec.size()-1];
//             vec[vec.size()-1]->right = vec[0];
            return vec[0];
        }
        else
            return nullptr;
    }
};