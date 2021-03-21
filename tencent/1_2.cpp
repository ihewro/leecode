//
// Created by hewro on 2021/3/21.
//

#include "bits/stdc++.h"
#include <math.h>
class Solution {
public:
    vector<ListNode*> ret;
    std::unordered_map<int,ListNode*> map;
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 你需要返回m个指针，第i个指针指向一条链，表示第i个问题的答案
     * @param root TreeNode类 指向链表树的根
     * @param b int整型vector 表示每个问题是什么
     * @return ListNode类vector
     */
    vector<ListNode*> solve(TreeNode* root, vector<int>& b) {
        map[root->val]= new ListNode(root->val);
        dfs(root->left,new ListNode(root->val));
        dfs(root->right,new ListNode(root->val));

        for (int i = 0; i < b.size(); ++i) {
//            ListNode* tmp = map[b[i]];
//            while(tmp!= nullptr){
//                std::cout << tmp->val << " ";
//                tmp = tmp->next;
//            }
//            std::cout << std::endl;
            ret.push_back(map[b[i]]);
        }
        return ret;
    }

    void dfs(TreeNode* root,ListNode* parent_root){
        if (root == nullptr){
            return ;
        }
        ListNode* p_root = parent_root;
        ListNode* tmp_root = new ListNode(p_root->val);
        ListNode* tmp_next = tmp_root;
        p_root = p_root->next;
        while (p_root!= nullptr){
            tmp_next ->next = new ListNode(p_root->val);
            tmp_next = tmp_next ->next;
            p_root = p_root->next;
        }

        tmp_next->next = new ListNode(root->val);
        map[root->val] = tmp_root;

        dfs(root->left,tmp_root);
        dfs(root->right,tmp_root);
    }
};

int main(){

    Solution solution;
    TreeNode* root = new TreeNode(1);
    TreeNode* n_2 = new TreeNode(2);
    TreeNode* n_3 = new TreeNode(3);
    root->left = n_2;
    root->right = n_3;

    TreeNode* n_4 = new TreeNode(4);
    TreeNode* n_5 = new TreeNode(5);

    n_2->left = n_4;
    n_2->right = n_5;

    TreeNode* n_6 = new TreeNode(6);
    TreeNode* n_7 = new TreeNode(7);
    n_3->left = n_6;
    n_3->right = n_7;
    vector<int> input{1,2,3,4,5,6,7};
    solution.solve(root,input) ;


}