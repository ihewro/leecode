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
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        // ��������������У������ͬʱ��������

        auto compare = [](vector<int> a,vector<int> b){
            if (a[0] < b[0]){
                return true;
            }else{
                if (a[0] == b[0]){
                    return a[1] > b[1];
                }else{
                    return false;
                }
            }
        };
        std::sort(intervals.begin(),intervals.end(),compare);
//        vector_util::print2D(intervals);


        int ret = 0;
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= left && intervals[i][1] <= right){//������
                ret ++;
            }else{//�н������ֺ�û�н����������
                left = intervals[i][0];
                right = intervals[i][1];
            }

        }
        return intervals.size() - ret;
    }
};



int main() {
    Solution solution;
    vector<vector<int>> input{{1,2},{1,4},{3,4}};
    std::cout << solution.removeCoveredIntervals(input) << std::endl;
}