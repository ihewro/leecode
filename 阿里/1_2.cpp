//
// Created by hewro on 2021/3/22.
//

#include "bits/stdc++.h"
using namespace std;


int main(){
    int num, limit;
    while (cin >> num >> limit){
        vector<int>w_list;
        map<int,int>dp;
        for (int i = 0; i < num; ++i) {
            int wi;scanf("%d",&wi);
            w_list.push_back(wi);
            dp[wi] = true;
        }
        for (int i = 0; i < num; ++i) {
            dp[1] = w_list[i]
        }

    }

}

