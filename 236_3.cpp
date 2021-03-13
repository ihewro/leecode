/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/21
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr){
            return nullptr;
        }
        if (root == p || root == q){
            return root;
        }
        auto left = lowestCommonAncestor(root->left,p,q);
        auto right = lowestCommonAncestor(root->right,p,q);

        if (left && right){
            return root;
        }
        if (!left && !right){
            return nullptr;
        }
        if (left == nullptr){
            return right;
        }else{
            return left;
        }
    }
};


int main(){

    Solution solution;
//    TreeNode* root = new TreeNode(3);
//
//    TreeNode* root_2 = new TreeNode(5);
//    TreeNode* root_4 = new TreeNode(6);
//    TreeNode* root_5 = new TreeNode(2);
//    TreeNode* root_6 = new TreeNode(7);
//    TreeNode* root_7 = new TreeNode(4);
//    root_5->left = root_6;
//    root_5->right = root_7;
//    root_2->left = root_4;
//    root_2->right = root_5;
//
//    TreeNode* root_3 = new TreeNode(1);
//    TreeNode* root_8 = new TreeNode(0);
//    TreeNode* root_9= new TreeNode(0);
//    root_3->left = root_8;
//    root_3->right = root_9;
//
//    root->left = root_2;
//    root->right = root_3;

    TreeNode* root = new TreeNode(1);
    TreeNode* root_1 = new TreeNode(2);
    root->left = root_1;

//    std::cout << solution.lowestCommonAncestor(root,root_2,root_3)->val << std::endl;
    std::cout << solution.lowestCommonAncestor(root,root_1,root)->val << std::endl;
}