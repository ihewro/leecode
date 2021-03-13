/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/6
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"
class Solution {
public:

    void moveZeroes(vector<int>& nums) {

        int left = -1;
        int right= 0;

        while (right< nums.size()){
            if (nums[right]!=0){
                left++;
                std::swap(nums[left],nums[right]);
            }
            right++;
        }
    }
};

int main() {
    Solution solution;

    vector<int> nums{1,7,4,2,6,5};
    int k = 0;int l = 0;
    int left = 0;int right = 1;
    while (right < nums.size()){
        if (nums[left] < nums[right]){
            k = left;
            l = right;
            left++;
        }else{
            left = k;
            if (nums[right] > nums[left]){
                l = right;
            }
        }
        right++;
    }

    std::cout << "left:" << left << " right:" << right << std::endl;
    std::cout << "k:" << k << " l:" << l << std::endl;
}