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

    TreeNode* dfsBuildTree(vector<int>& preorder, vector<int>& inorder,int pre_begin,int pre_end,int in_begin,int in_end){
        if (pre_begin > pre_end){
            return nullptr;
        }
        if(pre_begin == pre_end){
            return new TreeNode(preorder[pre_end]);
        }

        //获取当前根节点
        TreeNode* root = new TreeNode(preorder[pre_begin]);
        //寻找根节点在中序中的位置
        int index = in_begin;
        while(inorder[index] != root->val){
            index++;
        }

        int left_len = index - in_begin + 1;


        TreeNode* left = dfsBuildTree(preorder,inorder,pre_begin+1,pre_begin+left_len, in_begin,index-1);//构建左子树
        TreeNode* right = dfsBuildTree(preorder,inorder,pre_begin+left_len+1,pre_end, index+1,in_end);//构建右子树
        root->left = left;
        root->right = right;
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfsBuildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};

int main() {
    Solution solution;
    vector<int> pre{3,9,20,15,7};
    vector<int> in{9,3,15,20,7};
    tree_util::print_preorder(solution.buildTree(pre,in));
}