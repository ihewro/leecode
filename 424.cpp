/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/2
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.empty()){
            return 0;
        }
        int left = 0;
        int right;
        int history_max = 1;//滑动窗口初始大小为1
        std::unordered_map<char,int> map{};//记录滑动窗口中的字母重复次数
        map[s[0]] = 1;
        for (right= 1; right < s.size(); ++right) {
            //更新窗口中的字母重复次数
            if (map.count(s[right]) > 0){
                map[s[right]]++;
            }else{
                map[s[right]] = 1;
            }
            history_max = std::max(history_max,map[s[right]]);//更新max
            if (history_max + k > right - left ){//扩张，right - left = 之前的滑动窗口大小
                //right每次++ ，如果left不变化，就是扩张了
            }else{//滑动
                map[s[left]] --;
                left ++;
            }
        }

        return right - left;

    }
};

int main() {
    Solution solution;
}