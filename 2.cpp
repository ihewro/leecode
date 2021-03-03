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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node_1 = l1;
        ListNode* node_2 = l2;
        ListNode* ret_root = nullptr;
        ListNode* ret_tail = nullptr;

        int extra = 0;
        while (node_1 != nullptr || node_2 != nullptr){
            ListNode* ret_next;

            int temp_1=0,temp_2=0;
            if (node_1!= nullptr){
                temp_1= node_1->val;
                ret_next = node_1;
                node_1 = node_1->next;
            }

            if (node_2!= nullptr){
                temp_2= node_2->val;
                ret_next = node_2;
                node_2 = node_2->next;
            }

            int ret_value = temp_1 + temp_2 + extra;
            if (ret_value >= 10){//¼ÇÂ¼½øÎ»
                ret_value = ret_value % 10;
                extra = 1;
            }else{
                extra = 0;
            }

            std::cout << "ret_value:" << ret_value << std::endl;

            ret_next->val = ret_value;
            ret_next->next = nullptr;

            if (ret_root != nullptr){
                ret_tail->next = ret_next;
                ret_tail = ret_next;
            }else{
                ret_root = ret_next;
                ret_tail = ret_root;
            }
        }

        if (extra == 1){
            ret_tail->next = new ListNode(extra);
        }

        return ret_root;
    }
};


int main() {
    Solution solution;
    ListNode* li_2 = new ListNode(2);
    ListNode* li_4 = new ListNode(4);
    ListNode* li_3 = new ListNode(3);

    li_2->next = li_4;
    li_4->next = li_3;


    ListNode* li_5 = new ListNode(5);
    ListNode* li_6 = new ListNode(6);
    ListNode* li_7 = new ListNode(4);
    li_5->next = li_6;
    li_6->next = li_7;

    solution.addTwoNumbers(li_2,li_5);
}