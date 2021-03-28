//
// Created by hewro on 2021/3/27.
//

/**
 * 选择一棵树后，右侧编号减少 1，左侧编号不变，确保奇数编号的数值和 == 偶数编号的数值和
 * dp[i][0] 表示偶数和
 * dp[i][1] 表示奇数和
 * dp[i][0] = dp[i]
 * i-1 在 i 的左侧，对于 dp[i] 来说，i-1的序号不变，dp[i]比 dp[i-1] 多了一个 num[i-1] 少了一个 num[i]，我们减掉就行了
 * @return
 */
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n; scanf("%d",&n);
    vector<vector<int>>dp(n+1,vector<int>(2,0));
//    dp[1][]
    vector<int> nums(n+1);
    for (int i = 1; i <= n; ++i) {
        int hi;scanf("%d",&hi);
        nums[i] = hi;
        if (i==1){
            continue;
        }
        bool isEven = (i % 2 !=0);//右侧序号是奇数最后才是偶数
        if (isEven){
            dp[1][0] += hi;
        }else{
            dp[1][1] += hi;
        }
    }

    int count = 0;
    vector<int> ret;
    if (dp[1][0] == dp[1][1]){
        count ++;
        ret.push_back(1);
    }
    //构建 dp 数组
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
        if (i % 2 ==0){//i 是偶数
            dp[i][1] = dp[i][1] - nums[i];//对 i-1来说是奇数
            //i-1 是奇数
            dp[i][1] += nums[i-1];
        }else{//i 是奇数
            dp[i][0] = dp[i][0] - nums[i];//对 i-1来说是偶数
            //i-1是偶数
            dp[i][0] += nums[i-1];
        }
        if (dp[i][0] == dp[i][1]){
            count ++;
            ret.push_back(i);
        }
    }

    //-----print ret
    printf("%d\n",count);
    for (int i : ret) {
        printf("%d ",i);
    }


}