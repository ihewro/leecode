/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/21
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<vector<int>> dp(nums.size(), vector<int>{1, INT_MIN});//[0] 表示长度 [1] 表示最长的递增子序列的额最大值
        dp[0][0] = 1;
        dp[0][1] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > dp[i - 1][1]) {//递增子序列增加
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = nums[i];
            } else {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1];
            }
        }

        return dp[nums.size() - 1][0];
    }
};


int main() {
    Solution solution;
    vector<int> input{10,9,2,5,3,7,101,18};
    std::cout << solution.lengthOfLIS(input) << std::endl;
}