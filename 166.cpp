//
// Created by hewro on 2021/4/23.
//
#include "Util.hpp"
class Solution {
public:
    std::unordered_map<int,int> map;//key 存储余数，value 存储该余数第一次出现，该小数在小数部分的位置
    int getDecimal(long else_part,int index,long denominator,string &ret){
        long long tmp  = else_part * 10;
        int int_p = tmp / denominator;
        int else_p = tmp % denominator;
        if(else_p ==0){//可以整除的小数
            ret += std::to_string(int_p);

            return -1;
        }
        if(map.count (else_p)){//获取到了循环小数
            return map[else_p];
        }else{
            ret += std::to_string(int_p);
            map[else_p] = index;
            return getDecimal(else_p,index+1,denominator,ret);
        }

    }
    string fractionToDecimal(int numerator, int denominator) {
        //正负号的处理
        long _numerator = numerator;
        long _denominator = denominator;

        bool isNegtive = false;
        if (_numerator >0 && _denominator >0){
        }else if(_numerator <0 && _denominator <0){
            _numerator = abs(_numerator);
            _denominator = abs(_denominator);
        }else if(_numerator <0 || _denominator < 0){
            isNegtive = true;
            _numerator = abs(_numerator);
            _denominator = abs(_denominator);
        }

        string int_part = std::to_string(_numerator/_denominator);
        long else_part = _numerator % _denominator;
        if ((else_part != 0 || int_part !="0") && isNegtive){
            int_part  = "-" + int_part;
        }
        if(else_part == 0){
            return int_part;
        }else{
            string else_ret = "";
            int flag = getDecimal(else_part,0,_denominator,else_ret);
            if (flag!=-1){//循环小数
                else_ret.insert(flag,"(");
                return int_part + "." + else_ret + ")";
            }else{
                return int_part + "." + else_ret;

            }
        }
    }
};


int main(){
    Solution solution;
    std::cout << solution.fractionToDecimal(1,6);
}