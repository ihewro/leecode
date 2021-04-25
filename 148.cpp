//
// Created by hewro on 2021/4/20.
//
#include "Util.hpp"


class Solution {
public:
    //合并两个有序链表
    ListNode* mergeTwoList(ListNode*first, ListNode* second){
        ListNode* head = new ListNode(0);
        ListNode* phead = head;

        while(first!= nullptr || second!= nullptr){
            int first_value = (first != nullptr) ? first->val : INT_MAX;
            int second_value = (second!=nullptr) ? second->val : INT_MAX;
            if(first_value < second_value){
                phead->next = first;
                first = first->next;
            }else{
                phead->next = second;
                second = second->next;
            }
            phead = phead->next;
        }
        return head->next;
    }
    //返回的节点指向k+1位置
    ListNode* findK_1thNode(ListNode* head,int k){
        ListNode* pHead = head;
        while(k > 0){
            k--;
            if(pHead == nullptr){
                return pHead;
            }
            pHead = pHead->next;
        }
        return pHead;
    }

    ListNode* mergeSort(ListNode* head,int len){
        //终止条件要注意！
        if(head == nullptr || head->next == nullptr || len <=1){
            if (head != nullptr){//这个地方非常重要，需要把头结点的末尾指向空，不然 mergeTwoList 时候会死循环！
                head->next = nullptr;
            }
            return head;
        }
        int mid = len / 2;
        ListNode* second_head = findK_1thNode(head,mid);
        return mergeTwoList(mergeSort(head, mid),mergeSort(second_head, len - mid));

    }
    std::stack<TreeNode*> s;
    while(!s.empty() || root != nullptr){
        while(root != nullptr){//递归操作
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();//递归返回
        root = root->right;
        while(root != nullptr){//递归操作
            s.push(root);
            root = root->left;
        }

    }
    ListNode* sortList(ListNode* head) {
        int len = 0;
        ListNode* phead = head;
        while(phead!=nullptr){
            phead = phead->next;
            len ++;
        }
        return mergeSort(head,len);
    }
};

int main (){
    Solution solution;
    link_util::print(solution.sortList(link_util::getRootNode({4,2,1,3})));
}