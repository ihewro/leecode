/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/18
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        if (nums.empty()){
            return 0;
        }
        dp[nums.size() -1][0] = 0;
        dp[nums.size() -1][1] = nums[nums.size()-1];
        if (nums.size() < 2){
            return dp[0][1];
        }

        for (int i = nums.size() - 2; i >=0 ; --i) {
            dp[i][0] = std::max(dp[i+1][1],dp[i+1][0]);
            dp[i][1] = std::max(dp[i+1][1],nums[i] + dp[i+1][0]);
        }

        return dp[0][1];
    }
};


int main() {
    Solution solution;
    vector<int> input{2,7,9,3,1};
    std::cout << solution.rob(input) << std::endl;
}