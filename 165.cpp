//
// Created by hewro on 2021/4/21.
//
#include "Util.hpp"
class Solution {
public:
    int get_trunk_val(int& p1,string &str){
        if(p1 >= str.size()){
            return 0;
        }

        int val = 0;
        while(str[p1] != '.' && p1 < str.size()){
            val = val *  10 - '0' + str[p1];
            p1++;
        }

        p1++;//指向. 后面的一个元素
        return val;
    }
    int compareVersion(string version1, string version2) {
        int p1 = 0;
        int p2 = 0;

        while(p1 < version1.size() || p2 < version2.size()){
            //求两个数组
            int val1 = get_trunk_val(p1,version1);
            int val2 = get_trunk_val(p2,version2);

            if (val1 != val2){
                return (val1 > val2) ? 1 : -1;
            }
        }
        return 0;
    }
};


int main(){
    Solution solution;
    solution.compareVersion("1.01","1.001");
}