/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/19
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        uint32_t mask = 1;
        for (int i = 0; i < 32; ++i) {
            if ((n & mask) != 0){
                ret ++;
            }
            mask = mask << 1;
        }

        return ret;

    }
};


int main() {
    Solution solution;
    std::cout << solution.hammingWeight(0000001011) << std::endl;
}