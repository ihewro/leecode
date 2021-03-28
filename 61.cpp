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
        ListNode* left = head;
        ListNode* right = head;
        int len=0;

        //第一次遍历链表
        while (k >0){
            k--;
            if (right!= nullptr){
                right=right->next;
                len++;
            }
            if (right == nullptr){
                right = head;
                break;
            }
        }

        //如果第一次遍历结束 k 没有变成 0，说明 k> 链表的长度
        //此时需要把剩余的 k与 len 进行取模，确保第二次遍历可以结束
        if (k!=0){
            k = k % len;
            while (k >0){
                if (right!= nullptr){
                    right=right->next;
                }
                k--;
            }
        }
        //right位置就是在头部，说明链表不用处理
        if(right == head){return head;}

        //同步移动
        while (right!= nullptr && right->next != nullptr){
            left = left->next;
            right = right->next;
        }
        //[left->next,end) 区间指向头部
        auto new_head = left->next;
        right->next = head;
        left->next = nullptr;
        return new_head;
    }
};

int main(){
    Solution solution;
    std::cout << solution.rotateRight(nullptr,0) << std::endl;
}