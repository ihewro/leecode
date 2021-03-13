/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/15
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
    int maxDepth(TreeNode *root) {
        return dfs(root,0);
    }

    int dfs(TreeNode *root, int level){
        if (root == nullptr){//base case
            return level;
        }
        int left_level = dfs(root->left,level+1);
        int right_level = dfs(root->right,level+1);

        return std::max(left_level,right_level);
    }
};

int main(){
    Solution solution;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    std::cout << solution.maxDepth(root) << std::endl;
}