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


//dp ����¼

class Solution {
public:
    int cal_num = 0;
private:
    int mSize;
public:
    int maxProfit(vector<int> prices, int fee) {
        mSize = prices.size();
        vector<vector<int>> memo(mSize+1,vector<int>(2));
        memo.at(1)[1] = prices[mSize - 1] - fee;

        for (int i = 2; i <= mSize; ++i) {
            int first = prices[mSize-i];
            memo.at(i)[0] = std::max(memo.at(i-1)[1] - first,memo.at(i-1)[0]);
            memo.at(i)[1] = std::max(memo.at(i-1)[1],memo.at(i-1)[0] + first -fee);
        }
        return memo.at(mSize)[0];
    }

};

int main(){
    Solution solution;
    vector<int> prices = {1,3,2,8};
    int fee = 2;
    std::cout << solution.maxProfit(prices,fee) << std::endl;
}