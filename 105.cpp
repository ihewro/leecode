/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/23
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

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
    vector<int> _preorder;
    vector<int> _inorder;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        auto* root = new TreeNode(-1);
        if (preorder.empty() ||(preorder.size() ==1 && preorder[0] == -1)){
            return root;
        }
        this->_preorder = std::move(preorder);
        this->_inorder = std::move(inorder);

        root = build(0,_preorder.size()-1,0, _inorder.size()-1);

        return root;
    }

    TreeNode* build(int pre_i,int pre_j, int in_i,int in_j){
        if (pre_i > pre_j || in_i > in_j){
            return nullptr;
        }
        auto * root = new TreeNode(_preorder[pre_i]);

        if (pre_i == pre_j || in_i == in_j){
            return root;
        }
        int p = 0;
        for (int i = in_i; i <=in_j ; ++i) {
            if (_inorder[i] == root->val){
                p = i;
                break;
            }
        }

        int left_len = p-1 - in_i + 1;
        root->left = build(pre_i+1,pre_i+1+left_len-1, in_i,p-1);
        root->right = build(pre_i+1+left_len,pre_j, p+1,in_j);

        return root;
    }


};


int main() {
    Solution solution;
    vector<int> pre{3,9,20,15,7};
    vector<int> in{9,3,15,20,7};
    tree_util::print_preorder(solution.buildTree(pre,in));
}