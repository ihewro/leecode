/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/7
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1){
            return ;
        }

        int k = -1;int l = 0;

        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] < nums[i+1]){
                k = i;
            }
        }
        if (k==-1){
            std::reverse(nums.begin() ,nums.end());
            return;
        }else{
            for (int i = k; i < nums.size(); ++i) {
                if (nums[i] > nums[k]){
                    l = i;
                }
            }
            std::swap(nums[k],nums[l]);
            std::reverse(nums.begin() + k + 1,nums.end());
        }
    }
};


int main() {
    Solution solution;
    vector<int> input{2,3,1};
    solution.nextPermutation(input);
}