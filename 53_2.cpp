/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/4
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int max = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = std::max(dp[i-1] + nums[i] , nums[i]);
            if (dp[i] > max){
                max = dp[i];
            }
        }

        return max;
    }
};

int main() {


    Solution solution;
}