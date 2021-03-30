/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/20
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"




class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0,right =0;
        std::unordered_set<char> window;
        int max=0;
        while(right < s.size()){
            auto r = s[right];
            right ++;
            //判断是否需要收缩
            if (window.count(r) > 0){
                while(window.count(r) > 0){
                    auto l = s[left];
                    left++;
                    window.erase(l);
                }
            }

            //扩张后更新窗口性质
            window.insert(r);
            max = std::max(max,(int)window.size());
        }
        return max;

    }
};
int main() {
    Solution solution;
    std::cout << solution.lengthOfLongestSubstring("aab") << std::endl;
}