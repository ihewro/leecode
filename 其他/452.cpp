/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/23
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        if (intervals.empty()){
            return 0;
        }


        auto compare = [](vector<int> a, vector<int> b){
            return a[1] < b[1];
        };

        std::sort(intervals.begin(),intervals.end(),compare);

        int right = intervals[0][1];

        int ret = 1;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > right){//���ص�
                ret++;
                right = intervals[i][1];
            }
        }

        return ret;
    }
};



int main() {
    Solution solution;
}