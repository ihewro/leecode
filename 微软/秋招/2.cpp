//
// Created by hewro on 2021/9/30.
//
#include "bits/stdc++.h"

vector<vector<int>> merge(vector<vector<int>> &intervals) {

    vector<vector<int>> ret;
    if (intervals.empty()) {
        return ret;
    }

    //排序
    std::sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
        if (a[0] < b[0]) {
            return true;
        }
        return false;
    });
    int left = intervals[0][0];
    int right = intervals[0][1];


    //遍历合并
    for (int i = 0; i < intervals.size(); i++) {
        if (right >= intervals[i][0]) {//重叠
            right = std::max(right, intervals[i][1]);
        } else {//不重叠
            ret.emplace_back(vector<int>{left, right});
            left = intervals[i][0];
            right = intervals[i][1];
        }
    }

    if (ret.empty() || ret.back()[1] != right) {
        ret.emplace_back(vector<int>{left, right});
    }

    return ret;
}


bool solution(vector<int> &A, vector<int> &P, int B, int E) {
    // write your code in C++14 (g++ 6.2.0)

    vector<vector<int>> intervals;
    for (int i = 0; i < A.size(); ++i) {
        intervals.push_back({P[i] - A[i], P[i]+A[i]});
    }
    vector<vector<int>> ret = merge(intervals);
    for(auto pair: ret){
        if (pair[0] <= B  && pair[1] >= E){
            return true;
        }
    }
    return false;
}