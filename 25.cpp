//
// Created by hewro on 2021/4/7.
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *prev = nullptr;
        auto current = head;
        ListNode *prev_group_head = nullptr;//上一组的尾节点，实际上就是原来链表的上一组的头结点
        ListNode *current_group_head = nullptr;//当前一组的尾节点，实际上就是原来链表的上一组的头结点
        ListNode *new_head = nullptr;
        while (current != nullptr) {

            for (int i = 0; i < k; ++i) {
                if (i == 0){//一组开头的时候
                    current_group_head = current;
                }
                if (current == nullptr){
                    prev_group_head->next = prev;//
                    current_group_head->next = nullptr;//最后一组的第一个节点指向 null，是尾节点
                    break;
                }

                auto next = current->next;
                current->next = prev;
                prev = current;
                current = next;

                if (i == k-1){//一组结尾的时候
                    if (prev_group_head != nullptr){
                        prev_group_head->next = prev;
                    }
                    prev_group_head = current_group_head;//这一组结束了，对于下一组来说，需要修改这个值

                    if (new_head == nullptr){
                        new_head = prev;
                    }
                }

            }

        }
        return new_head;
    }
};

int main() {
    auto head = link_util::getRootNode({1, 2, 3, 4, 5});
    Solution solution;
    link_util::print(solution.reverseKGroup(head, 3));
}