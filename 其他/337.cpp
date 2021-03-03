/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/18
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    std::unordered_map<TreeNode*,int> can_map{};
    std::unordered_map<TreeNode*,int> can_not_map{};


    int rob(TreeNode* root) {
        can_map[nullptr] = 0;
        can_not_map[nullptr] = 0;
        dfs(root);
        return can_map.at(root);
    }

    void dfs(TreeNode* node){
        if (node == nullptr){
            return ;
        }dfs(node->left);
        dfs(node->right);
        can_map[node] = std::max(can_map[node->left] + can_map[node->right],
                                        node->val + can_not_map[node->left] + can_not_map[node->right]);
        can_not_map[node] = can_map[node->left] + can_map[node->right];
    }
};

int main() {
    Solution solution;
}