/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/6
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()){
            return 0;
        }
        int row = grid.size();
        int column = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(column,0));

        dp[row-1][column-1] = grid[row-1][column-1];
        for (int i = row-1; i >= 0; i--) {
            for (int j = column -1; j >=0 ; j--) {
                if (i== row-1 && j == column-1) continue;
                int ret_1 = INT_MAX;
                int ret_2= INT_MAX;

                if (i+1 <= row -1){
                    ret_1 = dp[i+1][j];
                }

                if (j+1 <= column-1){
                    ret_2 = dp[i][j+1];
                }

                dp[i][j]= grid[i][j] + std::min(ret_1,ret_2);
            }
        }

//        vector_util::print2D(dp);


        return dp[0][0];
    }
};


int main() {
    Solution solution;
    vector<vector<int>> input{{1,2,3},{4,5,6}};
    std::cout << solution.minPathSum(input) << std::endl;
}