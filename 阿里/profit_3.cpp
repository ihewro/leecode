//
// Created by hewro on 2021/3/15.
//
#include "Util.hpp"

int target = 3;
const long long mod=1e9+7;
int getSuitedProfitWays(vector<int> works,vector<int> profit,int work_num){
    if (works.empty()){
        return 0;
    }
    vector<vector<vector<int>>> dp(works.size()+1,vector<vector<int>>(work_num+1,vector<int>(200,0)));//index->{work_num->{target_1,target_2..}}

    if (works.size()==1){
        if (work_num >= works[0] && profit[0] >= target){
            return 1;
        }else{
            return 0;
        }
    }
    //工人人数超过works[works.size()-1]，并且收益要求小于profit[works.size()-1]，都可以完成
    for (int i = works[works.size()-1]; i <= work_num ; ++i) {
        for (int j = 0; j <= profit[works.size()-1]; ++j) {
            dp[works.size()-1][i][j] = 1;
        }
    }

    //如果收益要求是 0，那么不管工人多少，都可以完成
    for (int i = 0; i <= work_num; ++i) {
        dp[works.size()-1][i][0] = 1;
    }

    for (int i = works.size()-2; i >=0 ; i--) {
        for (int j = 0; j <= work_num ; ++j) {
            for (int k = 0; k <= target; ++k) {
                if (j >= works[i]){//当前工作可以做
                    std::cout<<"dp["<<i<<"]["<<j<<"]["<<k<<"] = "<<"dp["<<i+1<<"]["<<j-works[i]<<"]["<<k-profit[i]<<"] + dp["<<i+1<<"]["<<j<<"]["<<k<<"]"<<std::endl;
                    int current_do = dp[i+1][j-works[i]][std::max(0,k-profit[i])];//当前工作做
                    int current_not_do = dp[i+1][j][k];//当前工作不做
                    dp[i][j][k] = ((profit[i] >=k) ? 1 + current_do : current_do)//如果当前做了就满足了收益，那么到当前位置截止就是一种方式
                                  + current_not_do;//当前工作不做
                }else{//当前工作做不了
                    dp[i][j][k] = dp[i+1][j][k];
                }
            }
        }
    }


    std::cout<<dp[1][3][1]<<std::endl;
    std::cout<<dp[1][5][3]<<std::endl;

    return dp[0][work_num][target];



}

int main(){

    vector<int> works {2,2};
    vector<int> profit {2,3};
    int work_num = 5;
    //expect print 2
    std::cout<<getSuitedProfitWays(works,profit,work_num)<<std::endl;

}

