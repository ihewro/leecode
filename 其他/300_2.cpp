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
        if (nums.empty()){
            return 0;
        }
        vector<int> dp(nums.size(),1);

        int max_len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]){
                    dp[i] = std::max(dp[i],dp[j]+1);
                }
            }
            if (dp[i] > max_len){
                max_len = dp[i];
            }
        }
        return max_len;
    }
};


int main() {
    Solution solution;
    vector<int> input{10,9,2,5,3,7,101,18};
    std::cout << solution.lengthOfLIS(input) << std::endl;
}