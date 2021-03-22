//
// Created by hewro on 2021/3/22.
//

#include "bits/stdc++.h"
using namespace std;
int main(){
    //6
    //6 2 3 4 5 5
    int n;scanf("%d",&n);
    vector<int> nums(n);
    int num = n;

    for (int i = 0; i < n; ++i) {
        int value;scanf("%d",&value);
        nums[i] = value;
    }

    vector_util::print(nums);
    vector<vector<int>>dp(num,vector<int>(num,0));
    //初始化
    for (int i = 0; i < num; ++i) {
        dp[i][i] = 0;
    }

    for (int i = num-1; i >=0; --i) {
        for (int j = i; j < num; ++j) {
            for (int k = i; k < j; ++k) {
                int sum = 0;
                int left = std::accumulate(nums.begin()+i,nums.begin() +k+1,0);
                int right = std::accumulate(nums.begin()+k+1,nums.begin() +j+1,0);


                if (left < right){//dp[k+1][j] 的值+ i~k 的值之和
                    sum = left + dp[i][k];
                }else if (left > right){
                    sum = right + dp[k+1][j];
                } else{
                    sum = left + std::max(dp[i][k], dp[k+1][j]);
                }
                dp[i][j] = std::max(dp[i][j],sum);
            }
        }

    }
    std::cout <<  dp[0][n-1]<< std::endl;
}