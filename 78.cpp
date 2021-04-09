//
// Created by hewro on 2021/4/6.
//
#include "Util.hpp"
class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path{};
        backtrace(nums,path);
        return ret;
    }

    void backtrace(vector<int>& nums, vector<int> path){
        ret.push_back(path);
        for(int i = 0;i < nums.size();i++){
            if(!path.empty() && nums[i] < path.back()){
                continue;
            }
            if(std::find(path.begin(),path.end(),nums[i]) == path.end()){
                path.push_back(nums[i]);
                backtrace(nums,path);
                path.pop_back();
            }
        }
        //base case

    }
};

int main(){
    Solution solution;
    vector<int> nums{1,2,3};
    vector_util::print2D(solution.subsets(nums));
}