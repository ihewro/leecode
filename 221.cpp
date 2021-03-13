/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/21
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */
#include "Util.hpp"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() <=0){
            return 0;
        }
        int maxLength = 0;
        int rowNum = matrix.size();
        int columnNum = matrix[0].size();

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] != '1') continue;
                maxLength = std::max(maxLength,1);
                //最大可能构成的正方形边长
                int mayLength = std::min(rowNum - i, columnNum - j);
                for (int k = 2; k <= mayLength; ++k) {
                    //先判断右下角位置
                    if (matrix[i + k - 1][j + k -1] == '0'){
                        break;
                    }
                    bool isOK = true;
                    //同时判断行和列的位置是否是 1
                    for (int l = 0; l <= k-1; ++l) {
                        if (matrix[i + k - 1][j + l] == '0' || matrix[i + l][j + k - 1] == '0'){
                            isOK = false;
                            break;
                        }
                    }
                    if (isOK){
                        if (k > maxLength){
                            maxLength = k;
                        }
                    }else{
                        break;
                    }

                }
            }
        }

        return maxLength * maxLength;
    }



};

int main(){

    Solution solution;
    vector<vector<char>> input{'0'};
    std::cout << solution.maximalSquare(input) << std::endl;
}

