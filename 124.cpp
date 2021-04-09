//
// Created by hewro on 2021/4/6.
//

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
    int max = INT_MIN;

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max;
    }

    int dfs(TreeNode* root){
        //base case
        if (root == nullptr){
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);

        max = std::max(max,std::max(0,left) + std::max(0,right) + root->val);
        return std::max(std::max(0,left) + root->val,std::max(0,right) + root->val);
    }
};

int main(){
    auto root = tree_util::createTree({1,2,3});
    Solution solution;
    std::cout << solution.maxPathSum(root) << std::endl;

//    auto root = tree_util::createTree({5, 4, 7, 3, -1, 2, -1, 0, -1, 9});
//    tree_util::print_preorder(root);



}