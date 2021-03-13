/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/2
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        return dfs(root,root);
    }

    int dfs(TreeNode* root1,TreeNode* root2){
        if (root1 == nullptr && root2 == nullptr){
            return true;
        }

        if (root1 != nullptr && root2 != nullptr){
            return root1->val == root2->val && dfs(root1->left,root2->right) && dfs(root1->right,root2->left);
        }
        return false;
    }
};


int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    TreeNode* node_l = new TreeNode(2);
    TreeNode* node_r = new TreeNode(2);

    root->left = node_l;
    root->right = node_l;

    solution.isSymmetric(root);
}