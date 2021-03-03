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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()){
            return intervals;
        }
        auto compare = [](vector<int> a,vector<int> b){
            if (a[0] < b[0]){
                return true;
            }else{
                if (a[0] == b[0]){
                    return a[1] < b[1];
                }else{
                    return false;
                }
            }
        };
        std::sort(intervals.begin(),intervals.end(),compare);
        vector_util::print2D(intervals);

        std::cout << "=================" << std::endl;
        //��ʼ��
        vector<vector<int>> ret{{intervals[0][0],intervals[0][1]}};

        int left = intervals[0][0];
        int right = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {

            if (intervals[i][0] <= right){//���ص����ֻ��߸�����Ҫ�ϲ�
                right = std::max(right,intervals[i][1]);
                ret[ret.size()-1][1] = right;
            }else{//���ཻ
                left = intervals[i][0];
                right = intervals[i][1];
                ret.push_back({left,right});
            }
        }

        return ret;

    }
};



int main() {
    Solution solution;
    vector<vector<int>> input{{1,3},{2,6},{8,10},{15,18}};
//    vector<vector<int>> input{{1,4},{2,3}};
//    vector<vector<int>> input{{2,3},{4,5},{6,7},{8,9},{1,10}};
//    solution.merge(input);
    vector_util::print2D(solution.merge(input));
}