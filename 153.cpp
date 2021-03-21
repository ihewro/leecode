//
// Created by hewro on 2021/3/20.
//
#include "Util.hpp"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        if (nums[right] >= nums[0]) {
            return nums[0];
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[0]) {
                left = mid+1;
            } else if (nums[mid] < nums[0]){
                right = mid-1;
            }else if(nums[mid] == nums[0]){
                left =  mid+1;
            }
        }
        return nums[left];
    }
};
int main(){
    Solution solution;
    vector<int> input{11,13,15,17};
    std::cout << solution.findMin(input) << std::endl;
}