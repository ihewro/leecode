/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/21
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
    int p_level = 0;
    int q_level = 0;
    vector<TreeNode*> p_parent;
    vector<TreeNode*> q_parent;
    int findNum = 0;


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr){
            return nullptr;
        }
        dfs(root,p,q,0);

        //������vector���ҵ������
        int size = std::min(p_parent.size(),q_parent.size());

//        for (int i = 0; i < p_parent.size(); ++i) {
//            std::cout << p_parent[i]->val << " ";
//        }
//        std::cout << std::endl;
//
//
//        for (int i = 0; i < q_parent.size(); ++i) {
//            std::cout << q_parent[i]->val << " ";
//        }
//        std::cout << std::endl;
        int i =0;
        for (i = 0; i < size; ++i) {
            int p_index = p_parent.size() - i - 1;
            int q_index = q_parent.size() - i - 1;

            if (p_index  < 0 || q_index < 0){
                break;
            }
            if (p_parent[p_index] == q_parent[q_index]){
                continue;
            }else{
                return p_parent[p_index + 1];
            }
        }
        return p_parent[p_parent.size() - i];
    }

    int dfs(TreeNode* root,TreeNode* p, TreeNode* q,int level){
        int ret = -1;
        int currentRootFindNum = 0;

        if (root == nullptr){
            return ret;
        }
        if (root == p){
            p_parent.push_back(root);
            findNum ++;
            currentRootFindNum++;
            ret = 1;
        }

        if (root == q){
            q_parent.push_back(root);
            findNum ++;
            currentRootFindNum++;
            ret =  2;
        }

        if (findNum == 2){
            return ret;
        }

        int left_ret = dfs(root->left,p,q,level + 1);
        int right_ret = dfs(root->right,p,q,level + 1);

        if (left_ret == 1){
            p_parent.push_back(root);
        }else if (left_ret == 2){
            q_parent.push_back(root);
        } else if (left_ret == 3){
            p_parent.push_back(root);
            q_parent.push_back(root);
        }

        if (right_ret == 1){
            p_parent.push_back(root);
        }else if (right_ret == 2){
            q_parent.push_back(root);
        }else if (right_ret == 3){
            p_parent.push_back(root);
            q_parent.push_back(root);
        }

        if (left_ret > 0 ){
            currentRootFindNum++;
        }
        if (right_ret > 0){
            currentRootFindNum++;
        }

        if (currentRootFindNum >=2){
            //��root����ͬʱ�ҵ�����Ҫ���ҵ������ڵ�
            ret = 3;
        }else{
            ret = std::max(ret,left_ret);
            ret = std::max(ret,right_ret);
        }

        return ret;
    }
};


int main(){

    Solution solution;
//    TreeNode* root = new TreeNode(3);
//
//    TreeNode* root_2 = new TreeNode(5);
//    TreeNode* root_4 = new TreeNode(6);
//    TreeNode* root_5 = new TreeNode(2);
//    TreeNode* root_6 = new TreeNode(7);
//    TreeNode* root_7 = new TreeNode(4);
//    root_5->left = root_6;
//    root_5->right = root_7;
//    root_2->left = root_4;
//    root_2->right = root_5;
//
//    TreeNode* root_3 = new TreeNode(1);
//    TreeNode* root_8 = new TreeNode(0);
//    TreeNode* root_9= new TreeNode(0);
//    root_3->left = root_8;
//    root_3->right = root_9;
//
//    root->left = root_2;
//    root->right = root_3;

    TreeNode* root = new TreeNode(1);
    TreeNode* root_1 = new TreeNode(2);
    root->left = root_1;

//    std::cout << solution.lowestCommonAncestor(root,root_2,root_3)->val << std::endl;
    std::cout << solution.lowestCommonAncestor(root,root_1,root)->val << std::endl;
}