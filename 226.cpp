/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/15
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }

    void dfs(TreeNode* root){
        if (root == nullptr){
            return;
        }

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        dfs(root->left);
        dfs(root->right);
    }
};