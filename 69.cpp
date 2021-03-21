//
// Created by hewro on 2021/3/20.
//
#include "Util.hpp"
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while (left <= right){
            int mid = (left + right) / 2;
            long long temp = mid * mid;
            if (temp < x){
                left = mid + 1;
            }else if (temp > x){
                right = mid - 1;
            }else if (temp == x){
                return mid;
            }
        }
        return right;
    }
};


int main(){
    Solution solution;
    std::cout << solution.mySqrt(8) << std::endl;
}