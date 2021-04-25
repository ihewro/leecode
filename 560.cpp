//
// Created by hewro on 2021/4/24.
//
#include "Util.hpp"
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //计算 presum 数组
        std::unordered_map<int,int> map;//key 前缀和,value 重复的次数
        map[0] = 1;//这个地方别忘了！！！表示子数组为空的情况
        vector<int> presum (nums.size()+1);
        presum[0] = 0;
        int ans = 0;

        for(int i = 0;i<nums.size();i++){
            presum[i+1] = nums[i]+presum[i];
            int sum0_j = presum[i+1] - k;
            if(map.count(sum0_j)){
                ans+=map[sum0_j];//此时的 map[sum_j] 统计符号条件的presum[j] 一定不会是 presum[i+1]或者后面的
            }
            map[presum[i+1]]++;
        }

        return ans;
    }
};
int main(){
    Solution solution;
    vector<int> nums{0,0,0};
    std::cout << solution.subarraySum(nums,0);
}