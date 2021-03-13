/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/20
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        std::unordered_map<char,int> map;
        int max = 0;//当前重复字符的次数
        for (int right = 0; right < s.size();right ++){
            if (map.count(s[right]) > 0){
                map[s[right]]++;
            }else{
                map[s[right]] = 1;
            }
            max = std::max(max,map[s[right]]);

            if (right - left + 1 - max > k){//当前的扩张是不符合条件的，进行滑动
                map[s[left]] --;
                left++;
            }
        }

        return s.size() - left;

    }
};

int main() {
    Solution solution;
    std::cout << solution.characterReplacement("AAAA",0) << std::endl;
}