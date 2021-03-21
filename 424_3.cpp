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
    int characterReplacement(string s, int k) {
        if (s.empty()){
            return 0;
        }
        std::unordered_map<char,int> window;

        int left = 0;
        int right =0;

        int max = 0;//重复字母的次数的最大值

        while (right < s.size()){
            auto r = s[right];
            right++;
            window[r] ++;
            max = std::max(max,window[r]);//todo

            if (right-left - max > k){//只收缩一次，实际上是滑动
                auto l = s[left];
                left++;
                window[l]--;
            }
        }

        return right - left;
    }
};

int main() {
    Solution solution;
}