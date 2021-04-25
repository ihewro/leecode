//
// Created by hewro on 2021/4/23.
//
#include "Util.hpp"
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,INT_MIN);
        dp[0] = 1;
        dp[1] = 0;
        for(int i = 2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i] = std::max(dp[i], std::max(dp[i-j],i-j) * j);
            }
        }

        vector_util::print(dp);
        return dp[n];

    }
};

int main(){
    Solution solution;
    solution.integerBreak(10);

}