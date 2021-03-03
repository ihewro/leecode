/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/15
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (true){
            if (fast != nullptr && fast->next != nullptr && fast->next->next!= nullptr){
                fast = fast->next->next;
            } else{
                return false;
            }

            if (slow!= nullptr && slow->next!= nullptr){
                slow = slow->next;
            }else{
                return false;
            }

            if (fast == slow){
                return true;
            }
        }

        return false;
    }
};