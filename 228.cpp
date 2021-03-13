/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/10
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */
#include "Util.hpp"

class Solution {
public:

    static string createSection(int begin,int end){
        if (begin == end){
            return std::to_string(begin);
        }else{
            return std::to_string(begin) + "->" + std::to_string(end);
        }
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ret{};
        if (nums.empty()){
            return ret;
        }

        int begin = nums[0];
        int end = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (((long)nums[i] - (long)nums[i-1]) == 1){
                end = nums[i];
            }else{
                //����һ������
                ret.push_back(createSection(begin,end));
                begin = nums[i];
                end = nums[i];
            }
        }
        ret.push_back(createSection(begin,end));
        return ret;
    };
};

int main(){
    Solution solution;
    vector<int> input{-2147483648,-2147483647,2147483647};
    vector_util::print(solution.summaryRanges(input));

}
