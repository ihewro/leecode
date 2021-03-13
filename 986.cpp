/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/22
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0,j=0;

        vector<vector<int>> ret;
        while (i < firstList.size() && j < secondList.size()){
            auto i_pair = firstList[i];
            auto j_pair = secondList[j];

            if (i_pair[1] >= j_pair[0] && j_pair[1] >= i_pair[0]){//有交集
                ret.push_back({std::max(i_pair[0],j_pair[0]),std::min(i_pair[1],j_pair[1])});
            }

            if (i_pair[1] < j_pair[1]){
                i++;
            }else{
                j++;
            }
        }
        return ret;
    }
};


int main() {
    Solution solution;
}