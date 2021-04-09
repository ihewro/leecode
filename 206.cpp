//
// Created by hewro on 2021/3/13.
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
    ListNode* root;
    ListNode* reverseList(ListNode* head) {
        dfs(head);
        return root;
    }
    //返回反转后的链表的尾节点
    ListNode* dfs(ListNode* head){
        if (head ->next == nullptr){
            root = head;
            return head;
        }
        auto tail = dfs(head->next);
        tail->next = head;
        head->next = nullptr;
        return head;
    }
};






int main(){
    vector<string> ret{};
    SplitString("abaabc",ret,"aa");
    vector_util::print(ret);
//    Solution solution;
//    ListNode* root = link_util::getRootNode({1,2,3,4,5});
//    link_util::print(solution.reverseList(root)) ;




}
