/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/2
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret;

        for (int i = 0; i < nums.size(); ++i) {
            ret = ret ^ nums[i];
        }
        return ret;
    }
};


int main() {
    Solution solution;
}