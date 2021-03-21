//
// Created by hewro on 2021/3/16.
//
#include "Util.hpp"
class Solution {
public:
    string minWindow(string s, string t) {

        std::unordered_map<char, int> need;//辅助 map
        std::unordered_map<char, int> window;//存储窗口中的字符

        for (char & i : t) {
            need[i]++;
        }
        int left = 0;
        int right = 0;


        int valid = 0;
        int len = INT_MAX;
        int start= 0;
        while (right < s.size()){
            auto c = s[right];//即将移入窗口中的字符
            right++;//扩张

            //扩张后更新性质
            window[c]++;
            if (need.count(c) > 0 && window[c] == need[c]){
                valid++;
            }

            while (valid == need.size()){//收缩
                //该循环内部都是解，寻找最优解的长度
                if (right-left < len){
                    len = right - left;
                    start = left;
                }

                auto d = s[left];//即将移除窗口的数据
                left++;//收缩

                //收缩后更新性质
                if (need.count(d) > 0 && window[d] == need[d]){
                    valid--;
                }
                window[d]--;

            }
        }

        return len == INT_MAX ? "" : s.substr(start,len);

    }
};


int main(){
    Solution solution;
    std::cout << solution.minWindow("aa","aa") << std::endl;

}