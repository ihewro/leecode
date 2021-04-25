//
// Created by hewro on 2021/4/15.
//
#include <unistd.h>
#include "Util.hpp"
class Solution {
public:

    vector<int> tmp;
    void  merge(vector<int> &nums,int first,int first_end,int second,int second_end){
        int f_point = first;
        int s_point = second;
        int index = first;
        while(f_point <= first_end || s_point<= second_end){
            int first_p_v = (f_point <= first_end) ? nums[f_point]:INT_MAX;
            int second_p_v = (s_point <= second_end) ? nums[s_point]:INT_MAX;

            if (first_p_v < second_p_v){
                tmp[index] = first_p_v;
                f_point ++;
            }else{
                tmp[index] = second_p_v;
                s_point++;
            }
            index++;
        }
        std::copy(tmp.begin() + first,tmp.begin() + second_end + 1, nums.begin() + first);
    }

    void mergeSort(vector<int>& nums,int start,int end){
        if(start >= end){
            return ;
        }
        int mid = (start + end) / 2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,mid+1,end);

    }
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize(nums.size(),0);
        mergeSort(nums,0,nums.size()-1);
        return nums;

    }
};

int main() {
    vector<int> nums{5,2,3,1};
    Solution solution;
    solution.sortArray(nums);
    vector_util::print(nums);
}