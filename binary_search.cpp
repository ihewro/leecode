//
// Created by hewro on 2021/3/20.
//
#include "Util.hpp"
int left_bound(vector<int>nums, int target) {
    int left = 0, right = nums.size() - 1;
    // 搜索区间为 [left, right]
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target > nums[mid]) {
            //新区间为右侧 [mid+1, right]
            left = mid + 1;
        } else if (target < nums[mid]) {
            //新区间为左侧 [left, mid-1]
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 收缩右侧边界
            right = mid - 1;
        }
    }
    // 检查出界情况
    if (left >= nums.size())
        return -1;
    return left;
}

int right_bound(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 别返回，锁定右侧边界
            left = mid + 1;
        }
    }
    // 最后要检查 right 越界的情况
    if (right < 0)
        return -1;
    if (nums[right] != target){
        return right+1;
    }
    return right;
}

int binarySearch(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size() - 1; // 注意

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1; // 注意
        else if (nums[mid] > target)
            right = mid - 1; // 注意
    }
    return -1;
}


int main(){
    vector<int> input{0,2,2,2,5,6,7};
    std::cout << left_bound(input,1) << std::endl;
    std::cout << (std::lower_bound(input.begin(),input.end(),1) - input.begin()) << std::endl;
    std::cout << right_bound(input,1) << std::endl;
    std::cout << (std::upper_bound(input.begin(),input.end(),1) - input.begin()) << std::endl;
//    std::cout << binarySearch(input,1);
}
