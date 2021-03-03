/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/3
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr){
            return ret;
        }
        dfs(root,ret);
        return ret;
    }

    void dfs(TreeNode* node,vector<int> &ret){
        if (node == nullptr){
            return ;
        }

        dfs(node->left,ret);
        ret.push_back(node->val);
        dfs(node->right,ret);
    }
};

int main() {
    Solution solution;
}