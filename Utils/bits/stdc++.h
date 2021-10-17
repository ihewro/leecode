#pragma once
/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/8
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <thread>
#include <algorithm>
#include<math.h>
#include <queue>
#include <stack>
#include <numeric>
#include <array>
#include <sstream>
#include <iomanip>

using std::queue;
using std::vector;
using std::unordered_set;
using std::unordered_map;
using std::min;
using std::cin;

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

//#include <stream.h>
using std::vector;
using std::list;
using std::string;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class vector_util{
public:
    template<typename T>
    static void print(const vector<T>& input){
        std::cout << "[";
        for (auto item:input){
            std::cout << item << ",";
        }
        std::cout << "]" << std::endl;

    }

    template<typename T>
    static void print_2(const vector<vector<T>>& input){
        std::cout << "[";
        for (auto item:input){
            print(item);
//            std::cout << item << ",";
        }
        std::cout << "]" << std::endl;

    }
    template<typename T>
    static void print2D(vector<vector<T>> vectors) {
        for (auto vector: vectors) {
            vector_util::print(vector);
        }
    }
};

class MAP_VALUE{
    int num;
public:
    MAP_VALUE(int num) : num(num) {}

    virtual string print() const {return "nothing";};
};
class map_util{
public:
    template<typename T,typename U>
    static void print(const std::unordered_map<T,U>& input){
        std::cout << "[";
        for (auto &item:input){
            std::cout << "key:" << item.first << "value:" << item.second<<"," << std::endl;
        }
        std::cout << "]" << std::endl;

    }
};

class link_util{
public:
    static ListNode* getRootNode(vector<int> nodeList){
        ListNode* root = nullptr;
        ListNode* next = nullptr;

        for (auto item: nodeList) {
            if (root == nullptr){
                root = new ListNode(item);
                next = root;
            }else{
                next->next = new ListNode(item);
                next = next->next;
            }
        }
        next->next = nullptr;
        return root;
    }
};

class tree_util{
private:
    static TreeNode* dfs(vector<int>& nodeList,int head){
        if (head >= nodeList.size() || nodeList[head] == INT_MAX){
            return nullptr;
        }
        auto root = new TreeNode(nodeList[head]);
        auto left = dfs(nodeList,head+1);
        auto right = dfs(nodeList,head+2);
        root->left = left;
        root->right = right;
        return root;
    }
public:
    // error
    static TreeNode* getRootNode(vector<int> nodeList){
        return dfs(nodeList,0);
    }
    static void print_preorder(TreeNode* root){
        if (root == nullptr){
            return;
        }
        std::cout << root->val << ",";
        if (root->left == nullptr && root->right == nullptr){
            return ;
        }else{
            if (root->left == nullptr){
                std::cout << "null" << ",";
                print_preorder(root->right);
            }else if (root->left== nullptr){
                print_preorder(root->left);
                std::cout << "null" << ",";
            }else{
                print_preorder(root->left);
                print_preorder(root->right);
            }
        }
    }
};