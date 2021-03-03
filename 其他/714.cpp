/**
  * User: hewro
  * Date: 2020/12/17
  * Time: 16:40
  * Description: 
  */
//
// Created by hewro on 2020/12/17.
//
#include <iostream>
#include <utility>
#include <vector>
#include <map>
using std::vector;


//dp 备忘录

class Solution {
public:
    int cal_num = 0;

private:
    std::map<std::pair<int,bool>,int> memo{};
    int fee_value = 2;
    bool isFirst = true;
    vector<int> mPrices;
    int mSize;

public:
    int maxProfit(vector<int> prices, int fee) {
        this->mPrices = prices;
        mSize = prices.size();
        fee_value = fee;
        memo.clear();
        isFirst = true;
        return dp(0,0);
    }
    int dp(int position,int isHave){
        vector<vector<int>> memo(mSize+1,vector<int>(2));
        return dp_helper(memo,position,isHave);
    }

    int dp_helper(vector<vector<int>> memo, int position,int isHave){

        //备忘录
        if (memo[position][isHave] !=0){
            return memo[position][isHave];
        }else{
            //设置base case
            if (position == mSize -1){
                return (isHave) ? this->mPrices[position] - fee_value : 0;
            }
            //递归查找
            if (isHave == 1){
                memo[position][1] = std::max(this->mPrices[position] - fee_value + dp_helper(memo,position+1,0),
                                                  dp_helper(memo,position+1,1));
                return memo[position][1];
            }else{
                memo[position][0] = std::max(-this->mPrices[position]  + dp_helper(memo,position+1,1),
                                                  dp_helper(memo,position+1,0));
                return memo[position][0];
            }
        }
    }
};

int main(){
    Solution solution;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    std::cout << solution.maxProfit(prices,fee) << std::endl;


    vector<vector<int>> memo(mSize+1,vector<int>(2));//增加备忘录
    /**
    * position 子序列第一个元素在主序列中的位置
    */
    dp(int position,int isHave){
        // 设置base case
        if (position == size-1){
            return isHave ? prizes[position] - fee : 0;
        }
        //查询备忘录
        if (memo[position][isHave] !=0){
            return memo[position][isHave];
        }else{
            //递归查找
            if (isHave == 1){
                memo[position][1] = std::max(this->mPrices[position] - fee_value + dp_helper(memo,position+1,0),
                                             dp_helper(memo,position+1,1));
                return memo[position][1];
            }else{
                memo[position][0] = std::max(-this->mPrices[position]  + dp_helper(memo,position+1,1),
                                             dp_helper(memo,position+1,0));
                return memo[position][0];
            }

        }

    }