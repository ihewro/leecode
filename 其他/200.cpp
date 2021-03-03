/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/6
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"


class Solution {
public:
    int row;
    int column;
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {

        if (grid.empty()){
            return 0;
        }
        int ret = 0;
        vector<vector<int>> edge{};
        row = grid.size();
        column = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (grid[i][j] == '1'){
                    dfs(i,j,grid);
                    ret++;
                }
            }
        }
        return ret;

    }

    void dfs(int i, int j,vector<vector<char>>& grid){
        grid[i][j] = '0';
        for (auto & direction : directions) {
            int next_i = i + direction[0];
            int next_j = j + direction[1];

            if (next_i >=0 && next_j >=0 && next_i <= row -1 && next_j <= column -1 && grid[next_i][next_j] == '1'){
                dfs(next_i,next_j,grid);
            }
        }
    }
    
    


};

int main() {
    Solution solution;
    vector<vector<char>> input{
            {'1','1','1','1','0'},
            {'1','1','0','1','0'}
    };
    std::cout << solution.numIslands(input) << std::endl;

}