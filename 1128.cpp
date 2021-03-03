/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/26
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ret = 0;
        std::unordered_map<int,int> statistic{};
        for (auto item : dominoes){
            int key = std::min(item[0],item[1]) * 10 + std::max(item[0],item[1]);
            if (statistic.count(key) > 0){
                statistic[key] += 1;
            }else{
                statistic[key] = 1;
            }
        }

        for (auto pair: statistic){
            ret += (pair.second * (pair.second - 1)) / 2;
        }
        return ret;
    }

};


int main(){

    Solution solution;
    vector<vector<int>> dominodes{{1,2},{1,2},{2,1},{1,2}};
    std::cout << solution.numEquivDominoPairs(dominodes) << std::endl;


}