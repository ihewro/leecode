//
// Created by hewro on 2021/4/19.
//
#include "Util.hpp"
class Solution {
public:

    vector<vector<int>> ret;
    void backtrace(vector<int>& nums,bool preUse,vector<int> &path,int sum,int index){
        if (path.size() == 3){
            if (sum == 0){
                ret.push_back(path);
            }
            return ;
        }

        if (index == nums.size()){
            return ;
        }

        //如果当前元素和左侧是相同的并且 path 中不存在当前元素，则不添加当前元素
        if(index > 0 && nums[index] == nums[index-1] && !preUse){
            backtrace(nums,false,path,sum,index+1);
            return;
        }
        path.push_back(nums[index]);
        backtrace(nums,true,path,sum+nums[index],index+1);
        path.pop_back();

        backtrace(nums,false,path,sum,index+1);
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());

        vector<int> path{};
        backtrace(nums,false,path,0,0);
        return ret;
    }
};


int N;
void time(int n){
    if (n==N){

    }

}

int main(){
//    Solution solution;
//    vector<int> nums{-2,0,1,1,2};
//    vector_util::print2D(solution.threeSum(nums));

    int N = 10;
    vector<int> dp(N+1);
    dp [N] = 1;
    for (int i = N-1; i >=0 ; --i) {
        dp[i] = std::accumulate(dp.begin() + i-1,dp.end(),0);
    }
    std::cout << dp[0] << std::endl;

    list<int> tmp{};
    vector<int>{tmp.begin(),tmp.end()};
}