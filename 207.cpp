/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/31
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> inputDegree(numCourses,0);

        for (auto pair: prerequisites){
            edges[pair[1]].push_back(pair[0]);
            inputDegree[pair[0]] += 1;
        }

        std::queue<int> zero_list{};
        for (int i = 0; i < inputDegree.size(); ++i) {
            if (inputDegree[i] == 0){
                zero_list.push(i);
            }
        }
        int num = 0;

        while (!zero_list.empty()){
            auto node = zero_list.front();
            zero_list.pop();

            for (auto adjacent_node:edges[node]){//node ���ڵ����нڵ�
                inputDegree[adjacent_node] -= 1;//��ȼ���1
                if (inputDegree[adjacent_node] == 0){
                    zero_list.push(adjacent_node);
                }
            }
            num++;
        }

        if (num == numCourses){
            return true;
        }else{
            return false;
        }

    }
};