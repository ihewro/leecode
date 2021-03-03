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

    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ret{};

        if (root == nullptr){
            return ret;
        }
        vector<TreeNode *> mList{root};
        while (mList.size() > 0){
            vector<int> curr{};//�洢��ǰ��Ľڵ�ֵ�б�
            int len = mList.size();
            while (len > 0) {
                //��ͷȡ��Ԫ��
                if (ret.size() % 2 == 0){
                    curr.push_back(mList[0]->val);
                }else{
                    curr.insert(curr.begin(),mList[0]->val);
                }

                if (mList[0]->left!= nullptr){
                    mList.push_back(mList[0]->left);
                }
                if (mList[0]->right != nullptr){
                    mList.push_back(mList[0]->right);
                }
                mList.erase(mList.begin());
                len--;
            }
            ret.push_back(curr);
        }

        return ret;
        
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
