//
// Created by hewro on 2021/3/5.
//
#include "Util.hpp"

/**
 * 小顶堆，最小 k 个数
 */
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {

        std::priority_queue<int> q;
        for(int i = 0;i < arr.size();i++){
            if(q.size() == k){
                if(arr[i] < q.top()){
                    q.pop();
                    q.push(arr[i]);
                }
            }else{
                q.push(arr[i]);
            }
        }
        vector<int> ans;
        int size = q.size();
        for(int i=0;i<size;i++){
            ans.push_back(q.top());
            q.pop();
        }

        return ans;
    }
};
int main(){

    Solution solution;
    vector<int> input{1,2,3};
    vector_util::print(solution.smallestK(input,0));

}