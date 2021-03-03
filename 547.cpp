/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/7
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */
#include <iostream>
#include <utility>
#include <vector>
#include <map>
using std::vector;

class Solution {
public:


    int findCircleNum(vector<vector<int>>& isConnected) {
        int ret = 0;
        std::vector<bool> visit(200);
        for (int i = 0; i < isConnected.size(); ++i) {
            if (!visit[i]){
                traverse(i,isConnected,visit);
                ret++;
            }
        }

        return ret;

    }

    void traverse(int node,vector<vector<int>>& isConnected,std::vector<bool> &visit){
        visit[node] = true;
        for (int i = 0;i< isConnected.size();i++){
            if (isConnected[node][i] && !visit[i]){
                traverse(i,isConnected,visit);
            }
        }

    }
};

int main(){

    Solution solution;
    vector<vector<int>> input = {{1,0,0},{0,1,0},{0,0,1}};
    std:: cout << solution.findCircleNum(input) << std::endl;
}