//
// Created by hewro on 2021/3/21.
//

#include "bits/stdc++.h"
#include <math.h>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 你需要返回m个指针，第i个指针指向一条链，表示第i个问题的答案
     * @param root TreeNode类 指向链表树的根
     * @param b int整型vector 表示每个问题是什么
     * @return ListNode类vector
     */
    vector<ListNode*> solve(TreeNode* root, vector<int>& b) {
        // write code here
        ListNode* list_root = new ListNode(root->val);
        vector<ListNode*> ret(0);//存储链表的头结点

        queue<TreeNode*> queue;
        queue.push(root);
        ret.push_back(list_root);



        int level = 1;

        //两个子节点使用同一个父亲的路径
        while (!queue.empty()){
            int size = queue.size();
            int i = pow(2,level) - 2;
            while (size > 0){
                auto node_left = queue.front();queue.pop();
                queue.push(node_left->left);
                queue.push(node_left->right);


                auto prefix = ret[i];
                ListNode* tmp_root_left = new ListNode(prefix->val);
                ListNode* tmp_next_left = tmp_root_left;
                prefix = prefix->next;
                while (prefix!= nullptr){
                    tmp_next_left ->next = new ListNode(prefix->val);
                    tmp_next_left = tmp_next_left ->next;
                    prefix = prefix->next;
                }
                tmp_next_left->next = new ListNode(node_left->left->val);
                ret.push_back(tmp_root_left);


                if (level ==1){
                    size --;
                    continue;
                }
                auto node_right = queue.front();queue.pop();
                queue.push(node_right->left);
                queue.push(node_right->right);
                prefix = ret[i];
                ListNode* tmp_root_right = new ListNode(prefix->val);
                ListNode* tmp_next_right = tmp_root_right;
                prefix = prefix->next;
                while (prefix!= nullptr){
                    tmp_next_right ->next = new ListNode(prefix->val);
                    tmp_next_right = tmp_next_right ->next;
                    prefix = prefix->next;
                }

                tmp_next_right->next = new ListNode(node_left->right->val);
                ret.push_back(tmp_root_right);



                size = size - 1;
                i++;
            }
            level++;
        }


        return ret;

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
    std::cout << pow(2,3) ;
}