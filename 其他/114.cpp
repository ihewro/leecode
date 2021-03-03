/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/23
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
    void flatten(TreeNode* root) {
        if (root == nullptr){
            return ;
        }

        flatten(root->left);
        flatten(root->right);

        auto left = root->left;
        auto right = root->right;

        root->left = nullptr;
        root->right = left;
        TreeNode* p = root;//�ҵ�right ��������ӽڵ�
        while (p->right != nullptr){
            p = p->right;
        }

        p->right = right;
    }
};

int main() {
    Solution solution;
}