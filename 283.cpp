/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/6
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"
class Solution {
public:

    void moveZeroes(vector<int>& nums) {
        std::stack<int> zeroIndexList{};
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0){
                zeroIndexList.push(i);
            }
        }

        int zeroSize = zeroIndexList.size();
        while (!zeroIndexList.empty()) {
            int index= zeroIndexList.top();
            nums.erase(nums.begin() + index);
            zeroIndexList.pop();
        }

        for (int i = 0; i < zeroSize; ++i) {
            nums.push_back(0);
        }



    }
};

int main() {
    Solution solution;
}