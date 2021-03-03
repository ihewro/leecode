/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/7
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() <=1){
            return true;
        }
        bool isChanged = false;
        for (int i = 0; i <= nums.size() -2; ++i) {
            if (nums[i] <= nums[i+1]){
                continue;
            }else{
                if (!isChanged){
                    //把当前元素值变小，保证后面num[i+1]的元素 > num[i-1]
                    //num[i-1] <= num[i+1] 或者 num[i] <= num[i+2] 都可以修改num[i] 值来变成非递减的序列
                    bool ret = ((i+ 2 > nums.size() -1) || (nums[i+2] >= nums[i]) ) || ((i-1 < 0) || (nums[i+1] >= nums[i-1]));
                    if (ret){
                        isChanged = true;
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
}