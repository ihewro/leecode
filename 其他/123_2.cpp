/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/9
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

class Solution {
public:


    int maxProfit(vector<int>& prices) {
        //����
//        int memo[10001][2][3];
        std::unordered_map<std::string,int>memo;

        //��ʼ��base case
        int last = prices.size() -1;
        auto key = generateKey(last,1,0);
        memo[key] = prices[last];

        key = generateKey(last,1,1);
        memo[key] = prices[last];

        key = generateKey(last,0,0);
        memo[key] = 0;

        key = generateKey(last,0,1);
        memo[key] = 0;

        key = generateKey(last,0,2);
        memo[key] = 0;

        for (int i = last-1; i >= 0; i--) {
            std::cout << "end" << std::endl;
            auto key_ = generateKey(i,1,0);
            auto temp_key_1 = generateKey(i+1,0,0);
            auto temp_key_2 = generateKey(i+1,1,0);
            memo[key_] = std::max(prices[i] + memo[temp_key_1],memo[temp_key_2]);

            key_ = generateKey(i,1,1);
            temp_key_1 = generateKey(i+1,0,1);
            temp_key_2 = generateKey(i+1,1,1);
            memo[key_] = std::max(prices[i] + memo[temp_key_1], memo[temp_key_2]);


            key_ = generateKey(i,0,0);
            temp_key_1 = generateKey(i+1,0,0);
            memo[key_] = memo[temp_key_1];

            key_ = generateKey(i,0,1);
            temp_key_1 = generateKey(i+1,1,0);
            temp_key_2 = generateKey(i+1,0,1);
            memo[key_] = std::max(-prices[i] + memo[temp_key_1],memo[temp_key_2]);

            key_ = generateKey(i,0,2);
            temp_key_1 = generateKey(i+1,1,1);
            temp_key_2 = generateKey(i+1,0,2);
            memo[key_] = std::max(-prices[i] + memo[temp_key_1],memo[temp_key_2]);

        }
        key = generateKey(0,0,2);

//        for (auto item: memo) {
//            std::cout << "key:" << item.first << "value:" <<item.second << std::endl;
//        }
        return memo[key];
    }
    static std::string putValue(int begin, int isHave, int times){
//        int key=  std::stoi(std::to_string(begin) + std::to_string(isHave) + std::to_string(times));
        return std::to_string(begin) + std::to_string(isHave) + std::to_string(times);
//        return key;
    }
};

int main(){
    Solution solution;
//    std::vector<int> input{1,2,3,4,5};
    std::vector<int> input{3,3,5,0,0,3,1,4};
    std::cout << solution.maxProfit(input) << std::endl;

}