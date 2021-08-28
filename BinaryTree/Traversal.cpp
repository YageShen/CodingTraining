/*
 * @Author: 沈雅阁
 * @Date: 2021-08-23 10:00:21
 * @LastEditTime: 2021-08-23 14:24:01
 * @LastEditors: Please set LastEditors
 * @Description: 二叉树遍历和恢复
 * @FilePath: \nowcoder-hw\BinaryTree\Traversal.cpp
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> ret;
    vector<int> preOrder(TreeNode* root) {
        if(root == nullptr) {
            return ret;
        }
        ret.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
        return ret;
    }
    vector<int> inOrder(TreeNode* root) {
        if(!root) {
            return ret;
        }
        inOrder(root->left);
        ret.push_back(root->val);
        inOrder(root->right);
        return ret;
    }
    vector<int> postOrder(TreeNode* root) {
        if(!root) {
            return ret;
        }
        postOrder(root->left);
        postOrder(root->right);
        ret.push_back(root->val);
        return ret;
    }
    vector<int> layerOrder(TreeNode* root) {
        if(!root) {
            return ret;
        }
        queue<TreeNode*> q;
        int depth = 0;
        q.push(root);
        ret.push_back(root->val);
        while(!q.empty()) {
            int sc = q.size();
            while(sc--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) {
                    q.push(node->left);
                    ret.push_back(node->left->val);
                }
                if(node->right) {
                    q.push(node->right);
                    ret.push_back(node->right->val);
                }
            }
            ++depth;
        }
        return ret;
    }

    /**
     * @description: 创建一个完全二叉树
     * @param {int} nodeNum 完全二叉树的节点数量
     * @param {int} nodeVal 根节点的编号，按层序顺编
     * @return {*} 根节点指针
     */
    TreeNode* buildBinaryTree(int nodeNum, int nodeVal) {
        TreeNode* node = new TreeNode(nodeVal);
        if(nodeVal*2 <= nodeNum) {
            node->left = buildBinaryTree(nodeNum, nodeVal*2);
        }
        if(nodeVal*2+1 <= nodeNum) {
            node->right = buildBinaryTree(nodeNum, nodeVal*2+1);
        }
        return node;
    }
    /**
     * @description: 根据中序遍历序列和后序遍历序列重建二叉树
     * @param {vector<int>&} inOrder 中序遍历序列
     * @param {vector<int>&} postOrder 后序遍历序列
     * @return {TreeNode*} 根节点指针
     */    
    TreeNode* rebuildFromInAndPost(vector<int>& inOrder, vector<int>& postOrder) {
        return _rebuildFromInAndPost(inOrder, postOrder, 0, inOrder.size() - 1, 0, postOrder.size() - 1);
    }

    /**
     * @description: 根据前序遍历序列和中序遍历序列重建二叉树
     * @param {vector<int>&} preOrder 前序遍历序列
     * @param {vector<int>&} inOrder 中序遍历序列
     * @return {TreeNode*} 根节点指针
     */    
    TreeNode* rebuildFromPreAndIn(vector<int>& preOrder, vector<int>& inOrder) {
        return _rebuildFromPreAndIn(preOrder, inOrder, 0, preOrder.size() - 1, 0, inOrder.size() - 1);
    }

    void clearRet() {
        ret.clear();
    }

private:
    TreeNode* _rebuildFromInAndPost(vector<int>& inOrder, vector<int>& postOrder, int inOrderLeft, int inOrderRight, int postOrderLeft, int postOrderRight) {
        if(inOrderLeft > inOrderRight || postOrderLeft > postOrderRight)
            return nullptr;
        TreeNode* root = new TreeNode(postOrder[postOrderRight]);
        for(int i = inOrderLeft; i <= inOrderRight; ++i) {
            if(inOrder[i] == root->val) {
                root->left = _rebuildFromInAndPost(inOrder, postOrder, inOrderLeft, i - 1, postOrderLeft, postOrderLeft + i - inOrderLeft - 1);
                root->right = _rebuildFromInAndPost(inOrder, postOrder, i + 1, inOrderRight, postOrderLeft + i - inOrderLeft, postOrderRight - 1);
                break;
            }
        }
        return root;
    }
    TreeNode* _rebuildFromPreAndIn(vector<int>& preOrder, vector<int>& inOrder, int preOrderLeft, int preOrderRight, int inOrderLeft, int inOrderRight) {
        if(preOrderLeft > preOrderRight || inOrderLeft > inOrderRight)
            return nullptr;
        TreeNode* root = new TreeNode(preOrder[preOrderLeft]);
        for(int i = inOrderLeft; i <= inOrderRight; ++i) {
            if(inOrder[i] == root->val) {
                root->left = _rebuildFromPreAndIn(preOrder, inOrder, preOrderLeft + 1, preOrderLeft + i - inOrderLeft, inOrderLeft, i - 1);
                root->right = _rebuildFromPreAndIn(preOrder, inOrder, preOrderLeft + i - inOrderLeft + 1, preOrderRight, i + 1, inOrderRight);
                break;
            }
        }
        return root;
    }
};

int main() {
	Solution sol;
	TreeNode* root = sol.buildBinaryTree(7, 1);
    vector<int> preOrderRet;
    preOrderRet = sol.preOrder(root);
    sol.clearRet();
    vector<int> inOrderRet;
    inOrderRet = sol.inOrder(root);
    sol.clearRet();
    vector<int> postOrderRet;
    postOrderRet = sol.postOrder(root);
    sol.clearRet();
    vector<int> layerOrderRet;
    layerOrderRet = sol.layerOrder(root);
    sol.clearRet();
    TreeNode* root1;
    root1 = sol.rebuildFromInAndPost(inOrderRet, postOrderRet);
    TreeNode* root2;
    root2 = sol.rebuildFromPreAndIn(preOrderRet, inOrderRet);
    return 0;
}
