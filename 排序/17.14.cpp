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
        std::priority_queue<int,vector<int>,std::less<>> pq;
        for (auto item: arr) {
            pq.push(item);
            if (pq.size() > k){
                pq.pop();
            }
        }

        vector<int> ret;
        while (!pq.empty()){
            ret.push_back(pq.top());
            pq.pop();
        }

        return ret;

    }
};

int main(){

    Solution solution;
    vector<int> input{1,3,5,7,2,4,6,8};
    vector_util::print(solution.smallestK(input,4));

}