/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/23
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "Util.hpp"
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr){
            return nullptr;
        }

        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA!= nullptr || pB != nullptr){
            if (pA == pB){
                return pA;
            }
            if (pA == nullptr){
                pA = headB;
            }else{
                pA = pA->next;
            }

            if (pB == nullptr){
                pB = headA;
            }else{
                pB = pB->next;
            }
        }

        return nullptr;


    }
};