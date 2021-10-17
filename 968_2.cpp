//
// Created by hewro on 2021/10/15.
//

#include "bits/stdc++.h"

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
struct Status {
    int a, b, c;
};

class Solution {
public:
    Status dfs(TreeNode* root) {
        if (!root) {
            return {INT_MAX / 2, 0, 0};
        }
        auto [la, lb, lc] = dfs(root->left);
        auto [ra, rb, rc] = dfs(root->right);
        int a = lc + rc + 1;
        int b = min(a, min(la + rb, ra + lb));
        int c = min(a, lb + rb);
        return {a, b, c};
    }

    int minCameraCover(TreeNode* root) {
        auto [a, b, c] = dfs(root);
        return b;
    }
};

int main() {
    auto root = new TreeNode(0);
    root->right = new TreeNode(0);
    root->right->right = new TreeNode(0);
    root->right->right->right = new TreeNode(0);
    root->right->right->right->right = new TreeNode(0);

    root->right->right->right->right->left = new TreeNode(0);
    root->right->right->right->right->right = new TreeNode(0);

    root->right->right->right->right->right->left = new TreeNode(0);
    root->right->right->right->right->right->right = new TreeNode(0);

    Solution solution;
    std::cout << solution.minCameraCover(root);
}