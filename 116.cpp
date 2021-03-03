/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/23
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr){
            return nullptr;
        }
        connectTwoNode(root->left,root->right);
        return root;
    }

    void connectTwoNode(Node* left, Node* right){
        if (left == nullptr || right == nullptr){
            return ;
        }

        left->next = right;

        connectTwoNode(left->left,left->right);
        connectTwoNode(right->left,right->right);
        connectTwoNode(left->right,right->left);
    }
};

int main() {
    Solution solution;
}