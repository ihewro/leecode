#include "bits/stdc++.h"
using namespace std;
int main(){
    int T;scanf("%d",&T);
    while (T > 0){
        long n;
        cin >> n;
        vector<long>dp(n+1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            long ret_1 = dp[i-1];
            long ret_2 = (i % 2==0) ? dp[i/2] : INT_MAX;
            long ret_3 = (i % 3==0) ? dp[i/3] : INT_MAX;
            dp[i] = std::min(std::min(ret_1,ret_2),ret_3) + 1;
        }
        std::cout <<  dp[n] << std::endl;
        T--;
    }

}
