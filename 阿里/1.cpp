//
// Created by hewro on 2021/3/22.
//

#include "bits/stdc++.h"
using namespace std;
unordered_map<int,int> memo;
bool backtrace(int index,int sum,vector<int>w_list){
    if (memo.count(sum) > 0){
        return memo[sum];
    }
    if (sum == 0){
        memo[sum] = false;
        return true;
    }
    if (index == w_list.size()){
        return false;
    }
    //当前可以选择
    bool ret = backtrace(index + 1,sum - w_list[index],w_list);
    if (ret){
        memo[sum] = true;
        return true;
    }else{
        return backtrace(index + 1,sum,w_list);
    }

}
int main(){
    int num, limit;
    while (cin >> num >> limit){
        vector<int>w_list(num);
        memo.clear();
        for (int i = 0; i < num; ++i) {
            int wi;scanf("%d",&wi);
            w_list[i] = wi;
        }
        if (backtrace(0,limit,w_list)){
            std::cout << "YES" << std::endl;
        }else{
            std::cout << "NO" << std::endl;
        }
    }

}

