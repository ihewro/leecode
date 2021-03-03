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

    std::unordered_map<std::string,int>memo;

    int maxProfit(vector<int>& prices) {
//        memset(memo, -1, sizeof(int)*100000);//这里的100001是数组大小，需要多少替换下就可以了。
        return dp_helper(prices,0,0,2);
    }
    /**
     *
     * @param begin 第几天开始
     * @param isHave 当前是否拥有股票
     * @param times 剩余的可买入股票的次数
     * @return
     */
    int dp(vector<int>& prices,int begin,bool isHave,int times){
        //base case
        if (begin == prices.size() - 1){//最后一天或者是没有交易次数了
             return isHave ? prices[begin] : 0;
        }

//        if (times == 0){//交易次数为0
//            if (isHave){//持有股票，则价值为序列之后的股价的最大值
//                int max = 0 ;
//                for (int i = begin; i < prices.size() ;i++){
//                    if (prices[i] > max){
//                        max = prices[i];
//                    }
//                }
//                return max;
//            }else{//不持有股票，这价值为0
//                return 0;
//            }
//        }

        //递归计算该序列的价值
        if (isHave){
            //可以选择不操作或者卖出股票
            return std::max(
                    dp_helper(prices,begin+1, 1, times),
                    dp_helper(prices,begin+1, 0, times) + prices[begin]
                    );
        }else{
            //可以选择买入股票或者不操作
            if (times > 0){//可以选择买入，或者不操作
                return std::max(
                        dp_helper(prices,begin+1,1,times-1) - prices[begin],
                        dp_helper(prices,begin+1,0,times)
                        );
            }else{
                return dp_helper(prices,begin+1,0,0);
            }
        }
    }

    int dp_helper(vector<int>& prices,int begin,int isHave,int times){
        auto key = generateKey(begin,isHave,times);
        if (memo.count(key) > 0){//查询备忘录
            std::cout <<"get memo" << std::endl;
            return memo[key];
        }
        int ret = dp(prices,begin,isHave,times);
        memo[key] = ret;
        return ret;
    }

    static std::string putValue(int begin, int isHave, int times){
//        int key=  std::stoi(std::to_string(begin) + std::to_string(isHave) + std::to_string(times));
        return std::to_string(begin) + std::to_string(isHave) + std::to_string(times);
//        return key;
    }
};

int main(){
    Solution solution;
    std::vector<int> input{1,3,2,4,7};
//    std::vector<int> input{1};
    std::cout << solution.maxProfit(input) << std::endl;
}