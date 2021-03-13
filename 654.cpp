/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/23
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
    vector<int> nums_;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        this->nums_ = std::move(nums);
        TreeNode* root = dfs(0,nums_.size()-1);
        return root;
    }

    TreeNode* dfs(int i,int j){
        if (i > j){
            return nullptr;
        }
        if (i==j){
            return new TreeNode(nums_[j]);
        }
        int max_position = 0;
        int max = INT_MIN;
        for (int k = i; k <= j; ++k) {
            if (nums_[k] > max){
                max = nums_[k];
                max_position = k;
            }
        }

        auto* root = new TreeNode(max);

        root->left = dfs(i,max_position-1);
        root->right = dfs(max_position+1,j);

        return root;
    }

};


int main() {
    Solution solution;
    vector<int> input{3,2,1,6,0,5};
    tree_util::print_preorder(solution.constructMaximumBinaryTree(input));
}