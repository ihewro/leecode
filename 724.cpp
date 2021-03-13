/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/31
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0){
            return -1;
        }
        int all = 0;
        for (int i = 0; i < nums.size(); ++i) {
            all += nums[i];
        }

        //�м����������ڿ�ͷ
        if (all == nums[0]){
            return 0;
        }

        int temp = 0;
        for (int i = 1; i < nums.size(); ++i) {
            temp += nums[i-1];
            if (temp * 2 == all - nums[i]){
                return i;
            }
        }

        //�м��������ܴ���ĩβ
        if (all == nums[nums.size() -1]){
            return nums.size()-1;
        }

        return -1;
    }
};

int main(){

}