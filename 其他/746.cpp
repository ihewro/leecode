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
        cost.push_back(0);
        vector<int>dp(cost.size()+1);
        //base case
        dp[cost.size() -1] = 0;
        dp[cost.size()] = 0;
        for (int i = cost.size()-2; i >=0; i--) {
            dp[i] = std::min(cost[i]+dp[i+1],cost[i+1]+dp[i+2]);
        }

        return dp[0];

//        return dp(0);
    }


//    int dp(int position){
//        vector<int> memo(size);
//        return dp_helper(memo,position);
//    }
//
//    int dp_helper(vector<int> memo, int position){
//        //base case
//        if (position == size - 1){
//            return 0;
//        }
//        if (position == size){
//            return 0;
//        }
//        //²éÑ¯±¸ÍüÂ¼
//        if (memo[position] != 0){
//            return memo[position];
//        }else{
//            return std::min(cost[position] + dp_helper(memo, position+1),
//                            cost[position+1] + dp_helper(memo, position+2));
//        }
//
//    }
};

int main(){
    Solution solution;
    vector<int> cost = {0,0,0,0};
    std::cout << solution.minCostClimbingStairs(cost) << std::endl;
}