//
// Created by hewro on 2021/4/20.
//

#include "Util.hpp"
class Solution {
public:
    //返回合并后的根节点
    ListNode* mergeTwoList(ListNode*p, ListNode* q){
        auto* head = new ListNode(0);
        ListNode* pHead = head;


        while(p!=nullptr || q!=nullptr){
            auto pv = (p != nullptr) ? p->val : INT_MAX;
            auto qv = (q != nullptr) ? q->val : INT_MAX;
            if(pv < qv){
                pHead->next = p;
                p = p->next;
            }else{
                pHead->next = q;
                q = q->next;
            }
            pHead = pHead->next;
        }
        return head->next;
    }

    // 返回数组合并好的根节点
    ListNode* merge(vector<ListNode*>& lists,int start,int end){
        if (start >= end){//数组只有一个元素的时候
            return lists[start];
        }
        int mid = (start + end) / 2;
        return mergeTwoList(merge(lists,start,mid),merge(lists,mid+1,end));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists,0,lists.size()-1);
    }
};

int main(){
    vector<ListNode*> lists {link_util::getRootNode({1,4,5}),
                      link_util::getRootNode({1,3,4}),
                      link_util::getRootNode({2,6})};

    Solution solution;
    link_util::print(solution.mergeKLists(lists));
}