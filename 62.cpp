/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/5
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "Util.hpp"


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp_vector(m,vector<int>(n,0));
        dp_vector[m-1][n-1] = 1;
        for (int i = m-1; i >=0 ; i--) {
            for (int j = n-1; j >=0 ; j--) {
                if (i < m-1){//可以向下走
                    dp_vector[i][j] += dp_vector[i+1][j];
                }
                if (j<n-1){//可以向右走
                    dp_vector[i][j] += dp_vector[i][j+1];
                }
                if (dp_vector[i][j] == 0){
                    dp_vector[i][j] = 1;
                }
            }

        }

        return dp_vector[0][0];
    }
};

int main() {
    Solution solution;
}