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
    bool isSymmetric(TreeNode *root) {
        std::queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()){
            int size = q.size();
            while (size > 0){
                auto left = q.front();
                q.pop();
                auto right = q.front();
                q.pop();
                size -=2;

                if(left == nullptr && right== nullptr){
                    continue;
                }

                if ((left == nullptr || right == nullptr) || (left->val != right->val)){
                    return false;//一个为 null，另一个不为 null，或者值不相等
                }else{
                    q.push(left->left);
                    q.push(right->right);

                    q.push(left->right);
                    q.push(right->left);
                }
            }
        }
        return true;
    }

};

int main() {
    Solution solution;
    TreeNode *root = new TreeNode(1);
    TreeNode *node_l = new TreeNode(2);
    TreeNode *node_r = new TreeNode(2);

    node_l->right = new TreeNode(3);
    node_r->right = new TreeNode(3);

    root->left = node_l;
    root->right = node_r;

    std::cout << solution.isSymmetric(root) << std::endl;
}