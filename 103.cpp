/**
  * User: hewro
  * Date: 2020/12/22
  * Time: 11:30
  * Description: 
  */
//
// Created by hewro on 2020/12/22.
//

#include <iostream>
#include <utility>
#include <vector>
#include <map>

using std::vector;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isNormal = true;

    vector<vector<int>> ret;
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        traverse(root,1);
        return ret;
    }

    void push_back(int position, int level,int value){
        if (level % 2 ==0 ){//ż���㣬ÿ����ӵ���ͷ ��ʵ���������Ĳ�α�����ֻ������ӵĵ�����Ŀ�ͷ��һ������
            ret[position].insert(ret[position].begin(),value);
        }else{
            ret[position].push_back(value);
        }

    }
    void traverse(TreeNode *root,int level){
        //base case
        if (root == nullptr){
            return ;
        }
        if (level > ret.size()){
            ret.emplace_back();
            push_back(ret.size()-1,level,root->val);
        }else if (level == ret.size()){//ֱ����
            push_back(ret.size()-1,level,root->val);
        }else{
            push_back(level - 1,level,root->val);
        }


        traverse(root->left, level+1);
        traverse(root->right, level+1);

    }
};


void createTree(TreeNode* root, vector<int> nodes){
    //����ͷ�ڵ�
    for (int i = 0; i < nodes.size(); ++i) {
    }
    root = new TreeNode(nodes[0]);



}
int main (){
    //����������
    vector<int> nodes{3,9,20,-1,-1,15,7};
    TreeNode *root = nullptr;
    createTree(root,nodes);


}
