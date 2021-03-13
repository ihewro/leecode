/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/21
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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* root = nullptr;
        ListNode* next = nullptr;
        while (l1 != nullptr && l2 != nullptr){

            ListNode* choice;
            if (l1->val < l2->val){
                choice = l1;
                l1 = l1->next;
            }else{
                choice = l2;
                l2 = l2->next;
            }
            if (root == nullptr){
                root = choice;
                next = root;
            }else{
                next->next = choice;
                next = next->next;
            }
        }
        if (l1== nullptr){
            if (root == nullptr){
                root = l2;
            }else{
                next->next = l2;
            }
        }else{
            if (root == nullptr){
                root = l1;
            }else{
                next->next = l1;
            }
        }
        return root;
    }
};

int main() {
    Solution solution;

    vector<int> input{1,2,3,4};
    ListNode* l1 = link_util::getRootNode(input);

    while (l1 != nullptr){
        std::cout << l1->val << std::endl;
        l1 = l1->next;
    }

}