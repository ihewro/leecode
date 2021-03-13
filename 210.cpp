/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/31
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> inputDegree(numCourses,0);//顶点的入度表

        //初始化邻接矩阵和入度表
        for (auto pair: prerequisites){
            edges[pair[1]].push_back(pair[0]);
            inputDegree[pair[0]] += 1;
        }

        std::queue<int> zero_list{};//当前入度为 0 的队列
        for (int i = 0; i < inputDegree.size(); ++i) {
            if (inputDegree[i] == 0){
                zero_list.push(i);
            }
        }
        vector<int> ret{};//拓扑序列的存储

        //BFS 对入度为 0 的顶点进行搜索
        while (!zero_list.empty()){
            auto node = zero_list.front();
            zero_list.pop();
            for (auto adjacent_node:edges[node]){
                inputDegree[adjacent_node] -= 1;
                if (inputDegree[adjacent_node] == 0){
                    zero_list.push(adjacent_node);
                }
            }
            ret.push_back(node);
        }
        if (ret.size() == numCourses){
            return ret;
        }else{
            return {};
        }

    }
};