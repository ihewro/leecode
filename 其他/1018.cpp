/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/14
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */
#include "../Utils/Util.hpp"

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ret{};
        long value = 0;
        for (int i : A) {
            value = value * 2 + i;
            ret.push_back(value %= 5);
        }
        return ret;
    }
};

int main(){

    Solution solution;
    vector<int> input{1,1,1,0,1};
    vector_util::print(solution.prefixesDivBy5(input));

}