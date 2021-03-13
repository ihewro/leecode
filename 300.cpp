/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/21
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        //[0] 最大子序列长度，[1]该子序列的最大值
        vector<vector<int>> dp(nums.size(), vector<int>{1, INT_MIN});
        dp[0][0] = 1;
        dp[0][1] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > dp[i - 1][1]) {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = nums[i];
            } else {
                dp[i][0] = dp[i - 1][0];
                if (dp[i][0] == 1){
                    dp[i][1] = std::min(dp[i - 1][1],nums[i]);
                }else{
                    dp[i][1] = dp[i - 1][1];
                }
            }
        }

        vector_util::print2D(dp);

        return dp[nums.size() - 1][0];
    }
};


int main() {
    Solution solution;
//    vector<int> input{10,9,2,5,3,7,101,18};
    vector<int> input{0,1,0,3,2,3};
    std::cout << solution.lengthOfLIS(input) << std::endl;
}