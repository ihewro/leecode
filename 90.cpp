//
// Created by hewro on 2021/4/6.
//
#include "Util.hpp"
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> visit;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        visit.resize(nums.size(),0);
        std::sort(nums.begin(),nums.end());
        vector<int> path{};
        backtrace(nums,path);
        return ret;
    }
    void backtrace(vector<int> &nums,vector<int> path){

        ret.push_back(path);
        for(int i =0;i<nums.size();i++){
            if (visit[i] == 1){
                continue;
            }
            if(i> 0 && nums[i-1] == nums[i] && visit[i-1] == 0){
                continue;
            }

            if(!path.empty() && nums[i] < path.back()){
                continue;
            }

            path.push_back(nums[i]);
            visit[i] = 1;
            backtrace(nums,path);
            visit[i] = 0;
            path.pop_back();

        }
    }
};
int main(){
    Solution solution;
    vector<int> nums{0,0,0,0};
    vector_util::print2D(solution.subsetsWithDup(nums));
}