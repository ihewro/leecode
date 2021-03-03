/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/20
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

class Solution {
public:
    int maximumProduct(vector<int> &nums) {

        long ret = 1;

        if (nums.size() <= 3) {
            for (auto num:nums) {
                ret = ret * num;
            }
            return ret;
        }


        auto compare = [](int a, int b) {
            if (a > b) {
                return true;
            } else {
                return false;
            }
        };
        std::sort(nums.begin(), nums.end(), compare);

        if (nums[nums.size()-1] < 0 && nums[nums.size()-2] < 0){
            return std::max(nums[0] * nums[nums.size()-1] * nums[nums.size()-2],nums[0] * nums[1] * nums[2]);
        }else{
            return nums[0] * nums[1] * nums[2];
        }

    }
};

int main() {
    Solution solution;
    vector<int> nums{-70, -1, 3, 4,5};
    std::cout << solution.maximumProduct(nums) << std::endl;
}