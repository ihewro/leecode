/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/2
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy = INT_MAX;
        int sell = 0;
        int ret = 0;


        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < buy){
                buy = prices[i];
            }else{
                sell = prices[i] - buy;
                ret = std::max(ret,sell);
            }
        }

        return ret;


    }
};


int main() {
    Solution solution;
}