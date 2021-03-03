/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/8
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */


#include <iostream>
#include <utility>
#include <vector>
#include <map>
using std::vector;
#include "../Utils/Util.hpp"

class Solution {
public:
    void rotate(vector<int>& nums,int begin,int end){
        int temp;
        int begin_,end_;

        for (int i = 0; i < (end - begin + 1)/2; ++i) {
            begin_ = begin  + i;
            end_ = end - i;

            temp = nums[begin_];
            nums[begin_] = nums[end_];
            nums[end_] = temp;
        }
    }


    void rotate(vector<int>& nums, int k) {
        int size = nums.size();//7
        k = k % size;
        rotate(nums,0,size-1);
        rotate(nums,0 ,k-1);
        rotate(nums,k ,size-1);
    }
};


int main (){
    Solution solution;
//    vector<int> input{1,2,3,4,5,6,7};
    vector<int> input{1,2};
//    vector<int> input{7,6,5,4,3,2,1};
    int k = 3;
    solution.rotate(input,k);

    vector_util::print(input);
}