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
        if (k > nums.size()){
            k = nums.size();
        }
        std::cout << std::accumulate(nums.begin(),nums.begin() + 83,0) << std::endl;
        std::cout << nums.size() << std::endl;
        int left=0,right=0;
        //
        int window_ret = 0;
        int ret = 0;//窗口中最大的值
        while(right < nums.size()){
            auto r = nums[right];
            right++;

            //
            window_ret += r;
            //
            if(right-left > k){
                auto l = nums[left];
                left++;

                //
                window_ret -= l;
            }

            //
            if (right - left == k){
                ret = std::max(ret,window_ret);
            }
        }

        return 1.0*ret / k;

    }
};


int main() {
    Solution solution;
    vector<int> nums{-6662,5432,-8558,-8935,8731,-3083,4115,9931,-4006,-3284,-3024,1714,-2825,-2374,-2750,-959,6516,9356,8040,-2169,-9490,-3068,6299,7823,-9767,5751,-7897,6680,-1293,-3486,-6785,6337,-9158,-4183,6240,-2846,-2588,-5458,-9576,-1501,-908,-5477,7596,-8863,-4088,7922,8231,-4928,7636,-3994,-243,-1327,8425,-3468,-4218,-364,4257,5690,1035,6217,8880,4127,-6299,-1831,2854,-4498,-6983,-677,2216,-1938,3348,4099,3591,9076,942,4571,-4200,7271,-6920,-1886,662,7844,3658,-6562,-2106,-296,-3280,8909,-8352,-9413,3513,1352,-8825};
    int k = 90;
    std::cout <<solution.findMaxAverage(nums,k) <<std::endl;
}