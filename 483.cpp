//
// Created by hewro on 2021/10/15.
//
#include "bits/stdc++.h"
class Solution {
    long long num;
public:
    long long getValue(long long k,int m){
        long long ret = 0;
        for(int i = 0;i<m;i++){
            if (ret > (num - 1) / k){// ??????
                return LONG_LONG_MAX;
            }
            ret = ret*k + 1;
        }
        return ret;
    }

    string smallestGoodBase(string n) {
        num = std::atoll(n.c_str());
        long long ans = LONG_LONG_MAX;
        for(int i = 1;i<=64;i++){
            long long left = 2;
            long long right = num;

            while(left <= right){
                long long mid = (left + right) / 2;
                long long ret = getValue(mid, i);

                if (ret == num) {
                    ans = std::min(ans,mid);
                    break;
                }else if (ret < num){
                    left = mid+1;
                }else if (ret > num){
                    right = mid-1;
                }
            }
        }
        return std::to_string(ans);
    }
};

int main(){
//    std::cout << LONG_MAX;
    Solution solution;
    std::cout << solution.smallestGoodBase("1000000000000000000") << std::endl;

}