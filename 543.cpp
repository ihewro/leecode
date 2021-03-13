/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/1
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    int max = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        dfs(root);
        return max;
    }
    int dfs(TreeNode* root){
        if (root == nullptr) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        max = std::max(max,left + right);
        return std::max(left,right) + 1;
    }
};


int main (){
    TreeNode * node_1 = new TreeNode(1);
    TreeNode * node_2 = new TreeNode(2);
    TreeNode * node_3 = new TreeNode(3);

    node_1->left = node_2;
    node_1->right = node_3;

    TreeNode * node_4 = new TreeNode(4);
    TreeNode * node_5 = new TreeNode(5);
    node_2->left = node_4;
    node_2->right = node_5;

    Solution solution;
    std::cout << solution.diameterOfBinaryTree(node_1) << std::endl;


}