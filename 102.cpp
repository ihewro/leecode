/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/3
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret{};
        if (root == nullptr){
            return ret;
        }

        std::cout << ret.size() - 1<< std::endl;
        dfs(root,0,ret);
        return ret;
    }

    void dfs(TreeNode * node, int level,vector<vector<int>>& ret){
        if (node == nullptr){
            return ;
        }

        if (level >= ret.size()){
            ret.emplace_back();
        }
        ret[level].push_back(node->val);

        dfs(node->left,level + 1 ,ret);
        dfs(node->right,level + 1 ,ret);
    }
};

int main() {
    Solution solution;
    TreeNode * root = new TreeNode(3);
    solution.levelOrder(root);

}