//
// Created by hewro on 2021/4/1.
//

#include "Util.hpp"
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> visit;
    void backtrace(vector<int>& nums,vector<int>path){
        if(path.size() == nums.size()){
            ret.push_back(path);
            return ;
        }

        for(int i = 0;i<nums.size();i++){
            if(i>=1 && nums[i] == nums[i-1]){
                continue;
            }
            if(visit[i] == 0){
                path.push_back(nums[i]);
                visit[i] = 1;
                backtrace(nums,path);
                path.pop_back();
                visit[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<int> path = {};
        visit.resize(nums.size(),0);
        backtrace(nums,path);
        return ret;
    }
};