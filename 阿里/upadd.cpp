//
// Created by hewro on 2021/3/19.
//

#include "bits/stdc++.h"

int up_add(vector<int> input,vector<int> b_nums){
    vector<vector<int>> dp(input.size(),vector<int>(3,INT_MAX));//0存储递增子序列长度 为 1 的和，1 存在长度为 2 的和，2 存储长度为 3 的和
    dp[0][0] = b_nums[0];
    int min = INT_MAX;
    for (int i = 1; i < input.size(); ++i) {
        dp[i][0] = b_nums[i];

        for (int j = i-1; j >=0 ; --j) {

            if (dp[j][0] !=INT_MAX && input[i] >= input[j]){
               dp[i][1] = std::min(dp[j][0]+b_nums[i], dp[j][1]);
            }
            if (dp[j][1] !=INT_MAX && input[i] >= input[j]){
                dp[i][2] = std::min(dp[j][1]+b_nums[i], dp[j][2]);
            }
        }
        min = std::min(min,dp[i][2]);
    }
    return min == INT_MAX ? -1 : min;
}
int main(){
//    int m;scanf("%d",&m);
//    int n;scanf("%d",&n);
//
//    vector<int>input(n);
//    for (int i = 0; i < n; ++i) {
//        int temp;scanf("%d",&temp);
//        input.push_back(temp);
//    }

    std::cout << up_add({9,8,6,7,7,2,9,2},{9,1,10,8,6,4,8,6}) << std::endl;


}