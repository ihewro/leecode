/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/23
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret {};
        std::vector<int> track{};
        backtrack(nums,track,ret);
        return ret;
    }

    void backtrack(vector<int>& nums,std::vector<int> &track,vector<vector<int>> &ret){
        if (track.size() == nums.size()){//base case
            vector<int>temp{};
            temp.assign(track.begin(),track.end());
            ret.push_back(temp);
            return;
        }


        for (int i = 0; i < nums.size(); ++i) {
            if (std::find(track.begin(),track.end(),nums[i]) == track.end()){
                track.push_back(nums[i]);
                backtrack(nums,track,ret);
                track.pop_back();
            }
        }
    }
};


int main(){
    Solution solution;
    vector<int> nums{1,2,3};
    vector_util::print_2(solution.permute(nums));

}



