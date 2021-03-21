//
// Created by hewro on 2021/3/15.
//
#include "Util.hpp"

int target = 3;
int ways = 0;
int getSuitedProfitWays(int index,int &target_,int work_num,vector<int> works,vector<int> profit){
    if (index == works.size()-1){
        if (work_num >= works[index]){
            return 1;
        }else{
            return 0;
        }
    }
    target_ += profit[index];
    int current_do = getSuitedProfitWays(index+1,target_,work_num-works[index],works,profit);
    int current_not_do = getSuitedProfitWays(index+1,target_,work_num,works,profit);

    return current_do + current_not_do;

}

int main(){

    vector<int> works {2,2,5};
    vector<int> profit {2,3,5};
    int work_num = 5;
    //expect print 2
    std::cout << getSuitedProfitWays(0,0,work_num,works,profit) << std::endl;

}

