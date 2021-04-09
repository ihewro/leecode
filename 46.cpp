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
        vector<int>visit(nums.size(),0);
        backtrack(visit,nums,track,ret);
        return ret;
    }

    void backtrack(vector<int>&visit, vector<int>& nums,std::vector<int> &track,vector<vector<int>> &ret){
        if (track.size() == nums.size()){//base case
            vector<int>temp{};
            temp.assign(track.begin(),track.end());
            ret.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visit[i] == 0){
                track.push_back(nums[i]);
                visit[i] = 1;
                backtrack(visit,nums,track,ret);
                visit[i] = 0;
                track.pop_back();
            }
        }
    }
};


int main(){
    Solution solution;
    vector<int> nums{1,1,2};
    vector_util::print_2(solution.permute(nums));

}



