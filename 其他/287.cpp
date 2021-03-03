/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/23
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        while (true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast){
                break;
            }
        }

        std::cout << "slow" << slow << std::endl;
        std::cout << "fast" << fast << std::endl;

        int extra = 0;
        while (extra != slow){
            extra = nums[extra];
            slow = nums[slow];
        }
        return extra;

    }
};

int main(){
    vector<int> nums{1,3,4,2,2};
    Solution solution;
    std::cout << solution.findDuplicate(nums) << std::endl;
}
