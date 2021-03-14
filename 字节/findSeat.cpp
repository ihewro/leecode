//
// Created by hewro on 2021/3/14.
//

/**
* 循环数组，0 表示没人座的位置，1 表示有人坐了，找一个座位距离有人的位置最远。
 * 输入：0 0 0 0 0 1 0 0
 * 输出：4
 */

#include "Util.hpp"
int findSeat(vector<int>nums){
    int left = 0;
    int right = 0;
    int max_ = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0){
            right++;
        }else{
            max_ = std::max(max_,right-left);
            left = i;
            right = i;
        }
    }
    if (nums[nums.size()-1] == 0){
        right = 0;
        while (nums[right] ==0) {
            right++;
        }
        max_ = std::max((int)nums.size()- left + right,max_);
    }

    return max_/2;
}

int  main(){

    vector<int> input{0,0,1,0,1,0};
    std::cout << findSeat(input) << std::endl;
}