//
// Created by hewro on 2021/3/21.
//

#include "bits/stdc++.h"
using namespace std;
vector<long>memo;
int dp_helper(int x);
int dp(int x){
    if (x == 0){
        return 0;
    }
    long ret_1 = dp_helper(x-1);
    long ret_2 = (x % 2==0) ? dp_helper(x/2) : INT_MAX;
    long ret_3 = (x % 3==0) ? dp_helper(x/3) : INT_MAX;
    return std::min(std::min(ret_1,ret_2),ret_3) + 1;
}

int dp_helper(int x){
    if (x == 0){
        return 0;
    }
//    std::cout << x << std::endl;

    if (memo[x] != -1){
        return memo[x];
    }
    int ret = dp(x);
    memo[x] = ret;
    return ret;

}
int main(){
    int T;scanf("%d",&T);
    while (T > 0){
        long n;
        cin >> n;
        memo.resize(n+1,-1);
        std::cout << dp_helper(n) << std::endl;
        T--;
    }
}

