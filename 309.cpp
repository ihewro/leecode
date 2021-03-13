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
    vector<int> prices;
    int maxProfit(vector<int>& prices) {
        if (prices.empty()){
            return 0;
        }

        this->prices = prices;
        vector<vector<int>> memo(prices.size(),vector<int>(3,-1));
        return dp_helper(0,1,memo);
    }

    /**
     *
     * @param index
     * @param status 2 ���У�0 �䶳 1 ������
     * @return
     */
    int dp_helper(int index, int status, vector<vector<int>>& memo){
        if (memo[index][status] != -1){
            return memo[index][status];
        }

        int ret = dp(index, status, memo);
        memo[index][status] = ret;
        return ret;
    }

    int dp(int index, int status, vector<vector<int>>& memo){
        //base case
        if (index == prices.size()-1){
            if (status == 2){
                return prices[index];
            }else{
                return 0;
            }
        }
        switch (status) {
            case 2://ӵ�й�Ʊ
                return std::max(prices[index] + dp_helper(index + 1, 0, memo),
                                dp_helper(index + 1, 2, memo));
            case 1://������
                return std::max(-prices[index] + dp_helper(index+1,2,memo),
                                dp_helper(index+1,1,memo));
            case 0://�䶳
                return dp_helper(index+1,1,memo);
            default:
                break;
        }

        return 0;

    }
};

int main() {
    Solution solution;
}