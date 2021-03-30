/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/5
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {

        if (s.empty()){
            return 0;
        }
        int left = 0;
        int right = 0;
        for (right = 0; right < s.size(); right++) {
            int temp_cost = abs(s[right] - t[right]);
            if (maxCost >= temp_cost){
                maxCost -= temp_cost;
            }else{
                maxCost += abs(s[left] - t[left]);
                maxCost -= temp_cost;
                left++;
            }
        }
        return right - left;
    }

};


int main() {
    Solution solution;
    std::cout << solution.equalSubstring("abcd","acde",0) << std::endl;
}