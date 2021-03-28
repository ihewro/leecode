//
// Created by hewro on 2021/3/28.
//

#include "bits/stdc++.h"
class Solution {
public:
    int reinitializePermutation(int n) {

        int ret = 0;
        bool flag = true;
        //初始化
        vector<int> perm(n);
        vector<int> arr(n,0);
        for (int i = 0; i < n; ++i) {
            perm[i] = i;
        }
        while (true){
            ret++;
            flag = true;
            for (int i = n-1; i >= 0; --i) {
                if (i % 2 == 0){
                    arr[i] = perm[i / 2];
                }else{
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                }
                if (arr[i] != i){
                    flag = false;
                }
            }

            if (flag){
                break;
            }else{
                std::copy(arr.begin(),arr.end(),perm.begin());
            }
        }

        return ret;


    }
};

int main(){
    Solution solution;
    std::cout << solution.reinitializePermutation(6) << std::endl;
}