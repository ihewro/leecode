/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/4
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.empty()){
            return 0;
        }
        if (k > nums.size()){
            k = nums.size();
        }

        int temp_ret = nums[0];
        int ret = temp_ret;

        int left = 0;
        int right;
        for (right = 1; right < nums.size(); ++right) {
            if (right - left + 1 <= k){//À©ÕÅ
                temp_ret += nums[right];
                ret = temp_ret;
            }else{//»¬¶¯
                temp_ret -= nums[left];
                left++;
                temp_ret += nums[right];

                if (temp_ret > ret){
                    ret = temp_ret;
                }
            }
        }

        return 1.0 * ret / k;
    }
};


int main() {
    Solution solution;
    vector<int> nums{6,8,6,8,0,4,1,2,9,9};
    int k = 2;
    std::cout <<solution.findMaxAverage(nums,k) <<std::endl;
}