/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/1
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"
class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        int ret = dp_helper(n,memo);
//        vector_util::print(memo);

        return ret;
    }

    int dp_helper(int n,vector<int>& memo){
        if (memo[n] != -1){
            return memo[n];
        }

        int ret = dp(n,memo);
        memo[n] = ret;
        return ret;
    }
    int dp(int n,vector<int>& memo){
        if (n <= 0){
            return 1;
        }
        if (n==1){
            return 1;
        }

        int n_1 = dp_helper(n -1,memo);
        int n_2 = dp_helper(n-2,memo);

        return n_1 + n_2;
    }


};


int main() {
    Solution solution;
    std::cout << solution.climbStairs(5) << std::endl;
}