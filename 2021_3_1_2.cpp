//
// Created by hewro on 2021/3/3.
//

#include "Util.hpp"

/*
 * 整数拆分
 * 从命令行读取一个整数，分解为多个整数之和，并打印所有不同序列，每行一个，比如3：
 * 1+1+1
 * 2+1
 * 3
 */


class Solution{
public:
    std::vector<std::vector<int>> allSum(int n){

        vector<vector<vector<int>>> dp(n+1);
        vector<vector<int>> ret = {{1}};

        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < dp[i-1].size(); ++j) {
                if (dp[i-1][j].back() > 1){
//                    dp[i-1].erase(dp[i-1].begin()+j);
                    dp[i-1][j].push_back(1);
                }else{
                    dp[i-1][j].push_back(1);
                }
            }
            dp[i-1].push_back({1,i-1});
            dp[i-1].push_back({i});
            dp[i] = dp[i-1];
        }
        return dp[n];
    }
};




int main(){
    int n = 7;
    Solution solution;
    vector_util::print2D(solution.allSum(n));
}
