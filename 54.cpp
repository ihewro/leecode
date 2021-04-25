//
// Created by hewro on 2021/4/20.
//
#include "Util.hpp"
class Solution {
public:
    vector<int> ret;
    /*
    依次获取最外层的
    * i 起始行 ,j 起始列
    */
    void getOuter(vector<vector<int>>& matrix,int i,int j,int row,int column){
        //上边缘
        for(int c_index=j;c_index < j+column;c_index++){
            ret.push_back(matrix[i][c_index]);
        }
        //右边缘,是 i+1,边边角角的元素不要重复添加
        for(int r_index=i+1;r_index < i+row;r_index++){
            ret.push_back(matrix[r_index][j+column-1]);
        }
        if (row > 1){//超过一行才有下边缘
            //下边缘，是c_index=j+column-2
            for(int c_index=j+column-2;c_index >=j;c_index--){
                ret.push_back(matrix[i+row-1][c_index]);
            }
        }
        //左边缘，是i+row-2
        if (column>1){//超过一列才有左边缘
            for(int r_index=i+row-2;r_index >= i+1;r_index--){
                ret.push_back(matrix[r_index][j]);
            }
        }

    }

    void getSpiralOrder(vector<vector<int>>& matrix,int i,int j,int row,int column){
        if(row <=0 || column <= 0){//这个地方是 或不是与运算
            return ;
        }
        getOuter(matrix,i,j,row,column);
        getSpiralOrder(matrix,i+1,j+1,row-2,column-2);

    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        getSpiralOrder(matrix,0,0,matrix.size(),matrix[0].size());
        return ret;
    }
};

int main(){
    Solution solution;
    vector<int> tmp{7};
    vector<vector<int>>input{
            {tmp,{9},{6}}
    };
    vector_util::print(solution.spiralOrder(input));
}