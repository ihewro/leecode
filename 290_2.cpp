/**
 * Copyright (c) 2020, SeekLoud Team.
 * Manager:
    * 2020/12/27: hewro
 * Develper: hewro
 * Description: 
 * Refer:
 */
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
using std::vector;
using std::string;

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        int left = 0;
        int right = 0;

        std::unordered_map<char,string> char2str;
        std::unordered_map<string,char> str2char;
        for (int i = 0; i < pattern.size(); ++i) {
            if (left > s.size() -1){
                return false;
            }
            //获取 i 对应位置的子串
            right = left;
            while (right < s.size() && s[right] != ' '){
                right++;
            }
            //right 停下来的位置是空格的位置
            auto str = s.substr(left,right- left);
            left = right +1;

            //判断双向映射是否是对的
            if (char2str.count(pattern[i]) && char2str[pattern[i]] != str){
                return false;
            }
            if (str2char.count(str) && str2char[str] != pattern[i]){
                return false;
            }
            char2str[pattern[i]] = str;
            str2char[str] = pattern[i];
        }
        //patten 遍历完之后，right 应该是在 s 的最后一位的后一位，否则说明 s 的子串数目多了
        return right >= s.size();
    }
};

int main(){
    Solution solution;
//    std::unordered_map<string,char> str2char;
    std::unordered_map<char,string> char2str;

    std::cout << char2str['c'] <<  "|" << std::endl;
//    std::cout << solution.wordPattern("abba","dog cat cat dog") << std::endl;
}