//
// Created by hewro on 2021/4/23.
//
#include "Util.hpp"
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,0));
        //dp[i][j] 表示前 i 个硬币凑够 j 元的组合数目
        for(int i =0;i<=coins.size();i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=coins.size();i++){
            for(int j =1;j<=amount;j++){
                if (j-coins[i-1] >= 0){//这个地方是 i-1!!!
                    dp[i][j] = dp[i][j-coins[i-1]] //这个地方是 dp[i][j-xxx] 不是 i-1，硬币序号是i-1
                            + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[coins.size()][amount];

    }
};

int main(){
    Solution solution;
    vector<int>coins{1,2,5};
    std::cout  << solution.change(5, coins);


}