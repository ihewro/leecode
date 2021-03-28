//
// Created by hewro on 2021/3/27.
//

/**
 * 异或运算
 * 可能思路  动态规划
 * dp[i] = std::max(dp[i-1] ^ nums[i], dp[i-1]) dp[i] 表示以 i 结尾的子序列
 * @return
 */
#include "bits/stdc++.h"
using namespace std;
//32 124   6
int main(){
    int n;int k;
    scanf("%d %d",&n,&k);

    vector<int>dp_last(k+1,-1);

    //dp 初始化
    int ai; scanf("%d",&ai);
    dp_last[1] = ai;
    int max = ai;

    for (int i = 1; i < n; ++i) {
        int ai; scanf("%d",&ai);
        int max_temp = -1;
        for (int j = k; j >=1; --j) {
            dp_last[j] = std::max(dp_last[j-1] ^ ai, ai);
            if (dp_last[j] > max_temp){
                max_temp = dp_last[j];
            }
        }
        if (max_temp > max){
            max = max_temp;
        }
    }

    printf("%d\n",max);

}