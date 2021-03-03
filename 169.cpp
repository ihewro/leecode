/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/20
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int current = nums[0];//擂主的key
        std::unordered_map<int,int> eleShowMap{{nums[0],1}};
        for (int i = 1; i < nums.size(); ++i) {
            if (eleShowMap.count(nums[i]) <= 0){
                eleShowMap.insert({nums[i],1});
            }else{
                eleShowMap[nums[i]] = eleShowMap[nums[i]] + 1;
            }

            //判断是否挑战成功
            if (eleShowMap[nums[i]] > eleShowMap[current]){
//                std::cout << nums[i] << std::endl;
                current = nums[i];
            }
        }
        return current;
    }
};


int main(){
    Solution solution;
    vector<int> nums{3,2,3};
    int ia[1];
    ia[323] = 99;
    std::cout << "wokao" << std::endl;


    //    std::cout << solution.majorityElement(nums) << std::endl;

}
