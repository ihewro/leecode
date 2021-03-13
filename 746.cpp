/**
  * User: hewro
  * Date: 2020/12/17
  * Time: 16:40
  * Description:
  */
//
// Created by hewro on 2020/12/17.
//
#include <iostream>
#include <utility>
#include <vector>
#include <map>
using std::vector;


class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size());
        //base case
        dp[cost.size()-1] = 0;
        dp[cost.size()-2] = std::min(cost[cost.size()-2,cost.size()-1]);
        for (int i = cost.size()-2; i >=0; i--) {
            dp[i] = std::min(cost[i]+dp[i+1],cost[i+1]+dp[i+2]);
        }
        return dp[0];
    }

};

int main(){
    Solution solution;
    vector<int> cost = {0,0,0,0};
    std::cout << solution.minCostClimbingStairs(cost) << std::endl;
}