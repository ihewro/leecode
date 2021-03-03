/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/9
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:

    int memo[100001][2][3];

    int maxProfit(vector<int>& prices) {
        //µü´ú
//        std::unordered_map<std::string,int>memo;

        //³õÊ¼»¯base case
        int last = prices.size() -1;
        putValue(last, 1, 0,prices[last]);
        putValue(last, 1, 1,prices[last]);
        putValue(last, 0, 0,0);
        putValue(last, 0, 1,0);
        putValue(last, 0, 2,0);

        for (int i = last-1; i >= 0; i--) {

            putValue(i, 1, 0,std::max(prices[i] + memo[i + 1][0][0],memo[i + 1][1][0]));
            putValue(i, 1, 1,std::max(prices[i] + memo[i + 1][0][1],memo[i + 1][1][1]));
            putValue(i, 0, 0, memo[i + 1][0][0]);
            putValue(i, 0, 1,std::max(-prices[i] + memo[i + 1][1][0],memo[i + 1][0][1]));
            putValue(i, 0, 2,std::max(-prices[i] + memo[i + 1][1][1],memo[i + 1][0][2]));
        }

//        for (auto item: memo) {
//            std::cout << "key:" << item.first << "value:" <<item.second << std::endl;
//        }
        return memo[0][0][2];
    }
    void putValue(int begin, int isHave, int times,int value){
        memo[begin][isHave][times] = value;
    }
};

int main(){
    Solution solution;
//    std::vector<int> input{1,2,3,4,5};
    std::vector<int> input{3,3,5,0,0,3,1,4};
    std::cout << solution.maxProfit(input) << std::endl;

}