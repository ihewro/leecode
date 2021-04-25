//
// Created by hewro on 2021/4/6.
//
#include "Util.hpp"
class Solution {
public:
    vector<vector<int>>  ret;
    void backtrace(vector<int>& nums,int index,vector<int> &path){
        ret.push_back(path);

        if(index == nums.size()){
            return ;
        }

        for(int i=index;i<nums.size();i++){

            path.push_back(nums[i]);
            backtrace(nums,i+1,path);
            path.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> path = {};
        backtrace(nums,0,path);
        return ret;
    }
};
int main(){
    Solution solution;
    vector<int> nums{1,2,3};
    std::find()
    vector_util::print2D(solution.subsets(nums));
}