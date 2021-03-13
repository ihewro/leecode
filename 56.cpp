/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/22
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ret;
        if (intervals.empty()){
            return ret;
        }

        //排序
        std::sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){
            if (a[0] < b[0]){
                return true;
            }
            return false;
        });
        int left = intervals[0][0];
        int right = intervals[0][1];


        //遍历合并
        for(int i = 0;i < intervals.size();i++){
            if (right >= intervals[i][0]){//重叠
                right = std::max(right,intervals[i][1]);
            }else{//不重叠
                ret.emplace_back(vector<int>{left,right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }

        if (ret.empty() || ret.back()[1] != right){
            ret.emplace_back(vector<int>{left,right});
        }

        return ret;
    }
};


int main() {
    Solution solution;
    vector<vector<int>> input{{1,4},{4,6}};
//    vector<vector<int>> input{{1,4},{2,3}};
//    vector<vector<int>> input{{2,3},{4,5},{6,7},{8,9},{1,10}};
//    solution.merge(input);
    vector_util::print2D(solution.merge(input));
}