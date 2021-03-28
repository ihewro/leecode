//
// Created by hewro on 2021/3/27.
//

/**
 * 滑动窗口
 * @return
 */
#include "bits/stdc++.h"
using namespace std;
int main(){
    int n,c1,c2;
    cin >> n >> c1 >> c2;

    int min_cost = std::min(c1,c2);
    int left,right=0;//默认窗口大小为 0
    int count = 0;//窗口中 F 的数量
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        char r;cin >> r;
        right++;

        if (r == 'F'){
            count ++;
        }else{//不连续了
            left = right;
            count = 0;
        }
        //需要使用技能
        if (count >=3){
            ret++;
            left = right;
            count = 0;
        }
    }
    std::cout << ret * min_cost << std::endl;
}

}