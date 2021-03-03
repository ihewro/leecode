/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/19
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        dp[0] = 0;
        for (int i = 1; i <=num ; ++i) {
            dp[i] = dp[i & (i-1)] + 1
        }
        return dp;

    }
};

int main() {
    Solution solution;
}