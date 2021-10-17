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
class Solution {
public:


    int min_(int cnt, ...) {
        int value = 0;
        int i = 0;
        int arg_cnt = cnt;
        va_list arg_ptr;
        va_start(arg_ptr, cnt);
        int min_val = INT_MAX;
        for (i = 0; i < cnt; i++) {
            value = va_arg(arg_ptr, int);
            min_val = std::min(min_val, value);
        }
        va_end(arg_ptr);

        return min_val;
    }

    std::tuple<int, int, int> dfs(TreeNode *root) {
        if (root == nullptr) {
            return {INT_MAX / 2, 0, 0};
        }
        if (root->val == 9) {
            std::cout << "";
        }
        int l_y, l_n_father, l_n_son;
        int r_y, r_n_father, r_n_son;
        std::tie(l_y, l_n_father, l_n_son) = dfs(root->left);
        std::tie(r_y, r_n_father, r_n_son) = dfs(root->right);

        int y = min_(9,
                     l_n_father + r_n_father,
                     l_n_father + r_n_son,
                     l_n_father + r_y,
                     l_n_son + r_n_father,
                     l_n_son + r_n_son,
                     l_n_son + r_y,
                     l_y + r_n_father,
                     l_y + r_n_son,
                     l_y + r_y) + 1;
        int n_father = min_(4,
                            l_y + r_y,
                            l_y + r_n_son,
                            l_n_son + r_y,
                            l_n_son + r_n_son);

        int n_son = min_(3,
                         l_y + r_y,
                         l_y + r_n_son,
                         l_n_son + r_y);

        return {y, n_father, n_son};
    }

    int minCameraCover(TreeNode *root) {
        auto[y, n_father, n_son] = dfs(root);
        return std::min(y, n_son);
    }
};

int main() {
    auto root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);

    root->right->right->right->right->left = new TreeNode(6);
    root->right->right->right->right->right = new TreeNode(7);

    root->right->right->right->right->right->left = new TreeNode(8);
    root->right->right->right->right->right->right = new TreeNode(9);

    Solution solution;
    std::cout << solution.minCameraCover(root);
}