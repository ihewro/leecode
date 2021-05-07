//
// Created by hewro on 2021/5/7.
//
#include "Util.hpp"

class Solution {
public:
    int myAtoi(string s) {
        //先去掉左边的空格
        if(s.empty()){
            return 0;
        }
        int begin = 0;
        while(s[begin] == ' '){//这个地方循环的条件是等于不是不等于！！！！
            begin ++;
        }
        //从左往右读的，如果左边出现了不是数字和正负号或者空格，那整个数字解析为 0
        char start = s[begin];
        if(start !='-' && start !='+' && (start < '0' || start > '9')){
            return 0;
        }
        long long ans = 0;
        bool isNeg = (start == '-');
        int i = (s[begin] >='0' && s[begin]<='9') ? begin : begin+1;//注意这个地方 i 的其实位置！！！
        while(i < s.size() && s[i] >='0' && s[i]<='9'){
            ans = ans * 10 + (s[i] - '0');
            if(isNeg && ans > INT_MAX + 1L){//负数溢出
                ans = INT_MAX + 1L;
                break;
            }

            if(!isNeg && ans > INT_MAX){//正数溢出
                ans = INT_MAX ;
                break;
            }
            i++;
        }
        return isNeg ? -ans : ans;
    }
};

int main(){
    Solution solution;
    std::cout << solution.myAtoi(".1");
}