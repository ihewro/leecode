/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/23
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        if(head == nullptr){
            return nullptr;
        }

        while (true){
            if (slow->next != nullptr){
                slow = slow->next;
            }else{
                return nullptr;
            }

            if (fast->next != nullptr && fast->next->next != nullptr){
                fast = fast->next->next;
            }else{
                return nullptr;
            }

            if (slow == fast){//快慢指针相遇了
                ListNode * add = head;
                while (true){
                    if (add == slow){
                        return add;
                    }
                    if (add->next != nullptr){
                        add = add->next;
                    }
                    if (slow->next != nullptr){
                        slow = slow->next;
                    }
                }
            }

        }

        return nullptr;
    }
};
