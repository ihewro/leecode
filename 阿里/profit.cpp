//
// Created by hewro on 2021/3/15.
//
#include "Util.hpp"

int target = 3;
int ways = 0;
void getSuitedProfitWays(int index,vector<int> works,vector<int> profit,int target_,int work_num){
    if (target_ >= target){
//        std::cout << target_ << std::endl;
        ways++;
    }
    if (index > works.size() || work_num <=0){
        return ;
    }

    for (int i = index; i < works.size(); ++i) {
        if (work_num >= works[i]){
            target_ += profit[i];
            getSuitedProfitWays(i+1, works,profit,target_,work_num-works[i]);
            target_ -= profit[i];
        }
    }

}

int main(){

    vector<int> works {2,2,1};
    vector<int> profit {2,3,1};
    int work_num = 5;
    //expect print 3
    getSuitedProfitWays(0,works,profit,0,work_num);
    std::cout << ways << std::endl;

}

