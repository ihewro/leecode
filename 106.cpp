/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/23
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    vector<int> _postorder;
    vector<int> _inorder;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->_postorder = std::move(postorder);
        this->_inorder = std::move(inorder);
        auto* root = new TreeNode(-1);
        if (_postorder.empty() ||(_postorder.size() ==1 && _postorder[0] == -1)){
            return root;
        }


        root = build(0,_postorder.size()-1,0, _inorder.size()-1);

        return root;
    }

    TreeNode* build(int post_i,int post_j, int in_i,int in_j){
        if (post_i > post_j || in_i > in_j){
            return nullptr;
        }
        auto * root = new TreeNode(_postorder[post_j]);
//        std::cout << "root" << root->val  << std::endl;

        if (post_i == post_j || in_i == in_j){
            return root;
        }
        //�ҵ���ǰroot�����������е�λ��
        int p = 0;
        for (int i = in_i; i <=in_j ; ++i) {
            if (_inorder[i] == root->val){
                p = i;
                break;
            }
        }

        int right_len = in_j - p-1 + 1;
        root->left = build(post_i,post_j-1-right_len+1 -1, in_i,p-1);
        root->right = build(post_j-1-right_len+1,post_j-1, p+1,in_j);

        return root;
    }


};


int main() {
    Solution solution;
}