//
// Created by hewro on 2021/3/27.
//
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k==0 || head== nullptr||head->next == nullptr){
            return head;
        }
        ListNode* p = head;
        int len=0;
        while (p!= nullptr){
            if (p->next != nullptr){
                p=p->next;
            }else{//连成环
                p->next = head;
            }
            len++;
        }

        k = k % len;
        if (k==0){
            return head;
        }
        int move = len - k - 1;
        p = head;
        while (move > 0){
            move --;
            p= p->next;
        }
        auto new_head = p->next;
        p->next = nullptr;
        return new_head;
    }
};

int main(){
    Solution solution;
    std::cout << solution.rotateRight(nullptr,0) << std::endl;
}