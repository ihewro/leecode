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
        int left= 0,right = 0;

        //窗口性质
        int max = -1;//窗口中字母的最大重复次数，窗口大小 - max 必须要 <=k 才能被保证替换掉
        std::unordered_map<char,int> window;//窗口的字符次数统计
        while(right < s.size()){
            auto r = s[right];
            right++;
            //right 右移窗口性质修改
            window[r] ++;
            max = std::max(max,window[r]);

            //判断是否需要收缩
            int size = right - left;
            if (size - max > k){
                //需要收缩
                auto l = s[left];
                left++;

                //窗口收缩后性质修改
                window[l] --;
                //没有修改 max
            }
        }

        return right - left;

    }
};
int main() {
    Solution solution;
    std::cout << solution.characterReplacement("AABABBA",1);
}