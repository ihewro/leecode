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
        int maxLength = 0;//最大边长
        int rowNum = matrix.size();
        int columnNum = matrix[0].size();

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] != '1') continue;
                maxLength = std::max(maxLength,1);
                //查看该元素的右和下是否为1
                int mayLength = std::min(rowNum - i, columnNum - j);//可能的最大正方形边长
                for (int k = 2; k <= mayLength; ++k) {
                    //判断是否存在以i,j为左上角顶点的变成为k的正方形
                    if (matrix[i + k - 1][j + k -1] == '0'){//先判断右下角，原因是每次判断正方形需要利用前面的小的正方形信息，而右下角是底边和右侧边的公共部分
                        break;//不存在边长小的正方形，就更不存在边长大的正方形了，这个顶点就可以结束遍历了
                    }
                    bool isOK = true;
                    for (int l = 0; l < k-1; ++l) {//底部
                        if (matrix[i + k - 1][j + l] == '0' || matrix[i + l][j + k - 1] == '0'){
                            isOK = false;
                            break;
                        }
                    }

                    if (isOK){//是正方形
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

