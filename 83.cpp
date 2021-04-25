//
// Created by hewro on 2021/4/14.
//

#include "Util.hpp"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* prev = head;
        ListNode* current = head->next;

        while(current!=nullptr){
            if(prev->val == current->val){
                prev->next = current->next;
                prev = prev->next;
                if(prev==nullptr){
                    current = nullptr;
                }else{
                    current = prev->next;
                }
            }else{
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
};

int main(){
    Solution solution;
    auto head = link_util::getRootNode({1,2,3,4});
    link_util::print(solution.deleteDuplicates(head));

}